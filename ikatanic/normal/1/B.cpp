#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

char s[100];

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( ; t; --t ) {
    scanf( "%s", s );
    int n = strlen( s );

    int tip = 0;
    if( s[0] == 'R' && isdigit( s[1] ) )
      for( int i = 2; i < n; ++i )
	if( s[i] == 'C' ) { tip = i; break; }

    if( tip == 0 ) {
      int l = 0, x = 1, y = 0, pw = 1;
      while( !isdigit( s[l] ) ) l++;

      for( int i = 1; i < l; ++i )
	x += ( pw *= 26 );
      for( int i = 0; i < l; ++i )
	x += ( s[i]-'A' )*pw, pw /= 26;
      while( isdigit( s[l] ) ) y = y*10 + s[l++]-'0';
      
      printf( "R%dC%d\n", y, x );
    } else {
      int x = 0, y = 0;
      for( int i = 1; i < tip; ++i ) y = y*10 + s[i]-'0';
      for( int i = tip+1; i < n; ++i ) x = x*10 + s[i]-'0';
      
      int l = 1, pw = 26;
      while( x > pw ) x -= pw, pw *= 26, l++;
      
      --x;
      for( int i = 0; i < l; ++i ) s[i] = (x%26) + 'A', x /= 26;
      for( int i = l-1; i >= 0; --i ) putchar( s[i] );
      printf( "%d\n", y );
    }
  }
  return 0;
}