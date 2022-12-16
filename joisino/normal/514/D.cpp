#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }


const int RMQ_MAX_N = 100000*4;
const ll RMQ_INIT = -1e18;
const ll RMQ_NONE = -1e18;
struct RMQ{
  ll node[RMQ_MAX_N];
  int idnode[RMQ_MAX_N];
  int size;
  bool com( ll a , ll b ){
    return a > b;
  }
  ll cho( ll a , ll b ){
    return com( a , b ) ? a : b;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    for( int i = size*2-2; i >= 0; i-- ){
      node[i] = RMQ_INIT;
      if( i >= size-1 ) idnode[i] = i-size+1;
      else idnode[i] = idnode[i*2+1];
    }
    node[size*2] = RMQ_NONE;
  }
  void update( int k , ll x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      if( com( node[k*2+1] , node[k*2+2] ) ){
	node[k] = node[k*2+1];
	idnode[k] = idnode[k*2+1];
      } else {
	node[k] = node[k*2+2];
	idnode[k] = idnode[k*2+2];
      }
    }
  }
  ll query( int a , int b , int k = 0 , int l = 0 , int r = 0 , bool f = true){
    if( f ) r = size;
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return RMQ_NONE;
    } else {
      ll chl = query( a , b , k*2+1 , l , (l+r)/2 , false );
      ll chr = query( a , b , k*2+2 , (l+r)/2 , r , false );
      return cho( chl , chr );
    }
  }
  int idquery( int a , int b , int k = 0 , int l = 0 , int r = 0 , bool f = true ){
    if( f ) r = size;
    if( a <= l && r <= b ){
      return idnode[k];
    } else if( b <= l || r <= a ){
      return size+1;
    } else {
      int chl = idquery( a , b , k*2+1 , l , (l+r)/2 , false );
      int chr = idquery( a , b , k*2+2 , (l+r)/2 , r , false );
      return com( node[chl+size-1] , node[chr+size-1] ) ? chl : chr;
    }
  }
};


RMQ rmq[5];

int ans[5];

int main(){

  int n , m , k;
  scanf( "%d %d %d" , &n , &m , &k );

  for( int i = 0; i < m; i++ )
    rmq[i].init( n );
  
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < m; j++ ){
      int a;
      scanf( "%d" , &a );
      rmq[j].update( i , a );
    }
  }

  int lb = 0 , ub = n+1;
  while( ub - lb > 1 ){
    int md = (lb+ub)/2;

    bool ok = false;
    for( int i = 0; i+md <= n; i++ ){
      ll sum = 0;
      for( int j = 0; j < m; j++ )
	sum += rmq[j].query( i , i+md );

      if( sum <= ll(k) ){
	ok = true;
	for( int j = 0; j < m; j++ )
	  ans[j] = rmq[j].query( i , i+md );
      }
    }

    if( ok ) lb = md;
    else ub = md;
  }

  for( int i = 0; i < m; i++ )
    printf( "%d%c" , ans[i] , i==m-1?'\n':' ' );
 
  return 0;
}