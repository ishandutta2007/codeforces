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

struct qu{
  ll a, b;
  qu(){}
  qu( ll aa , ll ab ){
    if( ab < 0 ) aa *= -1, ab *= -1;
    a = aa;
    b = ab;
  }
  const bool operator == ( const qu &x ) const {
    return a * x.b == b * x.a;
  }
  const bool operator < ( const qu &x ) const {
    return a * x.b < b * x.a;
  }
};

typedef pair<qu,qu> pq;
typedef pair<pq,qu> pqq;

const ll MAX_N = 300010;

inline ll sq( ll x ){ return x * x; }

vector<pqq> ms;

ll n, m;

ll xa[MAX_N], ya[MAX_N], xb[MAX_N], yb[MAX_N];
ll cx[MAX_N], cy[MAX_N], r[MAX_N];

ll ans = 0;

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%lld %lld %lld %lld" , &xa[i] , &ya[i] , &xb[i] , &yb[i] );
  REP( i , m ) scanf( "%lld %lld %lld" , &cx[i] , &cy[i] , &r[i] );

  REP( i , m ) REP( j , i ) if( r[i] == r[j] && sq( cx[i] - cx[j] ) + sq( cy[i] - cy[j] ) > sq( r[i] + r[j] ) ){
    if( cy[i] != cy[j] ) ms.pb( pq( qu( cx[j] - cx[i] , cy[i] - cy[j] ) , qu( sq(cx[i]) - sq(cx[j]) + sq(cy[i]) - sq(cy[j]) , 2 * ( cy[i] - cy[j] ) ) ) , qu( cx[i] + cx[j] , 2 ) );
    else ms.pb( pq( qu( 1 , 0 ) , qu( cx[i] + cx[j] , 2 ) ) , qu( cy[i] , 1 ) );
  }

  SORT( ms );

  REP( i , n ){
    if( xa[i] != xb[i] ){
      pq line = pq( qu( ya[i] - yb[i] , xa[i] - xb[i] ) , qu( xa[i] * yb[i] - xb[i] * ya[i] , xa[i] - xb[i] ) );
      ans += upper_bound( ALL(ms) , pqq( line , qu( max( xa[i] , xb[i] ) , 1 ) ) ) - lower_bound( ALL(ms) , pqq( line , qu( min( xa[i] , xb[i] ) , 1 ) ) );
    } else {
      pq line = pq( qu( 1 , 0 ) , qu( xa[i] , 1 ) );
      ans += upper_bound( ALL(ms) , pqq( line , qu( max( ya[i] , yb[i] ) , 1 ) ) ) - lower_bound( ALL(ms) , pqq( line , qu( min( ya[i] , yb[i] ) , 1 ) ) );
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}