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

struct edge{
  ll fr , to, co;
  ll id;
  edge(){}
  edge( ll to ) : to(to){}
  edge( ll to , ll co ) : to(to) , co(co){}
  edge( ll fr , ll to , ll co ) : fr(fr) , to(to) , co(co){}
  edge( ll fr , ll to , ll co , ll id ) : fr(fr) , to(to) , co(co) , id(id){}  
};
typedef vector<vector<edge> > Graph;

vpl ts;
int ans;

const int DIJKSTRA_MAX_N = 1000010;
struct Dijkstra{
  Graph G;
  vl dist;
  int size;
  vpl sorted;

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
  
    priority_queue<pl,vector<pl>,greater<pl> > que;
    que.push( pl( 0 , s ) );
  
    int c = 0;
    while( !que.empty() ){
      while( c < ts.size() && ts[c].fi < que.top().fi ){
	if( ts[c].fi < dist[ts[c].se] ){
	  dist[ts[c].se] = ts[c].fi;
	  que.push( ts[c] );
	  ans++;
	}
	c++;
      }
      ll d = que.top().fi;
      ll p = que.top().se;
      que.pop();
      if( d > dist[p] ) continue;
      REP( i , G[p].size() ){
	ll to = G[p][i].to;
	ll co = G[p][i].co;
	if( d+co < dist[to] ){
	  dist[to] = d+co;
	  que.push( pl( dist[to] , to ) );
	}
      }
    }

    return dist[t];
  }

  vector<pl> get_sorted(){
    sorted.clear();
    REP( i , size )
      sorted.pb( pl( dist[i] , i ) );

    sort( ALL( sorted ) );
    return sorted;
  }
};

Dijkstra dij;

int n, m, k;
int u, v, x;
int s, y;

int main(){

  scanf( "%d %d %d" , &n , &m , &k );

  dij.init( n );
  
  REP( i , m ){
    scanf( "%d %d %d" , &u , &v , &x ); u--; v--;
    dij.add_biedge( u , v , x );
  }

  REP( i , k ){
    scanf( "%d %d" , &s , &y ); s--;
    ts.pb( pl( y , s ) );
  }
  SORT( ts );

  dij.dijkstra( 0 );

  printf( "%d\n" , k-ans );
  
  return 0;
}