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


const ll SEG_INIT = 1e18; // MIN
const ll SEG_NONE = 1e18; // MIN
template<typename T>
struct Segtree{
  vector<T> node;
  vi idnode;
  int size;
  bool com( T a , T b ){
    return a < b; // MIN
  }
  T cho( T a , T b ){
    return com( a , b ) ? a : b;
  }
  void init( const vector<T> &a ){
    size = 1;
    while( size < a.size() ) size *= 2;
    node = vector<T>( size*2 );
    idnode = vi( size*2 );
    for( int i = size*2-2; i >= 0; i-- ){
      if( i >= size-1 ){
	if( i-(size-1) < a.size() ) node[i] = a[i-(size-1)];
	else node[i] = SEG_INIT;
	idnode[i] = i-size+1;
      } else {
	if( com( node[i*2+1] , node[i*2+2] ) ){
	  node[i] = node[i*2+1];
	  idnode[i] = idnode[i*2+1];
	} else {
	  node[i] = node[i*2+2];
	  idnode[i] = idnode[i*2+2];
	}
      }
    }
    node[size*2-1] = SEG_NONE;
  }
  void init( int n ){
    vector<T> a(n,SEG_INIT);
    init( a );
  }
  void update( int k , T x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      if( com( node[k*2+1] , node[k*2+2] ) ){
	node[k] = node[k*2+1];
	idnode[k] = idnode[k*2+1];
      } else {
	node[k] = node[k*2+2];
	idnode[k] = idnode[k*2+2];
      }
    }
  }
  int idquery( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return idnode[k];
    } else if( b <= l || r <= a ){
      return size;
    } else {
      int chl = idquery( a , b , k*2+1 , l , (l+r)/2 );
      int chr = idquery( a , b , k*2+2 , (l+r)/2 , r );
      return com( node[chl+size-1] , node[chr+size-1] ) ? chl : chr;
    }
  }
  int idquery( int a , int b ){
    return idquery( a , b , 0 , 0 , size );
  }
  T query( int a , int b ){
    return node[idquery(a,b)+size-1];
  }
  T get( int a ){
    return node[a+size-1];
  }
};


const ll MAX_N = 100010;

ll n;
vpl G[MAX_N];

ll sz[MAX_N];
ll ans;
ll ansp[MAX_N];

vl u[MAX_N], v[MAX_N];
ll belong[MAX_N];

bool used[MAX_N];

Segtree<ll> seg, us;

void dfs4( ll x , ll p , ll k ){
  v[k].pb( x );
  YYS( w , G[x] ) if( w.fi != p ) dfs4( w.fi , x , k );
}

void dfs3( ll x , ll p , ll d ){
  ans += d * 2;
  YYS( w , G[x] ) if( w.fi != p ) dfs3( w.fi , x , d + w.se );
}

ll dfs2( ll x , ll p ){
  YYS( w , G[x] ) if( w.fi != p && sz[w.fi] * 2 > n ) return dfs2( w.fi , x );
  return x;
}

ll dfs( ll x , ll p ){
  sz[x] = 1;
  YYS( w , G[x] ) if( w.fi != p ) sz[x] += dfs( w.fi , x );
  return sz[x];
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n-1 ){
    ll a, b, c;
    scanf( "%lld %lld %lld" , &a , &b , &c ); a--; b--;
    G[a].pb( b , c );
    G[b].pb( a , c );
  }

  dfs( 0 , -1 );
  ll r = dfs2( 0 , -1 );
  dfs3( r , -1 , 0 );

  ll k = 0;
  YYS( w , G[r] ) dfs4( w.fi , r , k++ );
  v[k++].pb( r );

  REP( i , k ) YYS( w , v[i] ) belong[w] = i;
  
  REP( i , k ){
    SORT( v[i] );
    REVERSE( v[i] );
    u[i] = v[i];
  }
  seg.init( k );
  REP( i , k-1 ) seg.update( i , n - 2 * SZ(v[i]) );
  seg.update( k-1 , n-1 );

  us.init( k );
  REP( i , k ) us.update( i , u[i].back() );

  ll p = 0;
  REP( i , n ){
    ll id = seg.idquery( 0 , k );
    if( seg.get(id) - i != 0 ){
      while( used[p] ) p++;
      id = belong[p];
    }
    ll x = v[id].back(); v[id].pop_back();
    used[x] = true;
    if( v[id].empty() ) seg.update( id , INF );

    ll aid = us.idquery( 0 , id );
    ll bid = us.idquery( id+1 , k );
    if( id == k-1 ) bid = us.idquery( id , k );
    ll nid = us.get(aid) < us.get(bid) ? aid : bid;
    ll y = u[nid].back(); u[nid].pop_back();
    if( u[nid].empty() ) us.update( nid , INF );
    else us.update( nid , u[nid].back() );
    
    ansp[x] = y;
    seg.update( id , seg.get(id) + 1 );
    seg.update( nid , seg.get(nid) + 1 );
  }

  printf( "%lld\n" , ans );
  REP( i , n ) printf( "%lld%c" , ansp[i]+1 , i==n-1?'\n':' ' );
  
  return 0;
}