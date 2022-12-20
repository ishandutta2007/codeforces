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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct MaxFlow{
  struct edge{
    int to, cap, rev;
    edge(){}
    edge( int to , int cap , int rev ) : to(to) , cap(cap) , rev(rev) {}
  };
  vector<vector<edge> > G;
  vi level, iter;
  int n;
  void init( int arg_n ){
    n = arg_n;
    G = vector<vector<edge> >( n , vector<edge>(0) );
  }
  void add_edge( int from , int to , int cap ){
    G[from].pb( to , cap , SZ(G[to]) );
    G[to].pb( from , 0 , SZ(G[from])-1 );
  }
  void bfs( int s ){
    level = vi( n , -1 );
    queue<int> que;
    level[s] = 0;
    que.push( s );
    while( !que.empty() ){
      int v = que.front(); que.pop();
      YYS( e , G[v] ){
	if( e.cap > 0 && level[e.to] < 0 ){
	  level[e.to] = level[v] + 1;
	  que.push( e.to );
	}
      }
    }
  }
  int dfs( int v , int t , int f ){
    if( v == t ) return f;
    for( int &i = iter[v]; i < G[v].size(); i++ ){
      edge &e = G[v][i];
      if( e.cap > 0 && level[v] + 1 == level[e.to] ){
	int d = dfs( e.to , t , min( f , e.cap ) );
	if( d > 0 ){
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  int max_flow( int s , int t ){
    int flow = 0;
    while( 1 ){
      bfs( s );
      if( level[t] < 0 ) return flow;
      iter = vi( n , 0 );
      int f;
      while( (f = dfs( s , t , INF )) > 0 ) flow += f;
    }
  }
};

const ll MAX_N = 512;

MaxFlow mf;

ll n, m;
vl G[MAX_N];

ll ans = INFLL;

ll check( ll c ){
  ll center_cnt = G[c].size();
  mf.init( 2*n+2 );
  
  ll s = 2*n;
  ll t = 2*n+1;
  REP( i , n ) mf.add_edge( s , i , 1 );
  REP( i , n ) mf.add_edge( n+i , t , 1 );
  REP( i , n ) if( i != c ){
    YYS( w , G[i] ){
      if( w == c ) center_cnt++;
      else mf.add_edge( i , n+w , 1 );
    }
  }

  ll rest = m - center_cnt;
  ll flow = mf.max_flow( s , t );
  return ( 2*n-1 - center_cnt ) + ( rest - flow ) + ( n-1 - flow );
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , m ){
    ll a, b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    G[a].pb( b );
  }

  REP( i , n ) chmin( ans , check( i ) );

  printf( "%lld\n" , ans );
  
  return 0;
}