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

struct Bit{
  vl bit;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
  }
  void add( int k , ll v ){
    for( int i = k+1; i <= size; i += i & -i ) bit[i-1] += v;
  }
  ll sum( int k ){ // [0,k)
    ll res = 0;
    for( int i = k; i > 0; i -= i & -i ) res += bit[i-1];
    return res;
  }
  ll sum( int l , int r ){ // [l,r)
    return sum( r ) - sum( l );
  }
  ll get( int k ){
    return sum( k+1 ) - sum( k );
  }
  ll update( int k , ll x ){
    add( k , x - get(k) );
  }
};

struct Bitran{
  Bit bita , bitb;
  void init( int n ){
    bita.init( n );
    bitb.init( n );
  }
  void add( int a , int b , ll x ){
    bita.add( a , x );
    bita.add( b , -x );
    bitb.add( a , -a*x );
    bitb.add( b , b*x );
  }
  void add( int a , ll x ){
    bitb.add( a , x );
  }
  ll sum( int k ){
    return k * bita.sum(k) + bitb.sum(k);
  }
  ll sum( int a , int b ){
    return sum(b) - sum(a);
  }
};

ll n, m, w;
ll sum;
Bitran bitx, bity;

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &w );
  bitx.init( n+1 );
  bity.init( m+1 );

  REP( i , w ){
    ll t, xa, ya, xb, yb, v;
    scanf( "%lld" , &t );
    if( t == 0 ){
      scanf( "%lld %lld %lld %lld %lld" , &xa , &ya , &xb , &yb , &v ); xa--; ya--;
      bitx.add( xa , xb , ( yb - ya ) * v );
      bity.add( ya , yb , ( xb - xa ) * v );
      sum += ( ( xb - xa ) * ( yb - ya ) * v );
    } else if( t == 1 ){
      scanf( "%lld %lld %lld %lld" , &xa , &ya , &xb , &yb ); xa--; ya--;
      printf( "%lld\n" , bitx.sum( xa , xb ) + bity.sum( ya , yb ) - sum );
    }
  }

  return 0;
}