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

const int MAX_N = 5010;

int n;
vi G[MAX_N];
int sz[MAX_N];

bool dp[MAX_N], ansf[MAX_N];

vi ans;

void append( int x ){
  for( ll i = MAX_N - x - 1; i >= 0; i-- ) dp[i+x] |= dp[i];
}

int dfs( int x , int p ){
  sz[x] = 1;
  YYS( w , G[x] ) if( w != p ) sz[x] += dfs( w , x );
  
  REP( i , MAX_N ) dp[i] = false;
  dp[0] = true;
  
  YYS( w , G[x] ) if( w != p ) append( sz[w] );
  append( n - sz[x] );
  
  REP( i , MAX_N ) ansf[i] |= dp[i];
  
  return sz[x];
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );

  FOR( i , 1 , n-1 ) if( ansf[i] ) ans.pb( i );
  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%d %d\n" , w , n-1-w );
  
  return 0;
}