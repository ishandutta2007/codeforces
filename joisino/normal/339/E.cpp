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

const ll MAX_N = 1024;

ll n;
ll a[MAX_N];

vpl res;
vpl ans;

void dfs( ll t ){
  
  vl v(0);
  ll d = INFLL, cnt = 0, hs = 0;
  FOR( i , 1 , n+2 ){
    if( d == INFLL ){
      if( abs( a[i] - a[i-1] ) == 1 ) d = a[i] - a[i-1], cnt = 1;
      else v.pb( i ), hs++;
    } else {
      if( a[i] != a[i-1] + d ){
	v.pb( i ), hs++;
	if( cnt == 1 ) v.pb( i - 1 );
	cnt = 0;
	d = INFLL;
      } else cnt++;
    }
  }

  if( hs > ( 3 - t ) * 2 ) return;

  if( SZ(v) == 0 ){
    ans = res;
    return;
  } else if( t == 3 ) return;

  YYS( l , v ) YYS( r , v ) if( l+1 < r ){
    reverse( a + l , a + r );
    res.pb( l , r );
    dfs( t + 1 );
    res.pop_back();
    reverse( a + l , a + r );
  }
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i+1] );
  a[0] = 0; a[n+1] = n+1;
  
  dfs( 0 );

  REVERSE( ans );
  
  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi , w.se-1 );
  
  return 0;
}