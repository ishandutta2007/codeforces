#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n, m;
int a, b;
vpi G[MAX_N];
bool used[MAX_N], usede[MAX_N];

int dfs( int x ){
  used[x] = true;
  int y = -1;
  REPR( e , G[x] ){
    int to = e.fi, id = e.se;
    if( usede[id] ) continue;
    usede[id] = true;
    if( !used[to] ){
      int ret = dfs( to );
      if( ret != -1 ){
	printf( "%d %d %d\n" , ret , to , x );
	continue;
      }
    }
    if( y == -1 ) y = to;
    else printf( "%d %d %d\n" , y , x , to ), y = -1;
  }
    return y;
}

int main(){

  scanf( "%d %d" , &n , &m );
  if( m % 2 == 1 ) return puts( "No solution" );
  
  REP( i , m ){
    scanf( "%d %d" , &a , &b );
    G[a].pb( b , i );
    G[b].pb( a , i );
  }

  dfs( 1 );

  return 0;
}