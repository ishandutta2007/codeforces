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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 1000010;

ll n;

vi G[MAX_N];
ll sz[MAX_N];

ll ans;

ll dfs( int x , int p ){
  sz[x] = 1;
  YYS( w , G[x] ) if( w != p ) sz[x] += dfs( w , x );
  
  ll down = sz[x] * ( sz[x] - 1 ) / 2;
  YYS( w , G[x] ) if( w != p ) down -= sz[w] * ( sz[w] - 1 ) / 2;
  ll up = sz[x] * ( n - sz[x] );
  ans -= down * down + 2 * down * up;
  
  return sz[x];
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  ans = sq( n * (n-1) / 2 );

  dfs( 0 , -1 );

  printf( "%lld\n" , ans );
  
  return 0;
}