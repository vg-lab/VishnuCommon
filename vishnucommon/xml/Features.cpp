/*
 * Copyright (c) 2018-2019 GMRV/URJC.
 *
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
 *
 * This file is part of VishnuCommon <https://gitlab.gmrv.es/cbbsp1/vishnucommon>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "Features.h"

namespace vishnucommon
{

  Features::Features( void )
  {

  }

  Features::Features( const std::vector< std::string >& idColumns,
    const std::vector< std::string >& positionsXYZColumn,
    const std::string& geometryColumn, const FeaturesVector& features )
      : _idColumns( idColumns )
      , _positionsXYZColumn( positionsXYZColumn )
      , _geometryColumn( geometryColumn )
      , _features( features )
  {

  }

  Features::~Features( void )
  {

  }

  std::vector< std::string > Features::getIdColumns( void ) const
  {
    return _idColumns;
  }

  void Features::setIdColumns( const std::vector< std::string >& idColumns )
  {
    _idColumns = idColumns;
  }

  std::vector< std::string > Features::getPositionsXYZColumn( void ) const
  {
    return _positionsXYZColumn;
  }

  void Features::setPositionsXYZColumn(
    const std::vector< std::string >& positionsXYZColumn )
  {
    _positionsXYZColumn = positionsXYZColumn;
  }

  std::string Features::getGeometryColumn( void ) const
  {
    return _geometryColumn;
  }

  void Features::setGeometryColumn( const std::string& geometryColumn )
  {
    _geometryColumn = geometryColumn;
  }

  FeaturesVector Features::getFeatures( void ) const
  {
    return _features;
  }

  void Features::setFeatures( const FeaturesVector& features )
  {
    _features = features;
  }

  void Features::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "features" );
    streamWriter.writeAttribute( "idColumn",
      QString::fromStdString( Strings::join( _idColumns, "," ) ) );
    if ( _positionsXYZColumn.size( ) == 1 )
    {
      streamWriter.writeAttribute( "positionXYZColumn",
        QString::fromStdString( _positionsXYZColumn.at( 0 ) ) );
    }
    else
    {
      streamWriter.writeAttribute( "positionXColumn",
        QString::fromStdString( _positionsXYZColumn.at( 0 ) ) );
      streamWriter.writeAttribute( "positionYColumn",
        QString::fromStdString( _positionsXYZColumn.at( 1 ) ) );
      streamWriter.writeAttribute( "positionZColumn",
        QString::fromStdString( _positionsXYZColumn.at( 2 ) ) );
    }
    streamWriter.writeAttribute( "geometryColumn",
      QString::fromStdString( _geometryColumn ) );
    for (const auto& feature : _features )
    {
      feature->serialize( streamWriter );
    }
    streamWriter.writeEndElement( );
  }

}