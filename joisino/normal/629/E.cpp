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

int n, m;

vi G[100010];

ll dep[100010], sz[100010], sum[100010], dist[100010];

int par[20][100010];

void dfsa( int x , int p , int d ){
  par[0][x] = p;
  dep[x] = d;
  sz[x] = 1;
  YYS( w , G[x] ) if( w != p ){
    dfsa( w , x , d+1 );
    sz[x] += sz[w];
    sum[x] += sum[w] + sz[w];
  }
}

void dfsb( int x , int p , ll fr ){
  dist[x] = sum[x] + fr;
  YYS( w , G[x] ) if( w != p ){
    dfsb( w , x , dist[x] - sum[w] - sz[w] + ( n - sz[w] ) );
  }
}

void init(){
  FOR( i , 1 , 20 ) REP( j , n ){
    if( par[i-1][j] == -1 ) par[i][j] = -1;
    else par[i][j] = par[i-1][ par[i-1][j] ];
  }
}

int lca( int a , int b ){
  if( dep[a] > dep[b] ) swap( a , b );
  REP( i , 20 ) if( ( dep[b] - dep[a] ) & PW(i) ) b = par[i][b];
  if( a == b ) return a;
  for( int i = 19; i >= 0; i-- ){
    int pa = par[i][a];
    int pb = par[i][b];
    if( pa != pb ){
      a = pa;
      b = pb;
    }
  }
  return par[0][a];
}

int ch( int a , int b ){
  if( dep[a] > dep[b] ) swap( a , b );
  int sa = dep[b] - dep[a] - 1;
  REP( i , 20 ) if( sa & PW(i) ) b = par[i][b];
  return b;
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfsa( 0 , -1 , 0 );
  dfsb( 0 , -1 , 0 );

  init();

  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    if( dep[a] > dep[b] ) swap( a , b );
    int l = lca( a , b );
    
    ll sza, suma;
    ll szb = sz[b];
    ll sumb = sum[b];
    if( l == a ){
      int c = ch( a , b );
      sza = n - sz[c];
      suma = dist[a] - ( sum[c] + sz[c] );
    } else {
      sza = sz[a];
      suma = sum[a];
    }

    // cout << a << " " << b << " " << sza << " " << suma << " " << szb << " " << sumb << endl;
    
    ll len = dep[a] + dep[b] - 2 * dep[l];
    double com = double(sza) * double(szb);
    double tot = double(szb) * double(suma) + double(sza) * double(sumb);
    double ans = 1 + len + tot / com;
    printf( "%.18lf\n" , ans );
  }

  return 0;
}