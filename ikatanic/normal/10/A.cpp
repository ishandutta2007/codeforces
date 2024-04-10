#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main( void ) {
  int n, p1, p2, p3, t1, t2;
  scanf( "%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2 );
  
  int last, l, r, ans = 0;
  for( int i = 0; i < n; ++i ) {
    scanf( "%d %d", &l, &r );
    ans += ( r-l )*p1;

    int d = l-last;
    last = r;

    if( i > 0 ) {
      ans += min( d, t1 )*p1;
      d -= min( d, t1 );
      
      ans += min( d, t2 )*p2;
      d -= min( d, t2 );
      
      ans += d*p3;
    }
  }

  printf( "%d\n", ans );
  return 0;
}