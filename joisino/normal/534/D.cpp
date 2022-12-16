#include "bits/stdc++.h"

#define pb push_back

using namespace std;

vector<int> vs[200010];

int ans[200010];
int cnt;

int p[200010];
int a[200010];

int main(){

  int n;
  scanf( "%d" , &n );

  for( int i = 1; i <= n; i++ ){
    scanf( "%d" , &a[i] );
    vs[a[i]].pb( i );
  }

  for( int i = 0; i < n; i++ ){
    while( cnt >= 0 && vs[cnt].size() == 0 ) cnt -= 3;
    if( cnt < 0 ){
      printf( "Impossible\n" );
      return 0;
    }
    ans[i] = vs[cnt].back();
    vs[cnt].pop_back();

    cnt++;
  }

  printf( "Possible\n" );
  for( int i = 0; i < n; i++ )
    printf( "%d " , ans[i] );

  printf( "\n" );
  
  return 0;
}