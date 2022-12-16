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
    return __gcd( a , b );
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


struct RangeSegtree{
  mi node;
  int size;
  void initdfs( int k , int l , int r , const vi &a ){
    if( r - l == 1 ){
      node[k].pb( a[l] );
    } else {
      initdfs( k*2+1 , l , (l+r)/2 , a );
      initdfs( k*2+2 , (l+r)/2 , r , a );
      node[k].resize( r-l );
      merge( ALL( node[k*2+1] ) , ALL( node[k*2+2] ) , node[k].begin() );
    }
  }
  void init( int n , const vi &a ){
    size = 1;
    while( size < n ) size *= 2;
    node.resize( size*2-1 );
    initdfs( 0 , 0 , size , a );
  }
  int query( int a , int b , int x , int k , int l , int r ){
    if( a <= l && r <= b ){
      return upper_bound( ALL( node[k] ) , x ) - lower_bound( ALL( node[k] ) , x );
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      return query( a , b , x , k*2+1 , l , (l+r)/2 ) + query( a , b , x , k*2+2 , (l+r)/2 , r );
    }
  }
  int query( int a , int b , int x ){
    return query( a , b , x , 0 , 0 , size );
  }
};

int n, q;
vi a;

Segtree<ll> seg;
RangeSegtree rangeseg;

int main(){

  scanf( "%d" , &n );
  a.resize( n );
  REP( i , n ) scanf( "%d" , &a[i] );
  rangeseg.init( n , a );
  
  seg.init( n );
  REP( i , n ) seg.update( i , a[i] );


  scanf( "%d" , &q );
  REP( query_cnt , q ){
    int l, r;
    scanf( "%d %d" , &l , &r ); l--;
    ll g = seg.query( l , r );
    printf( "%d\n" , r-l-rangeseg.query( l , r , g ) );
  }
  
  return 0;
}