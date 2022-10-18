#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long llint;

llint dp[2002][4010];
int c[2002], t[2002];

int main( void ) {
  int n, o = 2002;
  scanf( "%d", &n );

  memset( dp, 127, sizeof( dp ) );
  for( int i = 0; i < n; ++i )
    scanf( "%d %d", t+i, c+i );

  dp[0][o] = 0;
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < o+o; ++j )
      if( dp[i][j] < 1e13 ) {
	dp[i+1][j-1] = min( dp[i+1][j-1], dp[i][j] );
	dp[i+1][ min(o+o-1,j+t[i] ) ] = min( dp[i+1][ min(o+o-1,j+t[i] ) ], dp[i][j] + c[i] );
      }

  llint ans = 1e15;
  for( int i = o; i < o+o; ++i )
    ans = min( ans, dp[n][i] );
  cout << ans << endl;
  return 0;
}