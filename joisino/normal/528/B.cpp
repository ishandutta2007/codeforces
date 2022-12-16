#include "stdio.h"
#include "vector"
#include "algorithm"
#include "utility"

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

const ll INF = 1e18;
const int RMQ_MAX_N = 200000*4;
const ll RMQ_INIT = INF;
const ll RMQ_NONE = INF;
bool com( ll a , ll b ){
  return a < b;
}
struct RMQ{
  ll node[RMQ_MAX_N];
  int idnode[RMQ_MAX_N];
  int size;
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
    if( a <= l && r <= l ){
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

RMQ q;

vector<int> G[200010];
int ans;

void dfs( int x , int d ){
  chmax( ans , d );

  for( int i = 0; i < G[x].size(); i++ )
    dfs( G[x][i] , d+1 );
}

int main(){

  int n;
  scanf( "%d" , &n );

  vector<P> vp;
  for( int i = 0; i < n; i++ ){
    int x , w;
    scanf( "%d %d" , &x , &w );
    vp.push_back( P( x-w , x+w ) );
  }
  vp.push_back( P( INF-10 , INF-10 ) );

  sort( vp.begin() , vp.end() );
  
  n = vp.size();
  
  q.init( n );

  for( int i = 0; i < n; i++ )
    q.update( i , vp[i].second );

  for( int i = 0; i < n-1; i++ ){
    vector<P>::iterator ite = lower_bound( vp.begin() , vp.end() , P( vp[i].second , -INF ) );
    int st = ite - vp.begin();
    int id = q.idquery( st , q.size );
    
    G[id].push_back( i );
  }

  ans = 0;
  dfs( n-1 , 0 );

  printf( "%d\n" , ans );
  
  return 0;
}