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
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct edge{
  int to , cap , rev;
  edge(){}
  edge( int to , int cap , int rev ) : to(to) , cap(cap) , rev(rev) {}
};

const int MAX_V = 128*10;
struct Maxflow{
  vector<edge> G[MAX_V];
  int level[MAX_V];
  int iter[MAX_V];
  
  void add_edge( int from , int to , int cap ){
    G[from].push_back( edge( to , cap , int(G[to].size()) ) );
    G[to].push_back( edge( from , 0 , int(G[from].size()-1) ) );
  }

  void bfs( int s ){
    memset( level , -1 , sizeof(level) );
    queue<int> que;
    level[s] = 0;
    que.push( s );
    while( !que.empty() ){
      int v = que.front(); que.pop();
      REP( i , G[v].size() ){
	edge &e = G[v][i];
	if( e.cap > 0 && level[e.to] < 0 ){
	  level[e.to] = level[v]+1;
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
    while(1){
      bfs(s);
      if( level[t] < 0 ) return flow;
      memset(iter,0,sizeof(iter));
      int f;
      while( (f=dfs(s,t,INF)) > 0 ){
	flow += f;
      }
    }
  }
};


const int MAX_N = 128;

int aa[MAX_N];
vpl ps[MAX_N];

vl fact( ll x ){
  vl res;
  for( ll i = 2; i*i <= x; i++ ){
    while( x % i == 0 ){
      res.pb( i );
      x /= i;
    }
  }
  if( x > 1 ) res.pb( x );
  return res;
}

vpl facts( ll x ){
  vpl res;
  vl ps = fact( x );
  REP( i , ps.size() ){
    if( i == 0 || ps[i-1] != ps[i] ) res.pb( pl( ps[i] , 1 ) );
    else res.back().se++;
  }
  return res;
}

Maxflow mf;

int main(){

  int n, m;
  cin >> n >> m;

  REP( i , n ){
    cin >> aa[i];
    ps[i] = facts( aa[i] );
  }

  int s = 10*n;
  int t = s+1;

  REP( i , n ){
    REP( j , ps[i].size() ){
      if( i % 2 == 0 ) mf.add_edge( s , i*10+j , ps[i][j].se );
      else mf.add_edge( i*10+j , t , ps[i][j].se );
    }
  }
  
  REP( i , m ){
    int a , b;
    cin >> a >> b; a--; b--;
    if( b % 2 == 0 ) swap( a , b );
    REP( j , ps[a].size() )
      REP( k , ps[b].size() )
      if( ps[a][j].fi == ps[b][k].fi )
	mf.add_edge( a*10+j , b*10+k , INF );
  }

  cout << mf.max_flow( s , t ) << endl;
  
  return 0;
}