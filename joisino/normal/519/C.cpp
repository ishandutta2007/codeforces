#include "bits/stdc++.h"

int main(){

  int n , m;
  scanf( "%d %d" , &n , &m );

  int ans = 0;
  while( 1 ){
    if( n > m ){
      n -= 2;
      m--;
    } else {
      n--;
      m -= 2;
    }
    if( n < 0 || m < 0 ) break;
    ans++;
  }

  printf( "%d\n" , ans );
  
  return 0;
}