#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef pair< int, int > par;
#define x first
#define y second

typedef long long llint;

const llint inf = 1e16;

int a[5005];
int b[5005];
par v[5005];
llint dp[2][5005];

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", a+i );
    v[i] = par( a[i], i );
  }

  sort( v, v+n );
  for( int j = 0; j < n; ++j )
    dp[0][j] = dp[1][j] = inf;

  for( int i = 0; i < n; ++i )
    dp[0][i] = abs( a[0] - v[i].x );

  int now = 1, next = 0;
  for( int i = 1; i < n; ++i ) {
    now ^= 1, next ^= 1;

    llint mini = dp[now][0];
    for( int j = 0; j < n; ++j ) {
      mini = min( mini, dp[now][j] );
      dp[next][j] = min( dp[next][j], mini + llint( abs( a[i]-v[j].x ) ) );
      dp[now][j] = inf;
    }
  }

  llint ans = inf;
  for( int j = 0; j < n; ++j )
    ans = min( ans, dp[next][j] );
  cout << ans << endl;
  return 0;
}