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

struct BIT{
  vl bit;
  ll size;
  void init( ll n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
  }
  void add( ll k , ll v ){
    for( ll i = k+1; i <= size; i += i & -i ) bit[i-1] += v;
  }
  ll sum( ll k ){
    ll res = 0;
    for( ll i = k; i > 0; i -= i & -i ) res += bit[i-1];
    return res;
  }
  ll sum( ll l , ll r ){
    return sum( r ) - sum( l );
  }
};


struct SegtreeSet{
  vl minv, maxv;
  ll size;
  void init( ll n ){
    size = 1;
    while( size < n ) size *= 2;
    minv = vl( size*2-1 ,  INFLL );
    maxv = vl( size*2-1 , -INFLL );
  }
  void insert( ll x ){
    ll k = x + size-1;
    minv[k] = maxv[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      minv[k] = min( minv[k*2+1] , minv[k*2+2] );
      maxv[k] = max( maxv[k*2+1] , maxv[k*2+2] );
    }
  }
  void erase( ll x ){
    ll k = x + size-1;
    minv[k] = INFLL; maxv[k] = -INFLL;
    while( k > 0 ){
      k = (k-1)/2;
      minv[k] = min( minv[k*2+1] , minv[k*2+2] );
      maxv[k] = max( maxv[k*2+1] , maxv[k*2+2] );
    }
  }
  bool find( ll x ){
    return minv[ x + size-1 ] == x;
  }
  ll ijou( ll x ){
    ll k = x + size-1;
    while( k > 0 && maxv[k] < x ) k = (k-1)/2;
    while( k < size-1 ){
      if( maxv[k*2+1] >= x ) k = k*2+1;
      else k = k*2+2;
    }
    return maxv[k];
  }
  ll ika( ll x ){
    ll k = x + size-1;
    while( k > 0 && minv[k] > x ) k = (k-1)/2;
    while( k < size-1 ){
      if( minv[k*2+2] <= x ) k = k*2+2;
      else k = k*2+1;
    }
    return minv[k];
  }
};

const ll MAX_N = 1000010;

ll n, k;
ll p[MAX_N], inv[MAX_N], b[MAX_N];
bool used[MAX_N];

ll ans;

SegtreeSet ss;

BIT bit;

int main(){

  scanf( "%lld %lld" , &n , &k );
  REP( i , n ) scanf( "%lld" , &p[i] ), p[i]--, inv[ p[i] ] = i;
  REP( i , k ) scanf( "%lld" , &b[i] ), b[i]--, used[ b[i] ] = true;

  bit.init( n );
  REP( i , n ) bit.add( i , 1 );

  ss.init( n+1 );
  ss.insert( 0 ); ss.insert( n );
  REP( i , n ){
    if( used[ i ] ){
      ss.insert( inv[i] );
    } else {
      ll l = ss.ika( inv[i] );
      ll r = ss.ijou( inv[i]+1 );
      ans += bit.sum( l , r );
    }
    bit.add( inv[i] , -1 );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}