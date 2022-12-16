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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

typedef pair<ll,pl> T;

ll n, m, k, s;

ll a[200010];
ll b[200010];

vpl x, y;

ll sa[200010];
ll sb[200010];

pair<bool,T> check( ll day ){
  pl ca = pl( INFLL , INFLL );
  pl cb = pl( INFLL , INFLL );
  REP( i , day ){
    chmin( ca , pl( a[i] , i ) );
    chmin( cb , pl( b[i] , i ) );
  }
  REP( i , k + 1 ){
    if( i > SZ(x) || k-i > SZ(y) ){
      continue;
    }
    if( ca.fi * sa[i] + cb.fi * sb[k-i] <= s ){
      return make_pair(true, T(i,pi(ca.se,cb.se)));
    }
  }
  return make_pair(false,T(0,pi(0,0)));
}

int main(){

  n = in();
  m = in();
  k = in();
  s = in();

  REP( i , n ){
    a[i] = in();
  }
  REP( i , n ){
    b[i] = in();
  }

  REP( i , m ){
    int t = in();
    ll v = in();
    if( t == 1 ){
      x.pb( v , i );
    } else {
      y.pb( v , i );
    }
  }
  SORT( x );
  SORT( y );

  REP( i , SZ(x) ){
    sa[i+1] = sa[i] + x[i].fi;
  }
  REP( i , SZ(y) ){
    sb[i+1] = sb[i] + y[i].fi;
  }
  
  ll lb = 0, ub = n + 1;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ).fi ){
      ub = md;
    } else {
      lb = md;
    }
  }

  if( ub == n + 1 ){
    puts( "-1" );
    return 0;
  }

  printf( "%lld\n" , ub );

  T p = check( ub ).se;

  REP( i , p.fi ){
    printf( "%lld %lld\n" , x[i].se + 1 , p.se.fi + 1 );
  }
  REP( i , k - p.fi ){
    printf( "%lld %lld\n" , y[i].se + 1 , p.se.se + 1 );
  }
  
  return 0;
}