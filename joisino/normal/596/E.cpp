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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct SCC{
  int n, k;
  mi G, rG;
  vi vs, cmp;
  vb used;
  void init( int size ){
    n = size;
    G = rG = mi( n , vi(0) );
    cmp = vi( n );
    vs.clear();
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
    REVERSE( vs );
    k = 0;
    used = vb( n , false );
    YYS( w , vs ) if( !used[w] ) rdfs( w ), k++;
    return k;
  }
};

const int MAX_N = 210;

int n, m, q;
char field[MAX_N][MAX_N];
int dx[10], dy[10];

SCC scc;

vi G[MAX_N*MAX_N];
bool contain[MAX_N*MAX_N][10];
char val[MAX_N*MAX_N];

bool isroot[MAX_N*MAX_N];

char s[1000010];

int len;

bool dfs( int x , int p ){
  if( p >= 0 && val[x] == s[p] ) p--;
  if( p == -1 ) return true;
  YYS( w , G[x] ) if( dfs( w , p ) ) return true;
  return false;
}

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

int p( int y , int x ){
  return y * m + x;
}

int main(){

  scanf( "%d %d %d" , &n , &m , &q );
  REP( i , n ) scanf( "%s" , field[i] );
  
  REP( i , 10 ) scanf( "%d %d" , &dy[i] , &dx[i] );

  scc.init( n * m );
  REP( i , n ) REP( j , m ){
    int k = field[i][j] - '0';
    if( isin( i + dy[k] , j + dx[k] ) ) scc.add_edge( p(i,j) , p(i+dy[k],j+dx[k]) );
  }

  int k = scc.scc();
  REP( i , k ) isroot[i] = true;
  REP( i , n*m ) YYS( w , scc.rG[i] ) if( scc.cmp[w] != scc.cmp[i] ){
    G[ scc.cmp[i] ].pb( scc.cmp[w] );
    isroot[ scc.cmp[w] ] = false;
  }

  REP( i , n ) REP( j , m ){
    contain[ scc.cmp[p(i,j)] ][ field[i][j] - '0' ] = true;
    val[ scc.cmp[p(i,j)] ] = field[i][j];
  }

  REP( query_cnt , q ){
    scanf( "%s" , s );
    len = strlen( s );

    bool ok = false;
    REP( i , k ) if( isroot[i] ){
      int it = len-1;
      while( it >= 0 && contain[i][s[it]-'0'] ) it--;
      if( dfs( i , it ) ){
	ok = true;
	break;
      }
    }
    if( ok ) printf( "YES\n" );
    else printf( "NO\n" );
  }
  
  return 0;
}