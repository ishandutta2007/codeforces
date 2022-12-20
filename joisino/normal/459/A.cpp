#include "stdio.h"
#include "algorithm"
#include "math.h"

using namespace std;

int main(){

  int x[4] , y[4];
  scanf( "%d %d %d %d" , &x[0] , &y[0] , &x[1] , &y[1] );

  if( x[0] == x[1] ){
    int d = abs( y[0]-y[1] );
    x[2] = x[0]+d;
    y[2] = y[0];
    x[3] = x[1]+d;
    y[3] = y[1];
  } else if( y[0] == y[1] ){
    int d = abs( x[0]-x[1] );
    x[2] = x[0];
    y[2] = y[0]+d;
    x[3] = x[1];
    y[3] = y[1]+d;
  } else {
    if( abs(x[0]-x[1]) == abs(y[0]-y[1]) ){
      x[2] = x[0];
      y[2] = y[1];
      x[3] = x[1];
      y[3] = y[0];
    } else {
      printf( "-1\n" );
      return 0;
    }
  }

  printf( "%d %d %d %d\n" , x[2] , y[2] , x[3] , y[3] );

  return 0;
}