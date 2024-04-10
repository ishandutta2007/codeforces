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

int n;

int a[5010], b[5010], c[5010];
vpi G[5010];

ll tot;

ll sz[5010], s[5010], t[5010];

void build( int id ){
  REP( i , n ) G[i].clear();
  REP( i , n-1 ) if( i != id ){
    G[ a[i] ].pb( b[i], c[i] );
    G[ b[i] ].pb( a[i], c[i] );
  }
}

ll dfs2( int x, int p, ll u, int size ){
  t[x] = s[x] + u;
  YYS( w , G[x] ) if( w.fi != p ){
    dfs2( w.fi, x, t[x] - ( s[w.fi] + sz[w.fi] * w.se ) + ( size - sz[w.fi] ) * w.se, size );
  }
}

void dfs( int x, int p ){
  sz[x] = 1;
  s[x] = 0;
  YYS( w , G[x] ) if( w.fi != p ){
    dfs( w.fi, x );
    sz[x] += sz[w.fi];
    s[x] += s[w.fi] + sz[w.fi] * w.se;
  }
}

ll calc( int id ){
  REP( i , n ) t[i] = INFLL;
  dfs( a[id], -1 );
  dfs2( a[id], -1, 0, sz[ a[id] ] );
  ll mia = INFLL;
  REP( i , n ) if( t[i] < mia ) mia = t[i];
  ll resa = t[ a[id] ] - mia;

  REP( i , n ) t[i] = INFLL;
  dfs( b[id], -1 );
  dfs2( b[id], -1, 0, sz[ b[id] ] );
  ll mib = INFLL;
  REP( i , n ) if( t[i] < mib ) mib = t[i];
  ll resb = t[ b[id] ] - mib;
  
  return tot / 2 - sz[ a[id] ] * resb - sz[ b[id] ] * resa;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    scanf( "%d %d %d" , &a[i], &b[i], &c[i] ); a[i]--; b[i]--;
  }

  build( -1 );
  dfs( 0, -1 );
  dfs2( 0, -1, 0, n );
  REP( i , n ) tot += t[i];

  ll ans = tot / 2;
  REP( i , n-1 ){
    build( i );
    chmin( ans , calc(i) );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}