#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string a[3];
int bio[ 100000 ];
int w[ 100000 ];
int mv[ 100000 ];

int ima( char c, int i, int j, int x, int y ) {
  for( int k = 0; k < 3; ++k )
    if( a[ i+k*x ][ j+k*y ] != c ) return 0;
  return 1;
}

void dfs() {
  int c1 = 0, c2 = 0;
  int ind = 0;
  for( int i = 0; i < 3; ++i )
    for( int j = 0; j < 3; ++j ) {
      ind *= 3;
      if( a[i][j] == 'X' ) ind += 1, c1++;
      if( a[i][j] == 'O' ) ind += 2, c2++;
    }

  if( bio[ind] ) return;

  bio[ind] = 1;
  int w1 = 0, w2 = 0;
  for( int i = 0; i < 3; ++i ) {
    if( ima( 'X', i, 0, 0, 1 ) ) w1 = 1;
    if( ima( 'X', 0, i, 1, 0 ) ) w1 = 1;
    if( ima( 'O', i, 0, 0, 1 ) ) w2 = 1;
    if( ima( 'O', 0, i, 1, 0 ) ) w2 = 1;
  }

  if( ima( 'X', 0, 0, 1, 1 ) ) w1 = 1;
  if( ima( 'X', 0, 2, 1, -1 ) ) w1 = 1;
  if( ima( 'O', 0, 0, 1, 1 ) ) w2 = 1;
  if( ima( 'O', 0, 2, 1, -1 ) ) w2 = 1;

  if( w1 ) w[ind] = 1;
  if( w2 ) w[ind] = 2;
  
  if( w1 || w2 || c1+c2 == 9 ) return;
  
  char c = ( c1 > c2 ) ? 'O' : 'X';
  mv[ind] = c;
  for( int i = 0; i < 3; ++i )
    for( int j = 0; j < 3; ++j )
      if( a[i][j] == '.' ) {
	a[i][j] = c;
	dfs();
	a[i][j] = '.';
      }
}
  
int main( void ) {
  a[0] = a[1] = a[2] = "...";
  dfs();

  int x = 0;
  for( int i = 0; i < 3; ++i ) {
    char s[5];
    scanf( "%s", s );
    for( int j = 0; j < 3; ++j ) {
      x *= 3;
      if( s[j] == 'X' ) x += 1;
      if( s[j] == '0' ) x += 2;
    }
  }

  if( mv[x] ) {
    if( mv[x] == 'X' ) puts( "first" ); else
      puts( "second" );
    return 0;
  }

  if( !bio[x] ) puts( "illegal" ); else
    if( w[x] == 1 ) puts( "the first player won" ); else
      if( w[x] == 2 ) puts( "the second player won" ); else
	puts( "draw" );

  return 0;
}