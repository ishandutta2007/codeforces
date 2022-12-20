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
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

int n, m;

vi G[300010];

int s[300010];
int t[300010];
ll c[300010];
int id[300010];

vi from[300010];
vi to[300010];

ll dp[300010];
ll ans;

int cnt;

int inid[300010];
int outid[300010];

ll node[2000010];
ll added[2000010];
int size;

void init( int n ){
  size = 1;
  while( size < n ){
    size *= 2;
  }
}

void add( int a , int b , ll x , int k , int l , int r ){
  if( a <= l and r <= b ){
    added[k] += x;
    chmin( added[k] , INFLL );
  } else if( b <= l or r <= a ){
    
  } else {
    add( a , b , x , k*2+1 , l , (l+r)/2 );
    add( a , b , x , k*2+2 , (l+r)/2 , r );
    node[k] = min( node[k*2+1] + added[k*2+1] , node[k*2+2] + added[k*2+2] );
    chmin( node[k] , INFLL );
  }
}

void add( int a , int b , ll x ){
  add( a , b , x , 0 , 0 , size );
}

ll query( int a , int b , int k , int l , int r ){
  if( a <= l and r <= b ){
    ll res = node[k] + added[k];
    return min( res , INFLL );
  } else if( b <= l or r <= a ){
    return INFLL;
  } else {
    ll chl = query( a , b , k*2+1 , l , (l+r)/2 );
    ll chr = query( a , b , k*2+2 , (l+r)/2 , r );
    ll res = min( chl , chr ) + added[k];
    return min( res , INFLL );
  }
}

ll query( int a , int b ){
  return query( a , b , 0 , 0 , size );
}

void dfs( int x , int p ){
  inid[x] = cnt;

  ll sum = 0;
  YYS( w , G[x] ){
    if( w != p ){
      dfs( w , x );
      sum += dp[w];
    }
  }

  YYS( w , G[x] ){
    if( w != p ){
      add( inid[w] , outid[w] , sum - dp[w] );
    }
  }

  YYS( w , from[x] ){
    add( cnt , cnt+1 , sum + c[w] );
    id[w] = cnt;
    cnt++;
  }

  YYS( w , to[x] ){
    add( id[w] , id[w]+1 , INFLL );
  }

  outid[x] = cnt;

  dp[x] = query( inid[x] , outid[x] );
  if( dp[x] == INFLL ){
    throw -1;
  }
}

int main(){

  n = in();
  m = in();

  init( m );

  REP( i , n-1 ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , m ){
    s[i] = in() - 1;
    t[i] = in() - 1;
    c[i] = in();

    from[ s[i] ].pb( i );
    to[ t[i] ].pb( i );
  }

  YYS( w , G[0] ){
    try{
      dfs( w , 0 );
      ans += dp[w];
    } catch( int e ){
      puts( "-1" );
      return 0;
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}