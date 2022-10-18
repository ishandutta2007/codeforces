#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxD = 40;
const int BASE = 1000;

struct bignum {
  int a[ MaxD ], n;
  bignum() { n = 0; };
  bignum( int x ) {
    n = 0;
    while( x > 0 ) a[n++] = x%BASE, x /= BASE;
  };

  friend bool operator > ( const bignum &a, const bignum &b ) {
    if( a.n != b.n ) return a.n > b.n;
    for( int i = a.n-1; i >= 0; --i )
      if( a.a[i] != b.a[i] ) return a.a[i] > b.a[i];
    return 0;
  }

  friend bignum operator * ( const bignum &a, const bignum &b ) {
    bignum r;
    r.n = a.n + b.n - 1;
    for( int i = 0; i < r.n; ++i ) r.a[i] = 0;
    for( int i = 0; i < a.n; ++i )
      for( int j = 0; j < b.n; ++j )
	r.a[i+j] += a.a[i]*b.a[j];

    int tmp = 0;
    for( int i = 0; i < r.n; ++i )
      r.a[i] += tmp, tmp = r.a[i]/BASE, r.a[i] %= BASE;
    while( tmp ) r.a[r.n++] = tmp%BASE, tmp /= BASE;
    return r;
  }
  
  void print() {
    if( n == 0 ) return;
    printf( "%d", a[n-1] );
    for( int i = n-2; i >= 0; --i )
      printf( "%03d", a[i] );
    putchar( '\n' );
  }
};

vector< int > E[707];
int sz[707];
bignum dp[707][707];
bignum tmp[707];
bignum w;

void solve( int x, int dad ) {
  sz[x] = 1;
  for( int i = 0; i < E[x].size(); ++i ) {
    int y = E[x][i];
    if( y == dad ) continue;
    solve( y, x );
    sz[x] += sz[y];
  }

  dp[x][0] = dp[x][1] = 1;

  int s = 1;
  for( int i = 0; i < E[x].size(); ++i ) {
    int y = E[x][i];
    if( y == dad ) continue;
   
    for( int j = 0; j <= s+sz[y]; ++j ) tmp[j] = 0;
    for( int j = 0; j <= s; ++j )
      for( int k = 0; k <= sz[y]; ++k ) {
	w = dp[x][j] * dp[y][k];
	if( w > tmp[j+k] ) tmp[j+k] = w;
      }
    for( int j = 0; j <= s+sz[y]; ++j ) dp[x][j] = tmp[j];
    s += sz[y];
  }

  for( int j = 0; j <= s; ++j ) {
    w = dp[x][j]*j;
    if( w > dp[x][0] ) dp[x][0] = w;
  }
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n-1; ++i ) {
    int a, b;
    scanf( "%d %d", &a, &b ); --a, --b;
    E[a].push_back( b );
    E[b].push_back( a );
  }
  
  solve( 0, -1 );
  dp[0][0].print();
  return 0;
}