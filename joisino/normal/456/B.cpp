#include "stdio.h"
#include "string.h"

const int MAX_N = 100010;

char str[MAX_N];

int main(){

  /*
  for( int i = 0; i < 20; i++ ){
    int ans = 1;
    int p = 1;
    for( int j = 2; j <= 4; j++ ){
      for( int k = 0; k < i; k++ ){
	p *= 2;
	p %= 5;
      }
      ans += p;
    }
    printf( "%d\n" , ans%5 );
  }
  return 0;
  */

  scanf( "%s" , str );

  int len = strlen( str );

  int p = (str[len-1]-'0');
  if( len >= 2 ) p += (str[len-2]-'0')*10;
  //printf( "%d\n" , p );
  p %= 4;
  //printf( "%d\n" , p );

  switch( p ){
  case 0:
    printf( "4\n" );
    break;
  case 1:
    printf( "0\n" );
    break;
  case 2:
    printf( "0\n" );
    break;
  case 3:
    printf( "0\n" );
    break;
  }

  return 0;
}