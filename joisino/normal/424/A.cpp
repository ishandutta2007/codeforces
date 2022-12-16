#include "stdio.h"

int main(){

  char ham[300];
  int n;
  scanf( "%d\n" , &n );

  scanf( "%s" , ham );

  int cntup = 0;
  for( int i = 0; i < n; i++ ){
    if( ham[i] == 'X' ) cntup++;
  }

  int ans = 0;
  if( cntup < n/2 ){
    for( int i = 0; i < n; i++ ){
      if( ham[i] == 'x' ){
	cntup++;
	ans++;
	ham[i] = 'X';
      }
      if( cntup == n/2 ) break;
    }
  } else if( cntup > n/2 ){
    for( int i = 0; i < n; i++ ){
      if( ham[i] == 'X' ){
	cntup--;
	ans++;
	ham[i] = 'x';
      }
      if( cntup == n/2 ) break;
    }
  }

  printf( "%d\n%s\n" , ans , ham );

  return 0;
}