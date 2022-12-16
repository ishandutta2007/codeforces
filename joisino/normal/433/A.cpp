#include "stdio.h"

int main(){

  int n;
  scanf( "%d" , &n );

  int ca = 0;
  int cb = 0;
  for( int i = 0; i < n; i++ ){
    int a;
    scanf( "%d" , &a );
    if( a == 100 ) ca++;
    else if( a == 200 ) cb++;
  }

  if( ( (ca > 0 || cb % 2 == 0 ) && ca % 2 == 0 ) ) printf( "YES\n" );
  else printf( "NO\n" );

  return 0;
}