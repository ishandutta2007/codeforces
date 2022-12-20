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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<typename T>
struct LazySegtree{
  const T ID = 0;
  const T NONE = INFLL;
  vector<T> node, lazy;
  ll size;
  inline void push( ll k , ll l , ll r ){
    if( k < size-1 ) lazy[k*2+1] = lazy[k*2+2] = lazy[k];
    else node[k] = lazy[k];
    lazy[k] = NONE;
  }
  void init( ll n ){
    size = 1;
    while( size < n ) size *= 2;
    lazy = vector<T>( size*2-1 , NONE );
    node = vector<T>( size*2-1 , ID );
  }
  void update( ll a , ll b , T x , ll k , ll l , ll r ){
    if( a <= l && r <= b ){
      lazy[k] = x;
      push( k , l , r );
    } else if( b <= l || r <= a ){
      return;
    } else {
      if( lazy[k] != NONE ) push( k , l , r );
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
    }
  }
  void update( ll a , ll b , T x ){
    update( a , b , x , 0 , 0 , size );
  }
  T get( ll a , ll k , ll l , ll r ){
    if( lazy[k] != NONE ) push( k , l , r );
    if( r - l == 1 ){
      return node[k];
    } else {
      if( a < (l+r)/2 ) return get( a , k*2+1 , l , (l+r)/2 );
      else return get( a , k*2+2 , (l+r)/2 , r );
    }
  }
  T get( ll a ){
    return get( a , 0 , 0 , size );
  }
};

const ll MAX_N = 100010;

ll n, m;
ll a[MAX_N];

LazySegtree<ll> l[20], r[20];

ll le[MAX_N], ri[MAX_N];

ll ans = 0;

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%lld" , &a[i+1] );

  REP( j , 20 ){
    le[0] = 0; le[n+1] = n+1;
    FOR( i , 1 , n+1 ){
      if( a[i] & PW(j) ) le[i] = le[i-1];
      else le[i] = i;
    }
    l[j].init( n+2 );
    REP( i , n+2 ) l[j].update( i , i+1 , le[i] );

    ri[0] = 0; ri[n+1] = n+1;
    for( ll i = n; i >= 1; i-- ){
      if( a[i] & PW(j) ) ri[i] = ri[i+1];
      else ri[i] = i;
    }
    r[j].init( n+2 );
    REP( i , n+2 ) r[j].update( i , i+1 , ri[i] );

    FOR( i , 1 , n+1 ) ans += ( ri[i] - i ) * PW(j);
  }

  REP( query_cnt , m ){
    ll p, v;
    scanf( "%lld %lld" , &p , &v );
    REP( j , 20 ){
      if( ( v & PW(j) ) && !( a[p] & PW(j) ) ){
	ll tor = r[j].get( p+1 );
	ll tol = l[j].get( p-1 );
	r[j].update( tol+1 , p+1 , tor );
	l[j].update( p , tor , tol );
	ans += (tor-p)*(p-tol)*PW(j);
      }
      if( !( v & PW(j) ) && ( a[p] & PW(j) ) ){
	ll tor = r[j].get( p );
	ll tol = l[j].get( p );
	r[j].update( tol+1 , p+1 , p );
	l[j].update( p , tor , p );
	ans -= (tor-p)*(p-tol)*PW(j);
      }
    }
    a[p] = v;
    printf( "%lld\n" , ans );
  }
  
  return 0;
}