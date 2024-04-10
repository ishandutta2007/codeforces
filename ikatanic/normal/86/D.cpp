#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int BLOCK, N;

llint ans[MAXN];
int c[MAXN], a[MAXN];
int l[MAXN], r[MAXN], q[MAXN];
int bio[MAXN], cookie;

llint s;

int cmpl( const int &a, const int &b ) { return l[a] < l[b]; }
int cmpr( const int &a, const int &b ) { return r[a] < r[b]; }

void add( int x, int k ) {
  if( bio[x] != cookie ) bio[x] = cookie, c[x] = 0;
  s += k*x*( c[x] + c[x] + k );
  c[x] += k;
}

int main( void ) {
  int n, m, g;
  scanf( "%d %d", &n, &m );
  for( int i = 0; i < n; ++i )
    scanf( "%d", a+i );

  for( BLOCK = 1; BLOCK*BLOCK <= n; BLOCK *= 2 );
  BLOCK /= 2;
  
  N = (n+BLOCK-1)/BLOCK;
  
  int M = 0;
  for( int i = 0; i < m; ++i ) {
    scanf( "%d %d", l+i, r+i ); --l[i];
 
    if( l[i]+BLOCK >= r[i] ) {
      cookie++, s = 0;
      for( int j = l[i]; j < r[i]; ++j )
	add( a[j], 1 );
      ans[i] = s;
    } else
      q[M++] = i;
  }

  cookie++;

  sort( q, q + M, cmpl );
  int x = 0;
  for( int p = 0; p < n; p += BLOCK ) {
    int y = x;
    while( y < M && l[ q[y] ] <= p ) y++;
    if( x == y ) continue;
    
    int e = p;
    cookie++, s = 0;

    sort( q + x, q + y, cmpr );
    for( int w = x; w < y; ++w ) {
      int i = q[w];
      while( e < r[i] ) add( a[e], 1 ), e++;
      for( int j = l[i]; j < p; ++j ) add( a[j], 1 );
      ans[i] = s;
      for( int j = l[i]; j < p; ++j ) add( a[j], -1 );
    }
    x = y;
  }
 
  for( int i = 0; i < m; ++i )
    printf( "%I64d\n", ans[i] );
  
  return 0;
}