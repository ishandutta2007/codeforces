#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector< int > a[55], b[55];
int f[55][55];

int main( void ) {
  int n, w, m;
  scanf( "%d %d %d", &n, &w, &m );
  double c = w/double(m);
  
  int p = 0, r = m;
  for( int i = 0; i < m; ++i ) {
    int q = n;
    while( q > 0 ) {
      int z = min( r, q );
      
      a[i].push_back( p );
      b[i].push_back( z );
      f[p][i] = 1;
      q -= z, r -= z;
      if( r == 0 ) p++, r = m;
    }
  }

  for( int i = 0; i < n; ++i ) {
    int c = 0;
    for( int j = 0; j < m; ++j )
      c += f[i][j];
    if( c > 2 ) { puts( "NO" ); return 0; }
  }

  puts( "YES" );
  for( int i = 0; i < m; ++i ) {
    for( int j = 0; j < a[i].size(); ++j )
      printf( "%d %lf ", a[i][j]+1, c*b[i][j] );
    putchar( '\n' );
  }
  return 0;
}