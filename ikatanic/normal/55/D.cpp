#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long llint;

const int mod = 2*2*2*3*3*5*7;

int b[3000];
int a[50], f[50][10];

llint pw[20];
llint dp[20][50][mod];
bool bio[20][50][mod];

llint A, B;

int gcd( int a, int b ) { return !b ? a : gcd( b, a%b ); }

llint solve( llint p, int n, int x, int m ) {
  llint mini = p*pw[n], maxi = p*pw[n] + pw[n]-1;
  bool memo = ( mini >= A && maxi <= B );
  if( mini > B || maxi < A ) return 0;
  
  if( memo && bio[n][x][m] ) return dp[n][x][m];
  if( n == 0 ) return dp[n][x][m] = ( m%a[x] == 0 );
  
  llint ans = 0;
  for( int i = 0; i < 10; ++i )
    ans += solve( p*10 + i, n-1, b[ f[x][i] ], (m*10+i)%mod );
  if( memo ) bio[n][x][m] = 1, dp[n][x][m] = ans;
  return ans;
}

int main( void ) {
  int c = 1;
  for( int s = 0; s < (1<<9); ++s ) {
    int x = 1;
    for( int i = 0; i < 9; ++i )
      if( s&(1<<i) ) x *= (i+1)/gcd(x,i+1);
    if( b[x] ) continue;
    
    a[c] = x, b[x] = c;
    f[c][0] = f[c][1] = x;
    for( int i = 2; i < 10; ++i )
      f[c][i] = x*i/gcd(x,i);
    c++;
  }
  
  pw[0] = 1;
  for( int i = 1; i < 20; ++i )
    pw[i] = pw[i-1]*10;

  int t;
  scanf( "%d", &t );
  for( ; t; --t ) {
    long long aa, bb, ans;
    scanf( "%I64d %I64d", &aa, &bb ); A = aa, B = bb;
    ans = solve( 0, 19, b[1], 0 );
    printf( "%I64d\n", ans );
  }
  return 0;
}