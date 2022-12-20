#include "stdio.h"
#include "algorithm"

using namespace std;

typedef long long int ll;

const int MAX_N = 100010;

int a[MAX_N];
ll c[MAX_N];

ll ans[2][2] = {};

int main(){

  /*
  printf( "100000\n" );
  for( int i = 0; i < 100000; i++ )
    printf( "100000 " );
  return 0;
  */


  int n;
  scanf( "%d" , &n );

  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &a[i] );
    c[ a[i] ]++;
  }


  for( int i = 0; i < MAX_N; i++ ){
    ans[(i+1)&1][0] = max( ans[i&1][0] , ans[i&1][1] );
    ans[(i+1)&1][1] = ans[i&1][0] + i*(ll)c[i];
  }

  printf( "%I64d\n" , max( ans[MAX_N&1][0] , ans[MAX_N&1][1] ) );

  return 0;
}