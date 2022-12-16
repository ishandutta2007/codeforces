#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

int n , m , k;
int a[100010];
int p[100010];

int main(){
  scanf( "%d %d %d" , &n , &m , &k );

  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &a[i] );
    p[a[i]] = i;
  }

  ll ans = 0;
  for( int i = 0; i < m; i++ ){
    int x;
    scanf( "%d" , &x );
    int px = p[x];
    ans += (px/k)+1;
    if( px > 0 ){
      p[x]--;
      p[a[px-1]]++;
      swap( a[px] , a[px-1] );
    }
  }

  printf( "%I64d\n" , ans );
 
  return 0;
}