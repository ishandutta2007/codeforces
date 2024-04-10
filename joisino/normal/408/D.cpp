#include "stdio.h"

typedef long long int ll;

const ll MAX_N = 1010;
const ll B = 1000000007;

int n;
int p[MAX_N];
ll dp[MAX_N] = {};

int main(){

  scanf( "%d" , &n );
  for( int i = 1; i <= n; i++ )
    scanf( "%d" , &p[i] );

  int ans = 0;
  for( int i = 1; i <= n; i++ ){
    dp[i] = 2;
    for( int j = p[i]; j < i; j++ )
      dp[i] = ( dp[i] + dp[j] ) % B;
    ans = ( ans + dp[i] ) % B;
  }

  printf( "%d\n" , ans );

  return 0;
}