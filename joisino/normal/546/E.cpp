#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb emplace_back
 
using namespace std;
 
typedef int64_t ll;
typedef long double ld;
 
const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-9;
 
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

typedef pair<int,int> P;
#define fi first
#define se second

const int MAX_V = 310;
struct edge{ int to , cap , rev; };
struct Maxflow{
  vector<edge> G[MAX_V];
  bool used[MAX_V];
 
  P add_edge( int from , int to , int cap ){
    G[from].push_back( (edge){ to , cap , int(G[to].size()) } );
    G[to].push_back( (edge){ from , 0 , int(G[from].size()-1) } );
    return P( to , G[to].size()-1 );
  }
 
  int dfs( int v , int t , int f ){
    if( v == t ) return f;
    used[v] = true;
    for( int i = 0; i < G[v].size(); i++ ){
      edge &e = G[v][i];
      if( !used[e.to] && e.cap > 0 ){
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
      memset( used , 0 , sizeof( used ) );
      int f = dfs( s , t , INF );
      if( f == 0 ) return flow;
      flow += f;
    }
  }
};
 
 
const int MAX_N = 310;
const P INI = P( -1 , -1 );
 
Maxflow mf;
int a[MAX_N];
int b[MAX_N];
 
bool f[MAX_N][MAX_N];
 
P G[MAX_N][MAX_N];

int main(){
 
  int n, m;
  cin >> n >> m;
  int s = 2*n;
  int t = s+1;
 
  REP( i , n )
    cin >> a[i];
 
  REP( i , n )
    cin >> b[i];
 
  int sum = 0;
  REP( i , n )
    sum += b[i];

  int suma = 0;
  REP( i , n )
    suma += a[i];


  REP( i , n )
    REP( j , n )
    G[i][j] = INI;
 
  REP( i , m ){
    int c, d;
    cin >> c >> d; c--; d--;
    if( f[c][d] ) continue;
    f[c][d] = f[d][c] = true;
    G[c][d] = mf.add_edge( c , n+d , INF );
    G[d][c] = mf.add_edge( d , n+c , INF );
  }
 
  REP( i , n )
    G[i][i] = mf.add_edge( i , n+i , INF );
 
  REP( i , n )
    mf.add_edge( s , i , a[i] );
 
  REP( i , n )
    mf.add_edge( n+i , t , b[i] );
  
  if( mf.max_flow( s , t ) == sum && sum == suma ){
    
    cout << "YES" << endl;
    REP( i , n ){
      REP( j , n ){
	if( j != 0 ) cout << " ";
	if( G[i][j] != INI ) cout << mf.G[G[i][j].fi][G[i][j].se].cap;
	else cout << 0;
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
 
  return 0;
}