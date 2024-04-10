#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char s[105];

int ok( int a, int b ) {
  for( int i = a; i < b; ++i )
    if( !isalpha( s[i] ) && !isdigit( s[i] ) && s[i] != '_' ) return 0;
  if( b-a > 16 || a == b ) return 0;
  return 1;
}

int check() {
  int p = -1, n = strlen( s );
  for( int i = 0; i < n; ++i )
    if( s[i] == '@' ) {
      if( p != -1 ) return 0;
      p = i;
    }
  if( p == -1 ) return 0;

  if( !ok( 0, p ) ) return 0;
  
  int l = p+1, f = p;
  while( f < n && s[f] != '/' ) f++;  

  if( f < n && !ok( f+1, n ) ) return 0;
  if( f-l > 32 || f-l == 0 ) return 0;

  s[f] = '.';
  for( int i = p+1; i <= f; ++i )
    if( s[i] == '.' ) {
      if( !ok( l, i ) ) return 0;
      l = i+1;
    }
  return 1;
}

int main( void ) {
  scanf( "%s", s );
  if( check() ) puts( "YES" ); else
    puts( "NO" );
  return 0;
}