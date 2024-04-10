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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

int n;
mi G(100010);

vpi ns;
mi nG(100010);


int dfs( int x , int p ){
  int id = SZ(ns);
  ns.pb( x , p );

  YYS( w , G[x] ) if( w != p ){
    nG[id].pb( dfs( w , x ) );
  }
  
  return id;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  int root = -1;
  REP( i , n ) if( SZ(G[i]) == 1 ) root = i;
  YYS( w , G[root] ) dfs( w , root );

  printf( "%lld\n" , SZ(ns) );
  YYS( w , ns ) printf( "2 %d %d\n" , w.fi+1 , w.se+1 );
  REP( i , SZ(ns) ) YYS( w , nG[i] ) printf( "%lld %d\n" , i+1 , w+1 );
  
  return 0;
}