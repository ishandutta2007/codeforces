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
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct LCA{
  vi dep;
  mi par;
  int n, logn;
  mi G;
  queue<int> que;
  void init( const mi &arg_G , int root = 0 ){
    G = arg_G;
    n = G.size();
    logn = log2( n ) + EPS + 2;
    dep.resize( n );
    par.resize( logn , vi( n ) );
    bfs( root );
    lca_init();
  }
  void bfs( int root ){
    while( !que.empty() ) que.pop();
    que.push( root );
    par[0][root] = -1;
    dep[root] = 0;
    while( !que.empty() ){
      int x = que.front(); que.pop();
      YYS( w , G[x] ) if( w != par[0][x] ){
	par[0][w] = x;
	dep[w] = dep[x] + 1;
	que.push( w );
      }
    }
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

const ll MAX_N = 100010;

ll ans;

ll n, k;
mi G;

LCA lca;

ll ord[MAX_N], dep[MAX_N];
ll sz;

set<pl> ss;

ll c;
void dfs( ll x , ll p , ll d = 0 ){
  ord[x] = c++;
  dep[x] = d;
  YYS( w , G[x] ) if( w != p ) dfs( w , x , d+1 );
}

ll ne( ll x ){
  auto ite = ss.lower_bound( pl( ord[x] , x ) );
  if( ite == ss.end() ) ite = ss.begin();
  return (*ite).se;
}

ll pr( ll x ){
  auto ite = ss.lower_bound( pl( ord[x] , x ) );
  if( ite == ss.begin() ) ite = ss.end();
  ite--;
  return (*ite).se;
}

ll calc( ll x ){
  if( ss.empty() ) return 1;
  
  ll y = pr( x );
  ll z = ne( x );

  ll lcay = lca.lca( x , y );
  ll lcaz = lca.lca( x , z );
  ll lcayz = lca.lca( y , z );

  ll u = lcay;
  if( dep[u] < dep[lcaz] ) u = lcaz;
  if( dep[u] < dep[lcayz] ) u = lcayz;

  return dep[x] + dep[u] - 2 * dep[lca.lca(x,u)];
}

void add( ll x ){
  sz += calc( x );
  ss.emplace( ord[x] , x );
}

void del( ll x ){
  ss.erase( pl( ord[x] , x ) );
  sz -= calc( x );
}

int main(){

  scanf( "%lld %lld" , &n , &k );
  G.resize( n );
  REP( i , n-1 ){
    ll a, b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  lca.init( G , 0 );

  dfs( 0 , -1 );

  ll t = 0;
  REP( s , n ){
    while( t < n && sz + calc(t) <= k ) add( t++ );
    chmax( ans , t-s );
    del( s );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}