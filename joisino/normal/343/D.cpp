#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }



template<typename T>
struct Segtree{
  const ll ID = 0; // indetity element
  vector<T> node;
  int size;
  T op( T a , T b ){ // operator
    return max( a , b );
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , ID );
  }
  void update( int k , T x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  T query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      T chl = query( a , b , k*2+1 , l , (l+r)/2 );
      T chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return op( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  T get( int a ){
    return node[a+size-1];
  }
};

template<typename T>
struct LazySegtree{
  const T ID = -1; // identity element
  vector<T> node, lazy;
  int size;
  inline T op( T a , T b ){ // operator
    return max( a , b );
  }
  inline T ranop( T a , int len ){  // op a len times
    return a; 
  }
  inline void push( int k , int l , int r ){
    node[k] = ranop( lazy[k] , r-l ); 
    if( k < size-1 )
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
    lazy[k] = INFLL;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    lazy = vector<T>( size*2-1 , INFLL );
    node = vector<T>( size*2-1 , ID );
  }
  void update( int a , int b , T x , int k , int l , int r ){
    if( lazy[k] != INFLL ) push( k , l , r );
    if( a <= l && r <= b ){
      lazy[k] = x;
      push( k , l , r );
    } else if( b <= l || r <= a ){
      return;
    } else {
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  void update( int a , int b , T x ){
    update( a , b , x , 0 , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    if( lazy[k] != INFLL ) push( k , l , r );
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      T chl = query( a , b , k*2+1 , l , (l+r)/2 );
      T chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return op( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};


const int MAX_N = 500010;

Segtree<ll> seg;
LazySegtree<ll> seg2;

int n, q;
vi G[MAX_N];
int in[MAX_N], out[MAX_N];
int k;

void dfs( int x , int p ){
  in[x] = k++;
  YYS( w , G[x] ) if( w != p ) dfs( w , x );
  out[x] = k;
}

int main(){

  scanf( "%d" , &n );
  seg.init( n );
  seg2.init( n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );

  scanf( "%d" , &q );
  REP( query_cnt , q ){
    int c, v;
    scanf( "%d %d" , &c , &v ); v--;
    if( c == 1 ){
      seg2.update( in[v] , out[v] , query_cnt+1 );
    } else if( c == 2 ){
      seg.update( in[v] , query_cnt+1 );
    } else if( c == 3 ){
      if( seg2.query( in[v] , in[v]+1 ) < seg.query( in[v] ,  out[v] ) ) printf( "0\n" );
      else printf( "1\n" );
    }
  }

  
  return 0;
}