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
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll IDENTITY = 0;
struct RangeAdd{
  vl node;
  int size;
  ll ad( ll a , ll b ){
    return a | b;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vl( size*2-1 , IDENTITY );
  }
  void update( int k , ll x ){
    k += size-1;
    node[k] = x;
  }
  void addren( int a , int b , ll x , int k, int l, int r ){
    if( a <= l && r <= b ){
      node[k] = ad( node[k] , x );
    } else if( b <= l || r <= a ){
      return;
    } else {
      addren( a , b , x , k*2+1 , l , (l+r)/2 );
      addren( a , b , x , k*2+2 , (l+r)/2 , r );
    }
  }
  void addren( int a , int b , ll x ){
    addren( a , b , x , 0 , 0 , size );
  }
  ll query( int a , int k, int l, int r ){
    if( r-l == 1 ) return node[k];
    if( a < (l+r)/2 ) return ad( query( a , k*2+1 , l , (l+r)/2 ) , node[k] );
    else return ad( query( a , k*2+2 , (l+r)/2 , r ) , node[k] );
  }
  ll get( int a ){
    return query( a , 0 , 0 , size );
  }
};


const ll SEGIDENTITY = (1LL<<62)-1; // and
template<typename T>
struct Segtree{
  vector<T> node;
  int size;
  T op( T a , T b ){
    return a & b;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , SEGIDENTITY );
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
      return SEGIDENTITY;
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


const int MAX_N = 100010;

RangeAdd ra;
Segtree<ll> seg;

int n, m;
int l[MAX_N], r[MAX_N], q[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ) scanf( "%d %d %d" , &l[i] , &r[i] , &q[i] ), l[i]--;

  ra.init( n );
  REP( i , m ) ra.addren( l[i] , r[i] , q[i] );
  
  seg.init( n );
  REP( i , n ) seg.update( i , ra.get(i) );

  REP( i , m ) if( seg.query( l[i] , r[i] ) != q[i] ) return puts( "NO" );

  printf( "YES\n" );
  REP( i , n ){
    if( i != 0 ) printf( " " );
    printf( "%lld" , seg.get( i ) );
  }
  printf( "\n" );
  
  return 0;
}