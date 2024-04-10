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

struct EulerTour{
  int n;
  mi G;
  vi in, out, sz, dep;
  int cnt;
  void init( int size ){
    n = size;
    G = mi( n , vi(0) );
    in = out = sz = dep = vi(n);
    cnt = 0;
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    G[b].pb( a );
  }
  int dfs( int x , int p = -1 , int d = 0 ){
    in[x] = cnt++;
    sz[x] = 1;
    dep[x] = d;
    YYS( w , G[x] ) if( w != p ) sz[x] += dfs( w , x , d+1 );
    out[x] = cnt;
    return sz[x];
  }
};

struct BIT{
  vi node;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vi( size , 0 );
  }
  void add( int k , int x ){
    for( int i = k+1; i <= size; i += i & -i ) node[i-1] += x;
  }
  int sum( int k ){ // [0,k)
    int res = 0;
    for( int i = k; i > 0; i -= i & -i ) res += node[i-1];
    return res;
  }
};

const int MAX_N = 100010;

int n, m;
vi G[MAX_N];

vi v[MAX_N];

EulerTour et;
vi in, out;
vi sz;

BIT used, bit;

int ans[MAX_N];

void dfs( int x , int p ){
  vpi his(0);
  YYS( w , v[x] ){
    if( used.sum( in[w]+1 ) == 0 ){
      int add = sz[w] - ( bit.sum( out[w] ) - bit.sum( in[w] ) );
      bit.add( in[w] , add );
      used.add( out[w] , -1 );
      used.add( in[w] , 1 );
      his.pb( w , add );
    }
  }
  ans[x] = max( 0 , bit.sum( n ) - 1 );
  YYS( w , G[x] ) if( w != p ) dfs( w , x );
  YYS( w , his ){
    bit.add( in[w.fi] , -w.se );
    used.add( out[w.fi] , 1 );
    used.add( in[w.fi] , -1 );
  }
}

int main(){

  scanf( "%d %d" , &n , &m );

  et.init( n );
  
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
    et.add_edge( a , b );
  }

  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    v[a].pb( b );
    v[a].pb( a );
    v[b].pb( a );
    v[b].pb( b );
  }
  
  et.dfs( 0 );
  in = et.in, out = et.out;
  sz = et.sz;

  // REP( i , n ) cout << in[i] << " " << out[i] << " " << sz[i] << endl;
  
  bit.init( n );
  used.init( n );
  dfs( 0 , -1 );
  
  REP( i , n ) printf( "%d%c" , ans[i] , i==n-1?'\n':' ' );

  return 0;
}