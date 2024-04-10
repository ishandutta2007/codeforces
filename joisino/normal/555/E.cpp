#include <bits/stdc++.h>
  
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
 
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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
 
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

struct SCC{
  int n, k;
  mi G, rG;
  vi vs, cmp;
  vb used;
  void init( int size ){
    n = size;
    G = rG = mi( n , vi(0) );
    cmp = vi( n );
    vs.clear();
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    rG[b].pb( a );
  }
  void dfs( int x ){
    used[x] = true;
    YYS( w , G[x] ) if( !used[w] ) dfs( w );
    vs.pb( x );
  }
  void rdfs( int x ){
    used[x] = true;
    cmp[x] = k;
    YYS( w , rG[x] ) if( !used[w] ) rdfs( w );
  }
  int scc(){
    used = vb( n , false );
    REP( i , n ) if( !used[i] ) dfs( i );
    REVERSE( vs );
    k = 0;
    used = vb( n , false );
    YYS( w , vs ) if( !used[w] ) rdfs( w ), k++;
    return k;
  }
};

struct BECC{
  int n;
  mi G;
  vb used;
  SCC scc;
  void init( int arg_n ){
    n = arg_n;
    G = mi( n , vi(0) );
    used = vb( n , false );
    scc.init( n );
  }
  void add_edge( int a , int b ){
    G[a].pb( b ); G[b].pb( a );
  }
  void dfs( int x , int p ){
    used[x] = true;
    YYS( w , G[x] ) if( w != p ){
      scc.add_edge( x , w );
      if( !used[w] ) dfs( w , x );
    }
  }
  int becc(){
    REP( i , n ) if( !used[i] ) dfs( i , -1 );
    return scc.scc();
  }
};

struct LCA{
  vi dep;
  mi par;
  int n, logn;
  mi G;
  void init( int arg_n ){
    n = arg_n;
    G = mi( n , vi( 0 ) );
    logn = 0;
    while( PW(logn) < n ) logn++;
    dep = vi( n , -1 );
    par = mi( logn , vi( n , 0 ) );
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    G[b].pb( a );
  }
  void dfs( int x , int p , int d ){
    par[0][x] = p;
    dep[x] = d;
    YYS( w , G[x] ) if( w != p ) dfs( w , x , d+1 );
  }
  void calc_par(){
    FOR( i , 1 , logn ){
      REP( j , n ){
	if( par[i-1][j] == -1 ) par[i][j] = -1;
	else par[i][j] = par[i-1][ par[i-1][j] ];
      }
    }
  }
  void lca_init(){
    REP( i , n ) if( dep[i] == -1 ) dfs( i , -1 , 0 );
    calc_par();
  }
  int lca( int a , int b ){
    if( dep[a] > dep[b] ) swap( a , b );
    REP( i , logn ) if( (dep[b]-dep[a]) & PW(i) ) b = par[i][b];
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

BECC becc;
LCA lca;

int n, m, q;

vi G[200010];

bool used[200010];
int s[200010], t[200010], l[200010];

bool ans = true;

set<pi> ss;

void dfs( int x ){
  used[x] = true;
  YYS( w , G[x] ) if( !used[w] ){
    dfs( w );
    s[x] += s[w];
    t[x] += t[w];
    l[x] += l[w];
  }
  int a = s[x] - l[x];
  int b = t[x] - l[x];
  assert( a >= 0 && b >= 0 );
  if( a > 0 && b > 0 ) ans = false;
}

int main(){

  scanf( "%d %d %d" , &n , &m , &q );
  becc.init( n );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    if( a > b ) swap( a , b );
    if( ss.find( pi( a , b ) ) != ss.end() ){
      becc.scc.add_edge( a , b );
      becc.scc.add_edge( b , a );
    }
    ss.insert( pi( a , b ) );
    becc.add_edge( a , b );
  }
  int k = becc.becc();
  
  lca.init( n );
  REP( i , n ) YYS( w , becc.G[i] ){
    int a = becc.scc.cmp[i];
    int b = becc.scc.cmp[w];
    if( a < b ){
      lca.add_edge( a , b );
      G[a].pb( b );
      G[b].pb( a );
    }
  }
  lca.lca_init();

  REP( query_cnt , q ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    a = becc.scc.cmp[a];
    b = becc.scc.cmp[b];
    if( lca.lca(a,b) == -1 ){
      ans = false;
      break;
    }
    s[a]++; t[b]++; l[lca.lca(a,b)]++;
  }

  REP( i , k ) if( !used[i] ) dfs( i );

  if( ans ) puts( "Yes" );
  else puts( "No" );
  
  return 0;
}