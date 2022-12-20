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

const int MAX_N = 200010;
const int LG = 18;

int n, m, k;
vi G[MAX_N];

vi nG[MAX_N];

vi v;
bool used[MAX_N];

int vcnt;
int id[MAX_N];

int sz[MAX_N];
int val[MAX_N];

int par[LG][MAX_N];
int ndep[MAX_N];

ll e[MAX_N];

void dfs( int x , int p ){
  used[x] = true;
  v.pb( x );
  
  YYS( w , G[x] ) if( w != p ){
    if( !used[w] ){
      dfs( w , x );
    } else if( id[x] == -1 ){
      for( int i = SZ(v)-1; i >= 0; i-- ){
	id[ v[i] ] = vcnt;
	sz[ vcnt ]++;
	if( v[i] == w ) break;
      }
      vcnt++;
    }
  }
  
  if( id[x] == -1 ) sz[vcnt] = 1, id[x] = vcnt++;
  v.pop_back();
}

void dfs2( int x , int p , int cur , int d ){
  if( sz[x] > 1 ) cur++;
  val[x] = cur;
  par[0][x] = p;
  ndep[x] = d;
  YYS( w , nG[x] ) if( w != p ) dfs2( w , x , cur , d+1 );
}

void initlca(){
  FOR( i , 1 , LG ) REP( j , vcnt ){
    if( par[i-1][j] == -1 ) par[i][j] = -1;
    else par[i][j] = par[i-1][ par[i-1][j] ];
  }
}

int lca( int a , int b ){
  if( ndep[a] > ndep[b] ) swap( a , b );
  int dif = ndep[b] - ndep[a];
  REP( i , LG ) if( dif & PW(i) ) b = par[i][b];
  if( a == b ) return a;
  for( int i = LG-1; i >= 0; i-- ){
    if( par[i][a] != par[i][b] ){
      a = par[i][a];
      b = par[i][b];
    }
  }
  return par[0][a];
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) id[i] = -1;

  dfs( 0 , -1 );

  REP( i , n ) YYS( w , G[i] ) if( id[i] != id[w] ){
    nG[ id[i] ].pb( id[w] );
  }

  /*
  REP( i , n ) cout << i+1 << " " << id[i] << endl;
  
  REP( i , vcnt ){
    cout << i << " : ";
    YYS( w , nG[i] ) cout << w << " ";
    cout << endl;
  }
  */

  dfs2( 0 , -1 , 0 , 0 );

  initlca();

  e[0] = 1;
  FOR( i , 1 , MAX_N ) e[i] = ( e[i-1] * 2 ) % MOD;

  scanf( "%d" , &k );
  REP( query_cnt , k ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    int l = lca( id[a] , id[b] );
    int res = val[ id[a] ] + val[ id[b] ] - 2 * val[l];
    if( sz[l] > 1 ) res++;
    printf( "%lld\n" , e[res] );
  }
  
  return 0;
}