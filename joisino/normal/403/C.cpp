#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
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

struct SCC{
  int n, k;
  mi G, rG;
  vi vs;
  vb used;
  vi cmp;
  void init( int size ){
    n = size;
    G = rG = mi( n );
    cmp = vi( n );
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    rG[b].pb( a );
  }
  void dfs( int x ){
    used[x] = true;
    YYS( w , G[x] ) if( !used[w] ) dfs( w );
    vs.pb( x );
  }
  void rdfs( int x ){
    used[x] = true;
    cmp[x] = k;
    YYS( w , rG[x] ) if( !used[w] ) rdfs( w );
  }
  int scc(){
    used = vb( n , false );
    REP( i , n ) if( !used[i] ) dfs( i );
    used = vb( n , false );
    REVERSE( vs );
    k = 0;
    YYS( w , vs ) if( !used[w] ) rdfs( w ), k++;
    return k;
  }
};

SCC scc;
int n, a;

int main(){

  scanf( "%d" , &n );
  scc.init( n );
  REP( i , n ) REP( j , n ){
    scanf( "%d" , &a );
    if( a >= 1 ) scc.add_edge( i , j );
  }

  if( scc.scc() == 1 ) puts( "YES" );
  else puts( "NO" );
  
  return 0;
}