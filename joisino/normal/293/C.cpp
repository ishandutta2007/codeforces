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

vl divisor( ll x ){
  vl res(0);
  for( ll i = 2; i * i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x / i ) res.pb( x / i );
    }
  }
  return res;
}

ll n;

vl ps;


typedef pair<ll,pl> se;
set<se> ss;

void yuyu( ll x , ll y , ll z ){
  ll a = x + y - z;
  ll b = y + z - x;
  ll c = z + x - y;
  if( a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && a > 0 && b > 0 && c > 0 ){
    ss.insert( se( x , pl( y , z ) ) );
  }
}

int main(){

  scanf( "%lld" , &n );

  if( n % 3 != 0 ){
    puts( "0" );
    return 0;
  }

  n /= 3;
  
  ps = divisor( n );
  SORT( ps );

  for( int i = 0; i < SZ(ps) && ps[i] * ps[i] * ps[i] <= n; i++ ){
    for( int j = i; j < SZ(ps) && ps[i] * ps[j] * ps[j] <= n; j++ ) if( n % ( ps[i] * ps[j] ) == 0 ){
      vl v = { ps[i] , ps[j] , n / ps[i] / ps[j] };
      do{
	yuyu( v[0] , v[1] , v[2] );
      } while( next_permutation( ALL(v) ) );
    }
  }

  printf( "%lld\n" , SZ(ss) );
  
  return 0;
}