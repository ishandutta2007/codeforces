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


struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }

template<typename T>
struct Segtree{
  const ll ID = INFLL; // indetity element
  vector<T> node;
  int size;
  T op( T a , T b ){ // operator
    return min( a , b );
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , ID );
  }
  void update( int k , T x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  T query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      T chl = query( a , b , k*2+1 , l , (l+r)/2 );
      T chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return op( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  T get( int a ){
    return node[a+size-1];
  }
};

const ll MAX_N = 100010;

Mod fact[MAX_N];
Mod ifact[MAX_N];
Mod Comb( ll a , ll b ){
  if( a < 0 || b < 0 || a-b < 0 ) return 0;
  return fact[a] * ifact[b] * ifact[a-b];
}

Segtree<ll> seg;

ll n;
ll a[MAX_N];

vpl v;

Mod dp[MAX_N][2];

int main(){

  fact[0] = 1;
  FOR( i , 1 , MAX_N ) fact[i] = fact[i-1] * i;
  REP( i , MAX_N ) ifact[i] = inv( fact[i] );

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  a[n] = n+1; n++;
  REP( i , n ) if( a[i] != 0 ) v.pb( a[i] , i );
  SORT( v );

  seg.init( n );
  REP( i , n ) seg.update( i , a[i] );

  if( v[0].fi == 1 ){
    dp[0][0] = 1;
  } else {
    if( v[0].se - v[0].fi + 1 >= 0 && seg.query( v[0].se - v[0].fi + 1 , v[0].se ) < v[0].fi ) dp[0][0] = modpow( 2 , v[0].fi-2 );
    if( v[0].se + v[0].fi <= n     && seg.query( v[0].se + 1 , v[0].se + v[0].fi ) < v[0].fi ) dp[0][1] = modpow( 2 , v[0].fi-2 );
  } 

  FOR( i , 1 , SZ(v) ){
    ll md = v[i].fi - v[i-1].fi - 1;
    if( v[i-1].se < v[i].se ){
      // left
      ll le = md - ( v[i].se - v[i-1].se - 1 );
      if( le >= 0 && v[i-1].se - v[i-1].fi + 1 - le >= 0 && seg.query( v[i-1].se - v[i-1].fi + 1 - le , v[i].se ) < v[i].fi ) dp[i][0] += dp[i-1][0] * Comb( md , le );
      // right
      le = md - ( v[i].se - v[i-1].se - v[i-1].fi );
      if( le >= 0 && seg.query( v[i-1].se - le , v[i].se ) < v[i].fi ) dp[i][0] += dp[i-1][1] * Comb( md , le );
    } else {
      // right
      ll ri = md - ( v[i-1].se - v[i].se - 1 );
      if( ri >= 0 && v[i-1].se + v[i-1].fi + ri <= n && seg.query( v[i].se + 1 , v[i-1].se + v[i-1].fi + ri ) < v[i].fi ) dp[i][1] += dp[i-1][1] * Comb( md , ri );
      // left
      ri = md - ( v[i-1].se - v[i].se - v[i-1].fi );
      if( ri >= 0 && seg.query( v[i].se + 1 , v[i-1].se + ri + 1 ) < v[i].fi ) dp[i][1] += dp[i-1][0] * Comb( md , ri );
    }
  }

  printf( "%lld\n" , (ll)dp[SZ(v)-1][0].n );
  
  return 0;
}