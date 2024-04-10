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
ll x[MAX_N], y[MAX_N];
vi v;
bool used[MAX_N];
int dep[MAX_N];
vi G[MAX_N];
int ps[20][MAX_N];
int logn = 20;

void dfs( int x , int p , int d ){
  used[x] = true;
  dep[x] = d;
  REPR( w , G[x] ){
    if( p != w && !used[w] ){
      dfs( w , x , d+1 );
    }
  }
}
void init_lca(){
  FOR( i , 1 , logn ){
    REP( j , n ){
      if( ps[i-1][j] == -1 ) ps[i][j] = -1;
      else ps[i][j] = ps[i-1][ps[i-1][j]];
    }
  }
}
int lca( int a , int b ){
  if( dep[a] > dep[b] ) swap( a , b );
  for( int i = logn; i >= 0; i-- )
    if( (dep[b]-dep[a])&(1<<i) ) b = ps[i][b];
  if( a == b ) return a;
  for( int i = logn-1; i >= 0; i-- ){
    if( ps[i][a] != ps[i][b] ){
      a = ps[i][a];
      b = ps[i][b];
    }
  }
  return ps[0][a];
}


int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld %lld" , &x[i] , &y[i] );

  v.pb( n-1 );
  for( int i = n-2; i >= 0; i-- ){
    while( ( m = v.size() ) >= 2 ){
      int a = v[m-1], b = v[m-2];
      if( (y[a]-y[i])*(x[b]-x[i]) >= (y[b]-y[i])*(x[a]-x[i]) ) break;
      v.pop_back();
    }
    ps[0][i] = v.back();
    G[v.back()].pb( i );
    v.pb( i );
  }

  dfs( n-1 , -1 , 0 );
  init_lca();

  scanf( "%d" , &m );
  REP( i , m ){
    if( i != 0 ) printf( " " );
    int a , b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    printf( "%d" , lca( a , b ) + 1 );
  }
  printf( "\n" );
  
  return 0;
}