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

const ll MAX_N = 5010;

ll n;
ll a[MAX_N], b[MAX_N];

ll iniv;
ll maxv, comb;

BIT bit;

void cswap( ll x , ll y ){
  swap( b[x] , b[y] );
  iniv++;
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] ), b[i] = a[i];

  FOR( i , 1 , n ){
    ll j = i;
    while( j > 0 && b[j] < b[j-1] ){
      cswap( j , j-1 );
      j--;
    }
  }

  maxv = -1; comb = 0;
  REP( st , n ){
    bit.init( n );
    FOR( en , st+1 , n ){
      if( a[st] > a[en] ){
	ll res = bit.sum( a[st] ) - bit.sum( a[en] );
	if( res > maxv ){
	  maxv = res;
	  comb = 1;
	} else if( res == maxv ){
	  comb++;
	}
      }
      bit.add( a[en] , 1 );
    }
  }

  ll resv = maxv == -1 ? iniv : iniv - maxv*2 - 1;
  printf( "%lld %lld\n" , resv , comb );
  
  return 0;
}