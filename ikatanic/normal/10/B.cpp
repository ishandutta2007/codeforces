#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int s[101][101];
int a[101][101];

int main( void ) {
  int n, k, m;
  scanf( "%d %d", &n, &k );
  int c = ( k+1 )/2;

  for( int i = 1; i <= k; ++i )
    for( int j = 1; j <= k; ++j )
      s[i][j] = s[i][j-1] + abs( c-i ) + abs( c-j );

  for( int w = 0; w < n; ++w ) {
    scanf( "%d", &m );
    
    int X, Y, C = INF;
    for( int i = k; i >= 1; --i ) {
      int cur = 0;
      for( int j = k; j >= 1; --j ) {
	if( a[i][j] == 1 ) cur = 0; else cur++;
	if( cur >= m ) {
	  int c = s[i][j+m-1] - s[i][j-1];
	  if( c <= C ) C = c, X = i, Y = j;
	}
      }
    }

    if( C == INF ) puts( "-1" ); else {
      printf( "%d %d %d\n", X, Y, Y+m-1 );
      for( int i = 0; i < m; ++i )
	a[X][Y+i] = 1;
    }
  }

  return 0;
}