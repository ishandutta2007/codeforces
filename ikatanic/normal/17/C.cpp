#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 51123987;

char s[153];
int next[153][3];
int dp[155][55][55][55];

void add( int &x, int y ) {
  x += y;
  if( x >= mod ) x -= mod;
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  scanf( "%s", s );
  for( int i = 0; i < n; ++i ) s[i] -= 'a';

  int d = (n/3)+1;
  next[n][0] = next[n][1] = next[n][2] = n;
  for( int i = n-1; i >= 0; --i ) {
    for( int j = 0; j < 3; ++j )
      next[i][j] = next[i+1][j];
    next[i][ s[i] ] = i;
  }

  if( next[0][0] != n ) dp[ next[0][0] ][1][0][0] = 1;
  if( next[0][1] != n ) dp[ next[0][1] ][0][1][0] = 1;
  if( next[0][2] != n ) dp[ next[0][2] ][0][0][1] = 1;

  for( int i = 0; i < n; ++i )
    for( int a = 0; a <= d; ++a )
      for( int b = 0; b <= d; ++b )
	for( int c = 0; c <= d; ++c ) {
	  if( next[i][0] != n ) add( dp[ next[i][0] ][a+1][b][c], dp[i][a][b][c] );
	  if( next[i][1] != n ) add( dp[ next[i][1] ][a][b+1][c], dp[i][a][b][c] );
	  if( next[i][2] != n ) add( dp[ next[i][2] ][a][b][c+1], dp[i][a][b][c] );
	  add( dp[n][a][b][c], dp[i][a][b][c] );
	}

  int ans, f = n/3;
  if( n%3 == 0 ) ans = dp[n][f][f][f];
  if( n%3 == 1 ) ans = dp[n][f+1][f][f] + dp[n][f][f+1][f] + dp[n][f][f][f+1];
  if( n%3 == 2 ) ans = dp[n][f+1][f+1][f] + dp[n][f+1][f][f+1] + dp[n][f][f+1][f+1];
  ans %= mod;

  printf( "%d\n", ans );
  return 0;
}