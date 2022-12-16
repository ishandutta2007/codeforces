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

struct edge{
  ll to , cap , rev;
  edge(){}
  edge( ll to , ll cap , ll rev ) : to(to) , cap(cap) , rev(rev) {}
};

struct MaxFlow{
  vector<vector<edge> > G;
  ll n;
  vl level, iter;
  void init( int size ){
    n = size;
    G = vector<vector<edge> >( size , vector<edge>(0) );
    level = iter = vl( size , 0 );
  }
  void add_edge( ll fr , ll to , ll cap ){
    G[fr].pb( to , cap , SZ(G[to]) );
    G[to].pb( fr , 0 , SZ(G[fr])-1 );
  }
  void bfs( ll s ){
    level = vl( n , INFLL );
    level[s] = 0;
    
    queue<ll> que;
    que.push( s );
    while( !que.empty() ){
      ll x = que.front(); que.pop();
      YYS( w , G[x] ){
	if( w.cap > 0 && level[w.to] == INFLL ){
	  level[w.to] = level[x] + 1;
	  que.push( w.to );
	}
      }
    }
  }
  ll dfs( ll x , ll t , ll f ){
    if( x == t ) return f;
    for( ll &i = iter[x]; i < SZ(G[x]); i++ ){
      edge &e = G[x][i];
      if( level[e.to] <= level[x] || e.cap == 0 ) continue;
      ll res = dfs( e.to , t , min( f , e.cap ) );
      if( res > 0 ){
	e.cap -= res;
	G[e.to][e.rev].cap += res;
	return res;
      }
    }
    return 0;
  }
  ll max_flow( ll s , ll t ){
    ll flow = 0;
    while( 1 ){
      bfs( s );
      if( level[t] == INFLL ) return flow;
      iter = vl( n , 0 );
      while( 1 ){
	ll res = dfs( s , t , INFLL );
	if( res == 0 ) break;
	flow += res;
      }
    }
  }
};

struct medge{
  int to , cap , cost , rev;
  medge(){}
  medge( int to , int cap , int cost , int rev ) : to(to) , cap(cap) , cost(cost) , rev(rev){}
};
struct MinCostFlow{
  int V;
  vector<vector<medge> > G;
  vi dist, prevv, preve;

  void init( int n ){
    V = n;
    G = vector<vector<medge> >( n , vector<medge>(0) );
    dist = prevv = preve = vi(n,0);
  }

  void add_edge( int from , int to , int cap , int cost ){
    G[from].pb( to , cap , cost , G[to].size() );
    G[to].pb( from , 0 , -cost , G[from].size()-1 );
  }

  int min_cost_flow( int s , int t , int f ){
    int res = 0;
    while( f > 0 ){
      dist = vi( V , INF );
      dist[s] = 0;
      bool update = true;
      while( update ){
	update = false;
	REP( v , V ){
	  if( dist[v] == INF ) continue;
	  REP( i , G[v].size() ){
	    medge &e = G[v][i];
	    if( e.cap > 0 && dist[e.to] > dist[v] + e.cost ){
	      dist[e.to] = dist[v] + e.cost;
	      prevv[e.to] = v;
	      preve[e.to] = i;
	      update = true;
	    }
	  }
	}
      }

      if( dist[t] == INF ) return INF;

      int d = f;
      for( int v = t; v != s; v = prevv[v] )
	d = min( d , G[prevv[v]][preve[v]].cap );

      f -= d;
      res += d * dist[t];
      for( int v = t; v != s; v = prevv[v] ){
	medge &e = G[prevv[v]][preve[v]];
	e.cap -= d;
	G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

const ll MAX_N = 72;

ll n, k;

MaxFlow mf;
MinCostFlow mcf;

int main(){

  scanf( "%lld %lld" , &n , &k );
  mf.init( n );
  mcf.init( n );
  
  REP( i , n ) REP( j , n ){
    ll a;
    scanf( "%lld" , &a );
    if( a > 0 ){
      mf.add_edge( i , j , a );
      mcf.add_edge( i , j , a , 0 );
      mcf.add_edge( i , j , INF , 1 );
    }
  }

  ll ans = mf.max_flow( 0 , n-1 );
  mcf.min_cost_flow( 0 , n-1 , ans );
  while( 1 ){
    ll res = mcf.min_cost_flow( 0 , n-1 , 1 );
    if( res > k ) break;
    k -= res;
    ans++;
  }

  printf( "%lld\n" , ans );
  
  return 0;
}