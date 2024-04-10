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

const int MAX_N = 100010;

int n;
int c[MAX_N];

vi G[MAX_N];

unordered_map<int,int> mp[MAX_N];
ll tot[MAX_N];
int mav[MAX_N], id[MAX_N];
ll ans[MAX_N];

void dfs( int x , int p ){
  mp[x][ c[x] ]++;
  id[x] = x;
  mav[x] = 1;
  tot[x] = c[x];
  
  YYS( ch , G[x] ) if( ch != p ){
    dfs( ch , x );
    
    int fr = id[ ch ];
    if( SZ(mp[fr]) > SZ(mp[id[x]]) ) swap( fr , id[x] );

    YYS( w , mp[fr] ){
      mp[ id[x] ][ w.fi ] += w.se;
      if( mp[ id[x] ][ w.fi ] > mav[ id[x] ] ) mav[ id[x] ] = mp[ id[x] ][ w.fi ], tot[ id[x] ] = w.fi;
      else if( mp[ id[x] ][ w.fi ] == mav[ id[x] ] ) tot[ id[x] ] += w.fi;
    }
    mp[fr].clear();
  }
  
  ans[x] = tot[ id[x] ];
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &c[i] );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );

  REP( i , n ) printf( "%lld%c" , ans[i] , i==n-1?'\n':' ' );
  
  return 0;
}