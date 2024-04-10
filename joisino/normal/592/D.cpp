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
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Diameter{
  mi G;
  void init( int n ){
    G.clear();
    G.resize( n , vi(0) );
  }
  void add_edge( int a , int b ){
    G[a].pb( b );
    G[b].pb( a );
  }
  pi dfs( int x , int p ){
    pi res = pi( 0 , x );
    YYS( w , G[x] ) if( w != p ){
      pi ret = dfs( w , x );
      ret.fi++;
      if( res.fi < ret.fi ) res = ret;
      else if( res.fi == ret.fi && res.se > ret.se ) res = ret;
    }
    return res;
  }
  pi diameter( int x ){
    pi resf = dfs( x , -1 );
    pi ress = dfs( resf.se , -1 );
    return pi( ress.fi , min( resf.se , ress.se ) );
  }
};

const int MAX_N = 200010;

int n, m;
vi G[MAX_N];
bool is_attacked[MAX_N];

Diameter dia;

int root;
int cnt;

bool dfs( int x , int p ){
  bool res = is_attacked[x];
  YYS( w , G[x] ) if( w != p ){
    if( dfs( w , x ) ){
      dia.add_edge( x , w );
      cnt++;
      res = true;
    }
  }
  return res;
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n-1 ){
    int x, y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    G[x].pb( y );
    G[y].pb( x );
  }

  dia.init( n );

  REP( i , m ){
    int a;
    scanf( "%d" , &a ); a--;
    is_attacked[a] = true;
    root = a;
  }

  dfs( root , -1 );

  pi res = dia.diameter( root );
  
  printf( "%d\n" , res.se+1 );
  printf( "%d\n" , cnt*2-res.fi );
  
  return 0;
}