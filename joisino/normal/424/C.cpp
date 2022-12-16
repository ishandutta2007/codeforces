#include "stdio.h"

const int MAX_N = 1000010;

int used[MAX_N] = {};

int main(){

  int n;
  scanf( "%d" , &n );

  int ans = 0;
  for( int i = 1; i <= n; i++ ){
    used[0] += n/i;
    used[i] -= n/i;
    used[0] += 1;
    used[(n%i)+1] += -1;
  }

  for( int i = 1; i <= n; i++ ){
    used[i] += used[i-1];
  }

  for( int i = 1; i <= n; i++ ){
    if( used[i] % 2 == 1 ) ans = ans ^ i;
  }

  for( int i = 0; i < n; i++ ){
    int x;
    scanf( "%d" , &x );
    ans = ans ^ x;
  }

  printf( "%d\n" , ans );

  return 0;
}