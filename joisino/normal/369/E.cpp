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

struct BIT{
  vl node;
  ll size;
  void init( ll n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vl( size , 0 );
  }
  void add( ll k , ll x ){
    for( ll i = k+1; i <= size; i += i & -i ) node[i-1] += x;
  }
  ll sum( ll k ){
    ll res = 0;
    for( ll i = k; i > 0; i -= i & -i ) res += node[i-1];
    return res;
  }
};


struct qs{
  ll x, id, next;
  qs(){}
  qs( ll x , ll id , ll next ) : x(x) , id(id) , next(next) {}
  bool operator <( const qs &a ) const {
    if( x != a.x ) return x < a.x;
    if( id != a.id ) return id < a.id;
    return next < a.next;
  }
};

const ll MAX_N = 300010;
const ll ADD = -INFLL;
const ll REM = INFLL;

ll n, m;
vector<qs> sweep;

BIT bit;

ll temp[MAX_N];
ll ans[MAX_N];

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ){
    ll l, r;
    scanf( "%lld %lld" , &l , &r );
    sweep.pb( l , ADD , r );
    sweep.pb( r , REM , -1 );
  }

  REP( i , m ){
    ll s;
    scanf( "%lld" , &s );
    REP( j , s ) scanf( "%lld" , &temp[j] );
    temp[s] = 1000010;
    REP( j , s ) sweep.pb( temp[j] , i , temp[j+1] );
  }

  SORT( sweep );

  bit.init( 1000072 );
  YYS( w , sweep ){
    if( w.id == ADD ){
      bit.add( w.next , 1 );
    } else if( w.id == REM ){
      bit.add( w.x , -1 );
    } else {
      ans[ w.id ] += bit.sum( w.next );
    }
  }

  REP( i , m ) printf( "%lld\n" , ans[i] );
  
  return 0;
}