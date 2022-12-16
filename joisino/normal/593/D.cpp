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
const ll INFLL = (1e18)*2+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<typename T>
struct Segtree{
  const ll ID = 1; // indetity element
  vector<T> node;
  int size;
  T op( T a , T b ){ // operator
    if( log10(a) + log10(b) > 18.4 ) return INFLL;
    if( a * b >= INFLL ) return INFLL;
    return a * b;
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

struct LCA{
  vi dep;
  mi par;
  int n, logn;
  mi G;

  void init( const mi &arg_G , int root = 0 ){
    G = arg_G;
    n = G.size();
    logn = log2( n ) + EPS + 2;
    dep.resize( n );
    par.resize( logn , vi( n ) );
    par_init( root , -1 , 0 );
    lca_init();
  }

  void par_init( int x , int p , int d ){
    par[0][x] = p;
    dep[x] = d;
    YYS( w , G[x] ) if( w != p ) par_init( w , x , d+1 );
  }

  void lca_init(){
    FOR( i , 1 , logn ){
      REP( j , n ){
	if( par[i-1][j] == -1 ) par[i][j] = -1;
	else par[i][j] = par[i-1][ par[i-1][j] ];
      }
    }
  }

  int lca( int a , int b ){
    if( dep[a] > dep[b] ) swap( a , b );
    for( int i = logn-1; i >= 0; i-- )
      if( (dep[b]-dep[a]) & PW(i) ) b = par[i][b];
    if( a == b ) return a;
    for( int i = logn-1; i >= 0; i-- ){
      if( par[i][a] != par[i][b] ){
	a = par[i][a];
	b = par[i][b];
      }
    }
    return par[0][a];
  }
};


struct HeavyLightDecomposition{
  int n, root;
  mi G, path;
  vi belong, id, size, par;
  int path_cnt;
  void init( const mi &arg_G , int arg_root = 0 ){
    G = arg_G;
    root = arg_root;
    n = G.size();
    belong = id = size = par = vi(n);
    dfs( root , -1 );
    path_cnt = 1;
    decomposition( root , -1 , 0 , 0 );
  }
  int dfs( int x , int p ){
    size[x] = 1;
    par[x] = p;
    YYS( w , G[x] ) if( w != p ){
      size[x] += dfs( w , x );
    }
    return size[x];
  }
  void decomposition( int x , int p , int index , int path_id ){
    belong[x] = path_id;
    id[x] = index;
    while( path.size() <= path_id ) path.pb( vi(0) );
    path[ path_id ].pb( x );
    
    int argmax = -1;
    YYS( w , G[x] ) if( w != p ){
      if( argmax == -1 ) argmax = w;
      else if( size[ argmax ] < size[w] ) argmax = w;
    }
    if( argmax == -1 ) return; // leaf
    decomposition( argmax , x , index+1 , path_id ); // heavy edge
    YYS( w , G[x] ) if( w != p && w != argmax ){
      decomposition( w , x , 0 , path_cnt++ ); // light edge
    }
  }
};


struct Query{
  vector<Segtree<ll> > ss;
  HeavyLightDecomposition hl;
  gr G;
  int n;
  mi sG;

  LCA lca;
  
  void init( const gr &arg_G ){
    G = arg_G;
    n = G.size();

    sG = mi( n , vi(0) );
    REP( i , n ) YYS( w , G[i] ) sG[i].pb( w.fi );
    hl.init( sG );

    lca.init( sG );

    int pc = hl.path_cnt;
    ss.resize( pc );
    REP( i , pc ) ss[i].init( hl.path[i].size() );

    REP( i , n ) YYS( w , G[i] ) if( w.fi == hl.par[i] ){
      ss[ hl.belong[i] ].update( hl.id[i] , w.se );
    }
  }
  void update( int a , int b , ll c ){
    if( hl.par[a] == b ) swap( a , b );
    ss[ hl.belong[b] ].update( hl.id[b] , c );
  }
  ll query( int a , int b , ll y ){
    int l = lca.lca( a , b );
    int bl = hl.belong[l];
    
    REP( ite , 2 ){
      while( hl.belong[a] != bl ){
	int t = hl.belong[a];
	y /= ss[t].query( 0 , hl.id[a]+1 );
	a = hl.par[ hl.path[t][0] ];
      }
      swap( a , b );
    }

    if( hl.id[a] > hl.id[b] ) swap( a , b );
    y /= ss[bl].query( hl.id[a]+1 , hl.id[b]+1 );

    return y;
  }
};

const int MAX_N = 200010;

Query Q;

int n, m;
pi e[MAX_N];
gr G;

int main(){

  scanf( "%d %d" , &n , &m );
  G.resize( n , vpl(0) );
  REP( i , n-1 ){
    int a , b;
    ll c;
    scanf( "%d %d %lld" , &a , &b , &c ); a--; b--;
    e[i] = pi( a , b );
    G[a].pb( b , c );
    G[b].pb( a , c );
  }

  Q.init( G );

  REP( query_cnt , m ){
    int t, a, b, p;
    ll c, y;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d %lld" , &a , &b , &y ); a--; b--;
      printf( "%lld\n" , Q.query( a , b , y ) );
    } else if( t == 2 ){
      scanf( "%d %lld" , &p , &c ); p--;
      Q.update( e[p].fi , e[p].se , c );
    }
  }
  
  return 0;
}