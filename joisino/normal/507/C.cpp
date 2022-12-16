#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }


int h;
ll n;

ll e[64];

void dfs( ll l , ll r , int d , ll s , int p ){

  if( r - l == ll(1) ){
    cout << s << endl;
    return;
  }

  if( l <= n && n < (l+r)/2 ){
    if( p == 1 ) s += e[h-d]-1;
    dfs( l , (l+r)/2 , d+1 , s+1 , 1 );
  } else {
    if( p == 0 ) s += e[h-d]-1;
    dfs( (l+r)/2 , r , d+1 , s+1 , 0 );
  }
}

int main(){

  cin >> h >> n; n--;

  e[0] = 1;
  FOR( i , 1 , h+1 )
    e[i] = e[i-1] * 2;
  
  dfs( 0 , e[h] , 0 , 0 , 0 );
  
  return 0;
}