#include <cstdio>
#include <algorithm>

using namespace std;

int c[1005];

int main( void ) {
  int n, q;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", &q );
    c[i] = -1;
  }

  int m;
  scanf( "%d", &m );
  for( int i = 0; i < m; ++i ) {
    int a, b, w;
    scanf( "%d %d %d", &a, &b, &w ); --a, --b;
    if( c[b] == -1 || w < c[b] ) c[b] = w;
  }

  int ans = 0, cnt = 0;
  for( int i = 0; i < n; ++i )
    if( c[i] != -1 ) ans += c[i], cnt++;
  if( cnt != n-1 ) ans = -1;
  printf( "%d\n", ans );
  return 0;
}