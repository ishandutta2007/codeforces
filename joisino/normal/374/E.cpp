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

struct Unionfind{
  vi size, par, inf, sup;
  Unionfind(){}
  Unionfind( int n ) :  size(n,1), par(n){
    REP( i , n ) par[i] = i;
  }
  void init( int n ){
    size = vi( n , 1 );
    inf = sup = vi( n , 0 );
    par.resize( n );
    REP( i , n ) par[i] = i;
  }
  int find( int x ){
    if( par[x] == x ) return x;
    return par[x] = find( par[x] );
  }
  bool unite( int x , int y ){
    x = find(x);
    y = find(y);
    if( x == y ) return false;
    if( size[y] < size[x] ) swap( x , y );
    par[x] = y;
    size[y] += size[x];
    chmin( inf[y] , inf[x] );
    chmax( sup[y] , sup[x] );
    return true;
  }
  bool same( int x , int y ){
    return find(x) == find(y);
  }
};

const ll MAX_N = 4096;

Unionfind ufx, ufy;

ll n, m;

vpl xs, ys;

vl G[MAX_N];

bool used[MAX_N];
bool res;

void dfs( ll x , ll p ){
  if( used[x] ){
    res = true;
    return;
  }
  used[x] = true;
  YYS( w , G[x] ) if( w != p ) dfs( w , x );
}


bool check( ll t ){
  ufx.init( n ); ufy.init( m );

  REP( i , n ){
    ufx.inf[i] = xs[i].se - 2 * t;
    ufx.sup[i] = xs[i].se + 2 * t;
  }

  REP( i , m ){
    ufy.inf[i] = ys[i].se - 2 * t;
    ufy.sup[i] = ys[i].se + 2 * t;
  }

  REP( i , n ) REP( j , i ) if( xs[i].fi == xs[j].fi && abs( xs[i].se - xs[j].se ) <= 4*t ) ufx.unite( i , j );
  REP( i , m ) REP( j , i ) if( ys[i].fi == ys[j].fi && abs( ys[i].se - ys[j].se ) <= 4*t ) ufy.unite( i , j );

  REP( i , n+m ) G[i].clear();
  
  REP( i , n ) if( ufx.find(i) == i ){
    REP( j , m ) if( ufy.find(j) == j ){
      if( ufx.inf[i] <= ys[j].fi && ys[j].fi <= ufx.sup[i] && ufy.inf[j] <= xs[i].fi && xs[i].fi <= ufy.sup[j]){
	G[i].pb( n+j );
	G[n+j].pb( i );
      }
    }
  }

  res = false;
  REP( i , n+m ) used[i] = false;
  REP( i , n+m ) if( !used[i] ) dfs( i , -1 );
  
  return res;
}

int main(){

  scanf( "%lld %lld" , &n , &m );

  ll x, y;
  REP( i , n ){
    scanf( "%lld %lld" , &x , &y );
    xs.pb( x+y , x-y );
  }
  REP( i , m ){
    scanf( "%lld %lld" , &x , &y );
    ys.pb( x-y , x+y );
  }

  SORT( xs ); SORT( ys );
  
  ll lb = -1, ub = INF;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ) ) ub = md;
    else lb = md;
  }

  if( ub == INF ) printf( "Poor Sereja!\n" );
  else printf( "%lld\n" , ub );
  
  return 0;
}