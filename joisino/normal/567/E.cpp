#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }




struct edge{
  ll fr , to, co;
  ll id;
  edge(){}
  edge( ll to ) : to(to){}
  edge( ll to , ll co ) : to(to) , co(co){}
  edge( ll to , ll co , ll id ) : to(to) , co(co) , id(id){}
  edge( ll fr , ll to , ll co , ll id ) : fr(fr) , to(to) , co(co) , id(id){}  
};
typedef vector<vector<edge> > Graph;


const int DIJKSTRA_MAX_N = 1000010;
struct Dijkstra{
  Graph G;
  vec dist;
  int size;
  vector<P> sorted;

  void init( int n ){
    size = n;
    G.resize( size );
    dist.resize( size );
  }
  
  Dijkstra(){
    init( DIJKSTRA_MAX_N );
  }
  
  void add_biedge( ll fr , ll to , ll co ){
    G[fr].pb( edge( to , co ) );
    G[to].pb( edge( fr , co ) );
  }
  
  void add_edge( ll fr , ll to , ll co ){
    G[fr].pb( edge( to , co ) );
  }

  ll dijkstra( ll s , ll t = 0 ){
    REP( i , size )
      dist[i] = INFLL;
    dist[s] = 0;
  
    priority_queue<P,vector<P>,greater<P> > que;
    que.push( P( 0 , s ) );
  
    while( !que.empty() ){
      ll d = que.top().fi;
      ll p = que.top().se;
      que.pop();
      if( d > dist[p] ) continue;
      REP( i , G[p].size() ){
	ll to = G[p][i].to;
	ll co = G[p][i].co;
	if( d+co < dist[to] ){
	  dist[to] = d+co;
	  que.push( P( dist[to] , to ) );
	}
      }
    }

    return dist[t];
  }

  vector<P> get_sorted(){
    sorted.clear();
    REP( i , size )
      sorted.pb( P( dist[i] , i ) );

    sort( ALL( sorted ) );
    return sorted;
  }
} dij , bdij;


// artpoint is not verified
const int BRIDGE_MAX_N = 1000010;
struct Bridge{
  Graph G;
  Graph T;
  vector<bool> used;
  vec ord;
  vec lowlink;
  vector<bool> isroot;
  int ordcnt;
  int size;
  vector<edge> bridge;
  vec artpoint;

  void init( int n ){
    size = n;
    G.resize( size );
    T.resize( size );
    used.resize( size );
    ord.resize( size );
    lowlink.resize( size );
    isroot.resize( size );
  }
  
  Bridge(){
    init( BRIDGE_MAX_N );
  }
  
  void add_edge( ll fr , ll to , ll id ){
    G[fr].pb( edge( fr , to , 1 , id ) );
    G[to].pb( edge( to , fr , 1 , id ) );
  }

  void dfs( int x , int pid ){
    used[x] = true;
    ord[x] = lowlink[x] = ordcnt++;
    REP( i , G[x].size() ){
      int v = G[x][i].to;
      if( !used[v] ){
	T[x].pb( edge(v) );
	dfs( v , G[x][i].id );
	chmin( lowlink[x] , lowlink[v] );
      } else if( G[x][i].id != pid ){
	chmin( lowlink[x] , ord[v] );
      }
    }
  }
  
  pair<vector<edge>, vec> calc(){
    ordcnt = 0;
    REP( i , size ){
      used[i] = false;
      isroot[i] = false;
      ord[i] = lowlink[i] = 0;
    }

    REP( i , size ){
      if( !used[i] ){
	dfs( i , -1 );
	isroot[i] = true;
      }
    }

    bridge.clear();
    REP( i , size ){
      REP( j , G[i].size() ){
	if( i > G[i][j].to ) continue;
	int a = i, b = G[i][j].to;
	if( ord[a] > ord[b] ) swap( a , b );
	if( ord[a] < lowlink[b] ) bridge.pb( G[i][j] );
      }
    }

    artpoint.clear();
    REP( i , size ){
      if( isroot[i] ){
	if( T[i].size() >= 2 )
	  artpoint.pb( i );
      } else {
	bool ok = false;
	REP( j , T[i].size() )
	  if( ord[i] <= lowlink[T[i][j].to] ) ok = true;
	if( ok ) artpoint.pb( i );
      }
    }
    
    return make_pair( bridge , artpoint );
  }
} bri;

typedef pair<P,P> PP;
vector<PP> es;

vec ans;

int main(){

  int n , m , s , t;
  cin >> n >> m >> s >> t; s--; t--;

  dij.init( n );
  bdij.init( n );
  bri.init( n );
  
  REP( i , m ){
    int a , b , c;
    cin >> a >> b >> c; a--; b--;
    es.pb( PP( P( i , c ) , P( a , b ) ) );
    dij.add_edge( a , b , c );
    bdij.add_edge( b , a , c );
  }

  ll dist = dij.dijkstra( s , t );
  vec fs = dij.dist;
  bdij.dijkstra( t , s );
  vec ft = bdij.dist;
  
  ans.resize( m );
  REP( i , m ){
    ll id = es[i].fi.fi;
    ll co = es[i].fi.se;
    ll a = es[i].se.fi, b = es[i].se.se;
    ans[id] = fs[a]+co+ft[b] - dist + 1;
    if( fs[a]+co+ft[b] == dist ){
      bri.add_edge( a , b , id );
    }
  }

  vector<edge> bris = bri.calc().fi;

  REP( i , bris.size() ){
    ans[ bris[i].id ] = 0;
  }

  REP( i , m ){
    if( ans[i] == 0 ) cout << "YES" << endl;
    else if( ans[i] < es[i].fi.se ) cout << "CAN " << ans[i] << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}