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
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;
const int RMQ_MAX_N = MAX_N*4;
const ll RMQ_INIT = -1e18; // MAX
const ll RMQ_NONE = -1e18; // MAX
template<typename T>
struct Segtree{
  T node[RMQ_MAX_N];
  int idnode[RMQ_MAX_N];
  int size;
  bool com( T a , T b ){
    return a > b; // MAX
  }
  T cho( T a , T b ){
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
  void update( int k , T x ){
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
  int idquery( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return idnode[k];
    } else if( b <= l || r <= a ){
      return size+1;
    } else {
      int chl = idquery( a , b , k*2+1 , l , (l+r)/2 );
      int chr = idquery( a , b , k*2+2 , (l+r)/2 , r );
      return com( node[chl+size-1] , node[chr+size-1] ) ? chl : chr;
    }
  }
  int idquery( int a , int b ){
    return idquery( a , b , 0 , 0 , size );
  }
  T query( int a , int b ){
    return node[idquery(a,b)+size-1];
  }
};

template<typename T>
struct LazyBit{
  T node[RMQ_MAX_N];
  T lazy[RMQ_MAX_N];
  int size;
  inline void push( int k , int l , int r ){
    node[k] = (r-l) * lazy[k];
    if( k < size-1 )
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
    lazy[k] = INF;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    for( int i = 0; i < size*2-1; i++ ){
      lazy[i] = INF;
      node[i] = 0;
    }
  }
  void update( int a , int b , T x , int k , int l , int r ){
    if( lazy[k] != INF ) push( k , l , r );
    if( a <= l && r <= b ){
      lazy[k] = x;
      push( k , l , r );
    } else if( b <= l || r <= a ){

    } else {
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = node[k*2+1] + node[k*2+2];
    }
  }
  void update( int a , int b , T x ){
    update( a , b , x , 0 , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    if( lazy[k] != INF ) push( k , l , r );
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      return query( a , b , k*2+1 , l , (l+r)/2 ) + query( a , b , k*2+2 , (l+r)/2 , r );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};


typedef pair<pl,double> pld;
typedef pair<ll,pld> lpld;

Segtree<ll> seg;
LazyBit<ll> lzb;

ll n, q;
ll a[MAX_N];
lpld b[MAX_N];

vector<ll> G[MAX_N];

ll M[MAX_N];

bool used[5010][5010];
double memo[5010][5010];

double rec( int t , int s ){
  if( s < 0 ) return 0.0;
  if( s > q ) return 1.0;
  if( used[t][s] ) return memo[t][s];
  used[t][s] = true;
  
  double p = b[t].se.se;

  double res1 = 1.0;
  REPR( w , G[t] )
    res1 *= rec( w , M[t] - M[w] + s     );
  if( s == 0 ) return memo[t][s] = res1 * ( 1 - p );

  double res2 = 1.0;
  REPR( w , G[t] )
    res2 *= rec( w , M[t] - M[w] + s - 1 );

  return memo[t][s] = res1 * ( 1 - p ) + res2 * p;
}


int main(){

  cin >> n >> q;
  seg.init( n );
  REP( i , n ){
    cin >> a[i];
    seg.update( i , a[i] );
  }

  REP( i , q ){
    cin >> b[i].se.fi.fi >> b[i].se.fi.se >> b[i].se.se;
    b[i].se.fi.fi--;
    b[i].fi = b[i].se.fi.se - b[i].se.fi.fi;
  }
  b[q] = lpld( INFLL , pld( pl( 0 , n ) , 0.0 ) ); q++;
  sort( b , b+q );
  reverse( b , b+q );

  lzb.init( n );
  FOR( i , 1 , q ){
    ll l = b[i].se.fi.fi;
    ll r = b[i].se.fi.se;
    ll id = lzb.query( l , l+1 );
    G[id].pb( i );
    lzb.update( l , r , i );
  }

  REP( i , q )
    M[i] = seg.query( b[i].se.fi.fi , b[i].se.fi.se );


  double maxv = seg.query( 0 , n );
  double ans = rec( 0 , 0 ) * maxv;
  FOR( i , 1 , q )
    ans += ( rec( 0 , i ) - rec( 0 , i-1 ) ) * ( maxv + (double)i );

  /*
  REP( i , 5 ){
    REP( j , 10 )
      cout << rec( i , j ) << " ";
    cout << endl;
  }
  */
  
  cout << setprecision(18) << ans << endl;
  
  return 0;
}