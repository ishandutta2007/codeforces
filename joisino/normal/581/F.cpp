#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 5010;

int n, r;
vi G[MAX_N];
int dp[MAX_N][MAX_N];
int s[MAX_N];

void dfs( int x , int p ){
  if( G[x].size() == 1 ) s[x] = 1;
  dp[x][0] = 0;
  YYS( w , G[x] ) if( w != p ){
    dfs( w , x );

    FOR( i , s[x]+1 , s[x]+s[w]+1 ) dp[x][i] = INF;
    for( int i = s[x]; i >= 0; i-- ) REP( j , s[w]+1 ) chmin( dp[x][i+j] , dp[x][i] + dp[w][j] );
    
    s[x] += s[w];
  }
  dp[x][ s[x] ] = 1;
  REP( i , s[x]+1 ){
    if( x == r ) chmin( dp[x][i] , dp[x][s[x]-i]  );
    else chmin( dp[x][i] , dp[x][s[x]-i] + 1 );
  }
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) if( G[i].size() >= 2 ){
    r = i;
    dfs( i , -1 );
    break;
  }

  printf( "%d\n" , dp[r][s[r]/2] );
  
  return 0;
}