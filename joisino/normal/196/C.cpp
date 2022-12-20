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

const int MAX_N = 3010;

int n;
int x[MAX_N], y[MAX_N];

vi G[MAX_N];
int sz[MAX_N];

int ans[MAX_N];

int v[MAX_N];
ld rad[MAX_N];

int piv;
void calcrad( int l , int r ){
  FOR( i , l , r ){
    int xa = x[v[i]] - x[piv], ya = y[v[i]] - y[piv];
    rad[v[i]] = atan2l( ya , xa );
  }
}

bool cmp( int a , int b ){
  return rad[a] < rad[b];
}

bool cmp2( int a , int b ){
  return x[a] + y[a] < x[b] + y[b];
}

int dfs( int x , int p ){
  sz[x] = 1;
  YYS( w , G[x] ) if( w != p ) sz[x] += dfs( w , x );
  return sz[x];
}

void dfs2( int x , int p , int l , int r ){
  sort( v+l , v+r , cmp2 );
  ans[ v[l] ] = x;
  piv = v[l];
  l++;
  calcrad( l , r );
  sort( v+l , v+r , cmp );
  //cout << "* " <<  x+1 << " " << l << " " << r << endl;
  //FOR( i , l , r ) cout << v[i]+1 << " ";
  //cout << endl;
  int it = 0;
  YYS( w , G[x] ) if( w != p ){
    dfs2( w , x , l+it , l+it+sz[w] );
    it += sz[w];
  }
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );

  REP( i , n ) scanf( "%d %d" , &x[i] , &y[i] );

  REP( i , n ) v[i] = i;
  dfs2( 0 , -1 , 0 , n );

  REP( i , n ) printf( "%d%c" , ans[i]+1 , i==n-1?'\n':' ' );
  
  return 0;
}