#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct LazyRollingHashSegtree{
  vl node;
  vl lazy;
  vl e, fact;
  ll mul , mod;
  int size;

  LazyRollingHashSegtree(){}
  LazyRollingHashSegtree( ll mul , ll mod ) : mul(mul) , mod(mod){}

  inline void push( int k , int l , int r ){
    if( k < size-1 ){
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
      node[k*2+1] = node[k*2+2] = ( fact[(r-l)/2] * lazy[k] ) % mod;
    }
    lazy[k] = -1;
  }
  
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    
    lazy = vl( size*2-1 , -1 );
    node = vl( size*2-1 , 0 );
    
    e = vl( size , 1 );
    fact = vl( size , 0 );
    FOR( i , 1 , size ){
      e[i] = ( e[i-1] * mul ) % mod;
      fact[i] = ( fact[i-1] * mul + 1 ) % mod;
    }
  }

  void initset( int k , int l , int r , const vl &a ){
    if( r - l == 1 ){
      node[k] = a[l] % mod;
    } else {
      initset( k*2+1 , l , (l+r)/2 , a );
      initset( k*2+2 , (l+r)/2 , r , a );
      node[k] = ( node[k*2+1] + node[k*2+2] * e[(r-l)/2] ) % mod;
    }
  }

  void init( const vl &a ){
    init( a.size() );
    initset( 0 , 0 , size , a );
  }
  
  void update( int a , int b , ll x , int k , int l , int r ){
    if( a <= l && r <= b ){
      lazy[k] = x;
      node[k] = ( fact[r-l] * x ) % mod;
    } else if( b <= l || r <= a ){

    } else {
      if( lazy[k] != -1 ) push( k , l , r );
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = ( node[k*2+1] + node[k*2+2] * e[(l+r)/2-l] ) % mod;
    }
  }
  void update( int a , int b , ll x ){
    update( a , b , x , 0 , 0 , size );
  }
  ll query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      if( lazy[k] != -1 ) push( k , l , r );
      return node[k];
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      chmax( a , l );
      chmin( b , r );
      if( lazy[k] != -1 ) return ( lazy[k] * fact[b-a] ) % mod;
      ll chl = query( a , b , k*2+1 , l , (l+r)/2 );
      ll chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return ( chl + chr * e[max(0,(l+r)/2-a)] ) % mod;
    }
  }
  ll query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};

const int MAX_LRHSEGTREE = 3;
const ll MUL[3] = { 72727 , 51419 , 79393  };
const ll MOD[3] = { 1000000007 , 765876961 , 727272727 };
struct LRHSegtree{
  LazyRollingHashSegtree rh[3];
  LRHSegtree(){
    REP( i , MAX_LRHSEGTREE )
      rh[i] = LazyRollingHashSegtree( MUL[i] , MOD[i] );
  }
  void init( int n ){
    REP( i , MAX_LRHSEGTREE )
      rh[i].init( n );
  }
  void init( const vl &a ){
    REP( i , MAX_LRHSEGTREE )
      rh[i].init( a );
  }
  void update( int a , int b , ll x ){
    REP( i , MAX_LRHSEGTREE )
      rh[i].update( a , b , x );
  }
  vl query( int a , int b ){
    vl res;
    REP( i , MAX_LRHSEGTREE )
      res.pb( rh[i].query( a , b ) );
    return res;
  }
};

const int MAX_N = 100010;

int n, m, k;
char s[MAX_N];

vl a;

LRHSegtree rh;

int main(){

  scanf( "%d %d %d\n" , &n , &m , &k );
  scanf( "%s\n" , s );

  REP( i , n )
    a.pb( s[i] - '0' );

  rh.init( a );

  REP( loop_cnt , m+k ){
    int a , b , c , d;
    scanf( "%d %d %d %d\n" , &a , &b , &c , &d );
    if( a == 1 ){
      rh.update( b-1 , c , d );
    } else if( a == 2 ){
      if( rh.query( b-1 , c-d ) == rh.query( b-1+d , c ) ) printf( "YES\n" );
      else printf( "NO\n" );
    }
  }

  return 0;
}