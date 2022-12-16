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

const ll SEG_INIT = 1e18; // MIN
const ll SEG_NONE = 1e18; // MIN
template<typename T>
struct Segtree{
  vector<T> node;
  vi idnode;
  int size;
  bool com( T a , T b ){
    return a < b; // MIN
  }
  T cho( T a , T b ){
    return com( a , b ) ? a : b;
  }
  void init( const vector<T> &a ){
    size = 1;
    while( size < a.size() ) size *= 2;
    node = vector<T>( size*2 );
    idnode = vi( size*2 );
    for( int i = size*2-2; i >= 0; i-- ){
      if( i >= size-1 ){
	if( i-(size-1) < a.size() ) node[i] = a[i-(size-1)];
	else node[i] = SEG_INIT;
	idnode[i] = i-size+1;
      } else {
	if( com( node[i*2+1] , node[i*2+2] ) ){
	  node[i] = node[i*2+1];
	  idnode[i] = idnode[i*2+1];
	} else {
	  node[i] = node[i*2+2];
	  idnode[i] = idnode[i*2+2];
	}
      }
    }
    node[size*2-1] = SEG_NONE;
  }
  void init( int n ){
    vector<T> a(n,SEG_INIT);
    init( a );
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
      return size;
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
  T get( int a ){
    return node[a+size-1];
  }
};

const ll SEG_INIT2 = -1e18; // MAX
const ll SEG_NONE2 = -1e18; // MAX
template<typename T>
struct SegtreeM{
  vector<T> node;
  vi idnode;
  int size;
  bool com( T a , T b ){
    return a > b; // MAX
  }
  T cho( T a , T b ){
    return com( a , b ) ? a : b;
  }
  void init( const vector<T> &a ){
    size = 1;
    while( size < a.size() ) size *= 2;
    node = vector<T>( size*2 );
    idnode = vi( size*2 );
    for( int i = size*2-2; i >= 0; i-- ){
      if( i >= size-1 ){
	if( i-(size-1) < a.size() ) node[i] = a[i-(size-1)];
	else node[i] = SEG_INIT;
	idnode[i] = i-size+1;
      } else {
	if( com( node[i*2+1] , node[i*2+2] ) ){
	  node[i] = node[i*2+1];
	  idnode[i] = idnode[i*2+1];
	} else {
	  node[i] = node[i*2+2];
	  idnode[i] = idnode[i*2+2];
	}
      }
    }
    node[size*2-1] = SEG_NONE2;
  }
  void init( int n ){
    vector<T> a(n,SEG_INIT2);
    init( a );
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
      return size;
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
  T get( int a ){
    return node[a+size-1];
  }
};


const int MAX_N = 100010;

Segtree<ll> dp;
Segtree<ll> seg;
SegtreeM<ll> segM;
ll n, s, l;
vl a;

int main(){

  cin >> n >> s >> l;
  a = vl(n);
  REP( i , n ) cin >> a[i];
  seg.init( a );
  segM.init( a );
  dp.init( n );
  dp.update( 0 , 0 );


  FOR( i , l-1 , n ){
    ll lb = -1, ub = i-l+2;
    while( ub - lb > 1 ){
      ll md = ( ub + lb ) / 2;
      if( segM.query( md , i+1 ) - seg.query( md , i+1 ) <= s ) ub = md;
      else lb = md;
    }
    dp.update( i+1 , dp.query( ub , i+2-l ) + 1 );
  }
  
  if( dp.get( n ) > n ) cout << -1 << endl;
  else cout << dp.get( n ) << endl;

  return 0;
}