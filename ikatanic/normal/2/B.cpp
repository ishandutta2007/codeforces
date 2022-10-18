#include <cstdio>
#include <algorithm>

using namespace std;

const int MaxN = 1002;
const int INF = 100000000;

char l[2][ MaxN ][ MaxN ];
char f[2][ MaxN ][ MaxN ];
int a[ MaxN ][ MaxN ];
int dp[2][ MaxN ][ MaxN ];
int n;

int solve( int p ) {
  if( a[0][0] == 0 || a[n-1][n-1] == 0 ) return INF;
  dp[p][0][0] = f[p][0][0];
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j ) {
      if( (i+j) == 0 ) continue;
      int &r = dp[p][i][j], v = f[p][i][j]; r = INF;
      if( a[i][j] == 0 ) continue;

      if( i > 0 && dp[p][i-1][j]+v < r ) r = dp[p][i-1][j]+v, l[p][i][j] = 0;
      if( j > 0 && dp[p][i][j-1]+v < r ) r = dp[p][i][j-1]+v, l[p][i][j] = 1;
    }
  return dp[p][n-1][n-1];
}

void recon( int p, int x, int y ) {
  if( x == 0 && y == 0 ) return;
  if( l[p][x][y] ) {
    recon( p, x, y-1 );
    putchar( 'R' );
  } else {
    recon( p, x-1, y );
    putchar( 'D' );
  }
}

int main( void ) {
  int nx, ny; nx = -1;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j ) {
      scanf( "%d", a[i]+j );
      int x = a[i][j];
      if( x == 0 ) nx = i, ny = j;
      while( x > 0 && !( x%2 ) ) f[0][i][j]++, x /= 2;
      while( x > 0 && !( x%5 ) ) f[1][i][j]++, x /= 5;
    }

  int p0 = solve( 0 ), p1 = solve( 1 );
  if( p0 > 0 && p1 > 0 && nx != -1 ) {
    printf( "%d\n", 1 );
    for( int i = 0; i < nx; ++i ) putchar( 'D' );
    for( int i = 0; i < ny; ++i ) putchar( 'R' );
    for( int i = nx+1; i < n; ++i ) putchar( 'D' );
    for( int i = ny+1; i < n; ++i ) putchar( 'R' );
    putchar( '\n' );
    return 0;
  }

  if( p0 < p1 ) {
    printf( "%d\n", p0 );
    recon( 0, n-1, n-1 );
  } else {
    printf( "%d\n", p1 );
    recon( 1, n-1, n-1 );
  }
  putchar( '\n' );
  return 0;
}