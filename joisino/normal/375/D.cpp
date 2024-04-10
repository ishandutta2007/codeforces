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

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n, m;
int c[MAX_N];
map<int,int> a[MAX_N];
vi b[MAX_N];
vi G[MAX_N];
vpi q[MAX_N];
int ans[MAX_N];

void add( int x , int y , int v ){
  //cout << x << " " << y << " " << v << endl;
  REP( i , v ){
    a[x][y]++;
    while( b[x].size() <= a[x][y] ) b[x].resize( b[x].size()*2 , 0 );
    b[x][ a[x][y] ]++;
  }
}

int dfs( int x , int p ){
  vi v( 1 , x );
  int base = x;
  YYS( w , G[x] ){
    if( w != p ){
      int res = dfs( w , x );
      v.pb( res );
      if( a[res].size() >= a[base].size() ) base = res;
    }
  }

  YYS( w , v )
    if( w != base )
      for( auto ite = a[w].begin(); ite != a[w].end(); ite++ )
	add( base , ite->fi , ite->se );

  YYS( w , q[x] )
    if( b[base].size() > w.fi ) ans[ w.se ] = b[base][w.fi];

  return base;
}

int x, y;

int main(){
  
  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &c[i] );
  REP( i , n-1 ){
    scanf( "%d %d" , &x , &y ); x--; y--;
    G[x].pb( y );
    G[y].pb( x );
  }

  REP( i , m ){
    scanf( "%d %d" , &x , &y ); x--;
    q[x].pb( y , i );
  }

  REP( i , n ) b[i].resize( 1 , 0 );
  REP( i , n ) add( i , c[i] , 1 );

  dfs( 0 , -1 );

  REP( i , m ) cout << ans[i] << endl;
  
  return 0;
}