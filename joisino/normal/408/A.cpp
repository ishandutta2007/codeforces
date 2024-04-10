#include "stdio.h"
#include "algorithm"

using namespace std;

const int MAX_N = 110;
const int MAX_K = 110;
const int INF = 100000000;

int n;
int k[MAX_N];
int m[MAX_N][MAX_K];

int main(){

  scanf( "%d" , &n );
  for( int i = 0; i < n; i++ )
    scanf( "%d" , &k[i] );
  
  int ans = INF;
  for( int i = 0; i < n; i++ ){
    int res = 0;
    for( int j = 0; j < k[i]; j++ ){
      int a;
      scanf( "%d" , &a );
      res += a*5 + 15;
    }
    ans = min( ans , res );
  }

  printf( "%d\n" , ans );

  return 0;
}