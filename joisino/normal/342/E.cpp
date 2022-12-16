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
const ll B = 128;

ll n, m;
mi G;

LCA lca;

bool red[MAX_N];

ll ord[MAX_N], ordcnt;

vl ss;

ll di( ll x , ll y ){
  return lca.dep[x] + lca.dep[y] - lca.dep[ lca.lca( x , y ) ] * 2;
}

void dfs( ll x , ll p ){
  ord[x] = ordcnt++;
  YYS( w , G[x] ) if( w != p ) dfs( w , x );
}

ll dist[MAX_N];

ll que[MAX_N];
void update(){
  ll s = 0, t = 0;
  REP( i , n ) dist[i] = INFLL;
  REP( i , n ) if( red[i] ) que[t++] = i, dist[i] = 0;
  while( s != t ){
    ll x = que[s++];
    YYS( w , G[x] ) if( dist[w] == INFLL ){
      dist[w] = dist[x] + 1;
      que[t++] = w;
    }
  }
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  G = mi( n , vi( 0 ) );
  REP( i , n-1 ){
    ll a ,b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  lca.init( G , 0 );

  dfs( 0 , -1 );
  
  red[0] = true;
  ss.pb( 0 );

  REP( i , n ) dist[i] = INFLL;

  REP( query_cnt , m ){
    ll t, v;
    scanf( "%lld %lld" , &t , &v ); v--;
    if( t == 1 ){
      ss.pb( v );
      red[v] = true;
      if( ss.size() == B ){
	ss.clear();
	update();
      }
    } else if( t == 2 ){
      ll ans = dist[v];
      YYS( w , ss ) chmin( ans , di( v , w ) );
      printf( "%lld\n" , ans );
    }
  }
  
  
  return 0;
}