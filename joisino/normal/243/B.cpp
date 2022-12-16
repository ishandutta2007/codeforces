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

vi G[MAX_N];
vpi es;

int n, m, h, t;
int a, b;

bool used[MAX_N];
bool used2[MAX_N];

int ans( int u , int v ){
  printf( "YES\n" );
  printf( "%d %d\n" , u+1 , v+1 );
  YYS( w , G[u] ) used[w] = true;
  vi anst, ansh;
  YYS( w , G[v] ) if( w != u && !used[w] && anst.size() < t ){
    anst.pb( w );
  }
  YYS( w , G[v] ) if( w != u && used[w] && anst.size() < t ){
    anst.pb( w );
    used2[w] = true;
  }
  YYS( w , G[u] ) if( w != v && !used2[w] && ansh.size() < h ){
    ansh.pb( w );
  }
  REP( i , h ) printf( "%d%c" , ansh[i]+1 , i==h-1?'\n':' ' );
  REP( i , t ) printf( "%d%c" , anst[i]+1 , i==t-1?'\n':' ' );
  return 0;
}

int main(){

  scanf( "%d %d %d %d" , &n , &m , &h , &t );
  REP( i , m ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
    es.pb( a , b );
    es.pb( b , a );
  }

  YYS( w , es ){
    int u = w.fi;
    int v = w.se;
    if( G[u].size() < h+1 || G[v].size() < t+1 ) continue;
    if( G[u].size() >= h+t+1 ) return ans( u , v );
    if( G[v].size() >= h+t+1 ) return ans( u , v );
    YYS( w , G[u] ) used[w] = true;
    int cntt = 0;
    YYS( w , G[v] ) if( w != u && !used[w] ) cntt++;
    int co = G[v].size() - 1 - cntt;
    int cnth = G[u].size() - 1 - co;
    YYS( w , G[u] ) used[w] = false;    
    if( cntt + co >= t && cnth + co - max(0,t-cntt) >= h ) return ans( u , v );
  }

  puts( "NO" );
  
  return 0;
}