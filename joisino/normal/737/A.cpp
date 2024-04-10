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
#define SHOW(x) cout << #x << " = " << x << endl
 
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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

ll n, k, s, t;

vpl car;
vl pos;

vl un, fi;
ll unsum, fisum;

int main(){

  n = in();
  k = in();
  s = in();
  t = in();
  REP( i , n ){
    ll c = in();
    ll v = in();
    car.pb( v , c );
  }
  SORT( car );
  pos.pb( 0 );
  REP( i , k ){
    ll p = in();
    pos.pb( p );
  }
  pos.pb( s );
  SORT( pos );
  /*
  YYS( p , pos ){
    SHOW( p );
  }
  */
  REP( i , SZ(pos) - 1 ){
    un.pb( pos[i+1] - pos[i] );
    unsum += pos[i+1] - pos[i];
  }
  SORT( un );
  REVERSE( un );
  ll ma = un[0];

  /*
  YYS( w , un ){
    SHOW( w );
  }
  */
  
  ll ans = INFLL;
  YYS( w , car ){
    ll v = w.fi;
    ll c = w.se;
    if( ma > v ){
      continue;
    }
    while( !un.empty() and un.back() * 2 <= v ){
      ll cun = un.back();
      un.pop_back();
      unsum -= cun;
      fi.pb( cun );
      fisum += cun;
    }
    if( SZ(un) * v - unsum + fisum >= 2 * s - t ){
      chmin( ans , c );
    }
  }

  if( ans == INFLL ){
    ans = -1;
  }

  printf( "%lld\n" , ans );

  return 0;
}