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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n;
pl cdf[MAX_N] , cdt[MAX_N];
int hdf[MAX_N], hdt[MAX_N];
int bdf[MAX_N], bdt[MAX_N];

vector<int> as;

bool used[MAX_N*4];

int has( const string &a ){
  ll res = 0;
  YYS( w , a ) res = ( w + res * 72727 ) % MOD;
  return (int)res;
}

struct SCC{
  int n, k;
  mi G, rG;
  vi vs;
  vi cmp;
  void init( int size ){
    n = size;
    G = rG = mi( n );
    cmp = vi( n );
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    rG[b].pb( a );
    assert( G.size() < MAX_N*4 );
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
    REP( i , n ) used[i] = false;
    REP( i , n ) if( !used[i] ) dfs( i );
    REP( i , n ) used[i] = false;
    REVERSE( vs );
    k = 0;
    YYS( w , vs ) if( !used[w] ) rdfs( w ), k++;
    vs.clear();
    rG.clear();
    return k;
  }
} scc;


int m;

char cs[MAX_N*5];

pl ca[MAX_N];
int bc[MAX_N];

pl ma[MAX_N*4];

pl ss[MAX_N*4];
vector<int> G[MAX_N*4];

int hes[MAX_N];

ll ansa, ansb;

pl check( string s ){
  ll cnt = 0;
  YYS( w , s ) if( w == 'r' ) cnt++;
  return pi( cnt , s.length() );
}

pl dfs( int s ){
  if( used[s] ) return ss[s];
  used[s] = true;
  pl res = ss[s];
  YYS( w , G[s] ) chmin( res , dfs( w ) );
  return ss[s] = res;
}

int main(){

  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%s" , cs );
    int si = strlen( cs );
    REP( i , si ) if( cs[i] <= 90 ) cs[i] += 32;
    hes[i] = has( cs );
    ca[i] = check( cs );
    as.pb( hes[i] );
  }

  scanf( "%d" , &n );

  REP( i , n ){
    scanf( "%s" , cs );
    int si = strlen( cs );
    REP( i , si ) if( cs[i] <= 90 ) cs[i] += 32;
    hdf[i] = has( cs );    
    cdf[i] = check( cs );
    as.pb( hdf[i] );    
    scanf( "%s" , cs );
    si = strlen( cs );
    REP( i , si ) if( cs[i] <= 90 ) cs[i] += 32;
    hdt[i] = has( cs );
    cdt[i] = check( cs );
    as.pb( hdt[i] );
  }

  assert( as.size() < MAX_N*4 );  

  
  SORT( as );
  as.erase( unique( ALL(as) ) , as.end() );
  scc.init( as.size() );
  
  REP( i , n ){
    bdf[i] = lower_bound( ALL(as) , hdf[i] ) - as.begin();
    bdt[i] = lower_bound( ALL(as) , hdt[i] ) - as.begin();
    scc.add_edge( bdf[i] , bdt[i] );
  }

  REP( i , m ){
    bc[i] = lower_bound( ALL(as) , hes[i] ) - as.begin();
    ma[bc[i]] = ca[i];
  }

  as.clear();

  int sn = scc.scc();
  REP( i , sn ) ss[i] = pi( INF , INF );

  REP( i , MAX_N*4 ) used[i] = false;

  assert( sn < MAX_N * 4 );

  int cntt = 0;
  REP( i , n ){
    chmin( ss[scc.cmp[bdf[i]]] , cdf[i] );
    if( !used[bdf[i]] ) YYS( w , scc.G[bdf[i]] ) G[scc.cmp[bdf[i]]].pb( scc.cmp[w] );
    used[bdf[i]] = true;
  }
  REP( i , n ){
    chmin( ss[scc.cmp[bdt[i]]] , cdt[i] );
    if( !used[bdt[i]] )YYS( w , scc.G[bdt[i]] ) G[scc.cmp[bdt[i]]].pb( scc.cmp[w] );
    used[bdt[i]] = true;    
  }

  REP( i , MAX_N*4 ) used[i] = false;

  REP( i , sn ) if( !used[i] ) dfs( i );
    
  REP( i , n ){
    chmin( ma[bdf[i]] , ss[scc.cmp[bdf[i]]] );
  }

  REP( i , m ){
    ansa += ma[bc[i]].fi;
    ansb += ma[bc[i]].se;
  }

  cout << ansa << " " << ansb << endl;
  
  return 0;
}