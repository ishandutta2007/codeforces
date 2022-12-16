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

struct Segtree{
  ll ID = 1;
  ll n;
  vl node;
  ll size;
  void init( ll arg_n ){
    n = arg_n;
    size = 1;
    while( size < n ) size *= 2;
    node = vl( size*2-1 , ID );
  }
  void update( ll k , ll x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      node[k] = __gcd( node[k*2+1] , node[k*2+2] );
    }
  }
  ll query( ll a , ll k , ll l , ll r ){
    ll md = (l+r)/2;
    
    if( !( l <= a && a < r ) ){
      if( node[k] % node[a+size-1] == 0 ) return r-l;
      else if( r-l == 1 ) return 0;
      ll res = query( a , k*2+1 , l , md );
      if( l+res == md ) return res + query( a , k*2+2 , md , r );
      else return res;
    }
    
    if( r-l == 1 ) return 1;
    if( a < md ){
      ll res = query( a , k*2+1 , l , md );
      if( a+res == md ) return res + query( a , k*2+2 , md , r );
      else return res;
    } else {
      return query( a , k*2+2 , md , r );
    }
  }
  ll query( ll a ){
    return min( n-a , query( a , 0 , 0 , size ) );
  }
};

Segtree seg[2];

const ll MAX_N = 300010;

ll n;
ll a[MAX_N];

ll s[MAX_N];

ll ans;
vl ansv;

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  seg[0].init( n ); seg[1].init( n );
  
  REP( i , n ){
    seg[0].update( i , a[i] );
    seg[1].update( n-1-i , a[i] );
  }

  REP( i , n ) s[i] = seg[0].query( i ) + seg[1].query( n-1-i ) - 1;

  REP( i , n ) chmax( ans , s[i] );
  REP( i , n ) if( s[i] == ans ) ansv.pb( i - seg[1].query( n-1-i ) + 1 );

  SORT( ansv );
  UNIQUE( ansv );
  printf( "%lld %lld\n" , SZ(ansv) , ans-1 );
  REP( i , SZ(ansv) ) printf( "%lld%c" , ansv[i]+1 , i==SZ(ansv)-1?'\n':' ' );
  
  return 0;
}