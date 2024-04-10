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


template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}

template<typename T>
struct Segtree{
  const ll SEG_INIT = -INFLL; // MAX
  const ll SEG_NONE = -INFLL; // MAX
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

const int MAX_N = 600010;

int n;
ll d, h;
vl hs;
vi ans;
vi chs;
pair<vi,vector<ll> > cp;

ll cid[MAX_N], res[MAX_N], pr[MAX_N];

Segtree<ll> seg;

int main(){

  scanf( "%d %lld" , &n , &d );
  REP( i , n ){
    scanf( "%lld" , &h );
    hs.pb( h );
    hs.pb( h - d + 1 );
    hs.pb( h + d );
  }

  hs.pb( -INFLL ); hs.pb( INFLL );

  cp = compress( hs );
  chs = cp.fi;

  int m = cp.se.size();
  seg.init( m );

  seg.update( 0 , 0 );
  cid[0] = -1;
  
  REP( i , n ){
    ll idl = seg.idquery( 0 , chs[i*3+1] );
    ll idr = seg.idquery( chs[i*3+2] , m );
    ll ch = chs[i*3];
    if( res[idl] < res[idr] ) pr[i] = cid[idr];
    else pr[i] = cid[idl];
    res[ch] = max( res[idl] , res[idr] ) + 1;
    cid[ch] = i;
    seg.update( ch , res[ch] );
  }

  int ansid = cid[ seg.idquery( 0 , m ) ];
  while( ansid != -1 ){
    ans.pb( ansid );
    ansid = pr[ansid];
  }
  REVERSE( ans );

  printf( "%d\n" , (int)ans.size() );
  REP( i , ans.size() ) printf( "%d%c" , ans[i]+1 , i+1==ans.size()?'\n':' ' );
  
  return 0;
}