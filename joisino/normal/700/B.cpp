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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n, k;

vi G[200010];

ll cnt[200010];
ll sz[200010];

ll ans = 0;

void dfs2( int x, int p, ll fr ){
  // cout << x << " " << fr << endl;
  ans += fr;
  vpl v(0);
  YYS( w , G[x] ){
    if( w != p ){
      v.pb( sz[w], w );
    }
  }
  if( SZ(v) == 0 ){
    return;
  }
  SORT( v );
  ll res = sz[x]-fr;
  assert( res >= 0 );
  ll mares = v.back().fi-fr;
  if( mares * 2 > res ){
    int to = v.back().se;
    dfs2( to, x, sz[to]-(mares*2-res) );
    v.pop_back();
  }
  YYS( w , v ){
    dfs2( w.se, x, sz[w.se] );
  }
}

ll dfs( int x, int p ){
  sz[x] = cnt[x];
  YYS( w , G[x] ){
    if( w != p ){
      sz[x] += dfs( w, x );
    }
  }
  return sz[x];
}

int main(){

  n = in();
  k = in();
  REP( i , k*2 ){
    int a = in() - 1;
    cnt[a]++;
  }
  REP( i , n-1 ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0, -1 );
  dfs2( 0 , -1 , 0 );

  printf( "%lld\n", ans );
  
  return 0;
}