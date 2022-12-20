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

const int MAX_N = 300010;

int n, m;

typedef pair<int,pi> pii;
pii edge[MAX_N];

int ndp[MAX_N];
int dp[MAX_N];

int ans;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ) scanf( "%d %d %d" , &edge[i].se.fi , &edge[i].se.se , &edge[i].fi );
  sort( edge , edge+m );

  int p = 0;
  while( p < m ){
    int curw = edge[p].fi;
    int st = p;
    while( p < m && edge[p].fi == curw ) p++;
    FOR( i , st , p ) chmax( ndp[ edge[i].se.se ]  , dp[ edge[i].se.fi ] + 1 );
    FOR( i , st , p ) chmax( dp[ edge[i].se.se ] , ndp[ edge[i].se.se ] );
  }

  REP( i , MAX_N ) chmax( ans , dp[i] );

  printf( "%d\n" , ans );
  
  return 0;
}