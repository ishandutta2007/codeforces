#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1<<24];
int l1[1<<24];
int l2[1<<24];

int x[25], y[25];
int d[25][25];
int e[25];
int n;

void recon( int s ) {
  int x = l1[s]-1, y = l2[s]-1;
  if( s == 0 ) return;

  if( x != -1 ) s &= ~(1<<x), printf( " %d", x+1 );
  if( y != -1 ) s &= ~(1<<y), printf( " %d", y+1 );
  
  printf( " 0" );
  recon( s );
}
 
int main( void ) {
  int xs, ys;
  scanf( "%d %d %d", &xs, &ys, &n );
  for( int i = 0; i < n; ++i )
    scanf( "%d %d", x+i, y+i );

  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j )
      d[i][j] = ( x[i]-x[j] )*( x[i]-x[j] ) + ( y[i]-y[j] )*( y[i]-y[j] );
  for( int i = 0; i < n; ++i )
    e[i] = ( x[i]-xs )*( x[i]-xs ) + ( y[i]-ys )*( y[i]-ys );

  dp[0] = 0, l1[0] = 1;
  for( int i = 0; i < (1<<n); ++i ) {
    int x = 0, c = 0;
    for( int j = n-1; j >= 0; --j )
      if( !( (i>>j)&1 ) ) x = j, c++;
    if( !l1[i] ) continue;
    
    if( !l1[ i|(1<<x) ] || dp[i]+e[x]+e[x] < dp[ i|(1<<x) ] )
      dp[ i|(1<<x) ] = dp[i]+e[x]+e[x], l1[ i|(1<<x) ]  = x+1, l2[ i|(1<<x) ] = 0;
    
    for( int k = 0; k < n; ++k )
      if( !( (i>>k)&1 ) && x != k && ( !l1[ i|(1<<k)|(1<<x) ] || dp[i]+d[x][k]+e[x]+e[k] < dp[ i|(1<<k)|(1<<x) ] ) )
	dp[ i|(1<<k)|(1<<x) ] = dp[i]+e[x]+e[k]+d[x][k], l1[ i|(1<<k)|(1<<x) ] = k+1, l2[ i|(1<<k)|(1<<x) ] = x+1;
  }

  int ans = dp[ (1<<n)-1 ];
  printf( "%d\n", ans );
  printf( "0" );
  recon( (1<<n)-1 );
  putchar( '\n' );
  return 0;
}