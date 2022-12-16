#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> II;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

//const int dx[] = { 0 , 0 , 1 , -1 };
//const int dy[] = { -1 , 1 , 0 , 0 };
//const int dx[] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
//const int dy[] = { 0 , -1 , -1 , -1 , 0 , 1 , 1 , 1 };
const int dx[6] = { 0 , 1 , 1 , 0 , -1 , -1 };
const int dy[2][6] = { { 1 , 0 , -1 , -1 , -1 , 0 } , { 1 , 1 , 0 , -1 , 0 , 1 } };
const ll LLINF = 1e16;
const int INF = 1e9;
const double EPS = 1e-2;

int n , k;
ll s;
ll a[64];

map<ll,ll> dp[2][64];

ll fact[64];
ll nv;
vec addi , addv , addk;

void dfs( int p , int t , ll sum , int ty , int end ){
  if( p == end ){
    dp[ty][t][sum]++;
  } else {
    if( a[p] <= 18 ) dfs( p+1 , t+1 , sum+fact[a[p]] , ty , end );
    dfs( p+1 , t , sum+a[p] , ty , end );
    dfs( p+1 , t , sum , ty , end );
  }
}

int main(){

  scanf( "%d %d" , &n , &k);
  scanf( "%I64d" , &s );

  for( int i = 0; i < n; i++ )
    scanf( "%I64d" , &a[i] );

  fact[0] = 1;
  for( int i = 1; i <= 18; i++ )
    fact[i] = fact[i-1]*ll(i);

  dfs( 0 , 0 , 0 , 0 , n/2 );
  dfs( n/2 , 0 , 0 , 1 , n );
  
  ll ans = 0;
  for( int i = 0; i <= k; i++ ){
    for( auto ite = dp[0][i].begin(); ite != dp[0][i].end(); ite++ ){
      for( int j = 0; i+j <= k; j++ ){
	auto ite2 = dp[1][j].find( s-(ite->first) );
	if( ite2 != dp[1][j].end() )
	  ans += (ite->second)*(ite2->second);
      }
    }
  }

  printf( "%I64d\n" , ans );
    
  return 0;
}