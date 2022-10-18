#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char c[100115];
char a[105], b[105];
int la, lb, n;

int can() {
  int f1 = n, f2 = 0;
  for( int i = 0; i < n; ++i ) {
    int ok = ( i+la <= n );
    for( int j = 0; j < la; ++j )
      if( a[j] != c[i+j] ) { ok = 0; break; }

    if( ok && i < f1 ) f1 = i;
    ok = ( i+lb <= n );
    for( int j = 0; j < lb; ++j )
      if( b[j] != c[i+j] ) { ok = 0; break; }
    if( ok && i > f2 ) f2 = i;
  }
  return f1+la <= f2;
}

int main( void ) {
  scanf( "%s", c );
  scanf( "%s", a );
  scanf( "%s", b );

  la = strlen( a );
  lb = strlen( b );
  n = strlen( c );

  int o1 = can();
  reverse( c, c+n );
  int o2 = can();

  if( o1 && o2 ) puts( "both" ); else
    if( o1 ) puts( "forward" ); else
      if( o2 ) puts( "backward" ); else
	puts( "fantasy" );
  return 0;
}