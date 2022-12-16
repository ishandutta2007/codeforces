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


#define PREV(P,i) P[(i-1+SZ(P))%SZ(P)]
#define CURR(P,i) P[i]
#define NEXT(P,i) P[(i+1)%SZ(P)]

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

const ll MAX_N = 200010;

ll n, m;
vl G[MAX_N];
ll low[MAX_N];
ll checked[MAX_N];
bool yuyu[MAX_N];
bool used[MAX_N];
bool f;
ll cnt;
ll tp;

ll d[MAX_N];

vl to[MAX_N];

bool ans;

set<ll> ss;

vl v, cv, pa, qa, qb;

void answer( vl a , vl b , vl c ){
  if( ans ) return;
  ans = true;

  printf( "YES\n" );
  
  printf( "%lld" , SZ(a) );
  YYS( w , a ) printf( " %lld" , w+1 );
  printf( "\n" );

  printf( "%lld" , SZ(b) );
  YYS( w , b ) printf( " %lld" , w+1 );
  printf( "\n" );

  printf( "%lld" , SZ(c) );
  YYS( w , c ) printf( " %lld" , w+1 );
  printf( "\n" );
}

void dfs3( ll x , ll p , ll r ){
  yuyu[x] = true;
  if( x != r && ss.find( x ) != ss.end() ){
    f = true;
    pa.pb( x );    
    return;
  }
  YYS( w , to[x] ) if( !yuyu[w] && !f ) dfs3( w , x , r );
  if( f ) pa.pb( x );
}

void dfs2( ll x , ll p , ll r , ll c ){
  cv.pb( x );
  to[x].pb( p );
  if( x == r ) return;
  checked[x] = c;

  YYS( w , G[x] ) if( w != p && checked[w] >= c ){
    to[x].pb( w );
    if( checked[w] == INFLL ) dfs2( w , x , r , c );
  }
}

void dfs4( ll x , ll p , ll r ){
  yuyu[x] = true;
  
  if( x == r ){
    f = true;
    v.pb( x );
    return;
  }
  
  YYS( w , to[x] ) if( w != p && !yuyu[w] && !f ) dfs4( w , x , r );

  if( f ) v.pb( x );
}

void check( ll x , ll r , ll c ){
  v.clear();
  cv.clear();
  cv.pb( r );
  
  to[r].pb( x );
  dfs2( x , r , r , c );

  f = false;
  YYS( w , cv ) yuyu[w] = false;
  dfs4( x , r , r );

  tp = -1;
  YYS( w , v ) if( SZ(to[w]) >= 3 ) tp = w;

  if( tp != -1 ){
    ss.clear();
    YYS( w , v ) ss.insert( w );
    
    ll id = -1;
    REP( i , SZ(v) ) if( v[i] == tp ) id = i;
    
    pa.clear();
    f = false;
    YYS( w , to[tp] ) if( w != PREV( v , id ) && w != NEXT( v , id ) ){
      YYS( w , cv ) yuyu[w] = false;
      yuyu[tp] = true;
      dfs3( w , tp , tp );
      pa.pb( tp );
      REVERSE( pa );
      break;
    }
    if( !f ){
      cout << "cycle : " << SZ(v) << " , component : " << SZ(cv) << endl;
      cout << "turn : " << tp+1 << endl;
      YYS( w , v ) cout << w+1 << " ";
      cout << endl;
      YYS( w , cv ) cout << w+1 << " ";
      cout << endl;
      assert( false );
    }
    qa.clear();
    qb.clear();
    ll p = id;
    while( 1 ){
      qa.pb( v[p] );
      if( v[p] == pa.back() ) break;
      p++;
      if( p == SZ(v) ) p = 0;
    }
    while( 1 ){
      qb.pb( v[p] );
      if( p == id ) break;
      p++;
      if( p == SZ(v) ) p = 0;      
    }
    REVERSE( qb );
    answer( pa , qa , qb );
  }

  YYS( w , cv ) to[w].clear();
}

void dfs( ll x , ll p ){
  d[x] = d[p] + 1;
  low[x] = d[x];
  used[x] = true;
  YYS( w , G[x] ){
    if( !used[w] ){
      dfs( w , x );
      chmin( low[x] , low[w] );

      if( low[w] >= d[x] ) check( w , x , ++cnt );
      
    } else if( w != p ){
      chmin( low[x] , d[w] );
    }
  }
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , m ){
    ll a, b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) checked[i] = INFLL;

  REP( r , n ) if( !used[r] ) {
    used[r] = true;
    YYS( w , G[r] ) if( !used[w] ){
      low[w] = 1;
      dfs( w , r );
      check( w , r , ++cnt );
    }
  }

  if( !ans ) printf( "NO\n" );
  
  return 0;
}