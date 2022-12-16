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

ll n, a, cf, cm, m;
pl b[100010];

ll sumf[100010];
ll sumb[100010];

ll ans[100010];

bool check( ll ikou, ll nokori, ll mokuhyou ){
  ll lb = ikou-1, ub = n;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( b[md].fi >= mokuhyou ){
      lb = md;
    } else {
      ub = md;
    }
  }
  return mokuhyou * ( n - ub ) - sumb[ub] <= nokori;
}

ll getm( ll ikou, ll nokori ){
  ll lb = 0, ub = a;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( ikou, nokori, md ) ){
      lb = md;
    } else {
      ub = md;
    }
  }
  return lb;
}

int main(){

  n = in();
  a = in();
  cf = in();
  cm = in();
  m = in();

  REP( i , n ){
    b[i] = pl( in() , i );
  }

  sort( b , b+n );
  reverse( b , b+n );

  REP( i , n ){
    sumf[i+1] = sumf[i] + b[i].fi;
    sumb[n-1-i] = sumb[n-i] + b[n-1-i].fi;
  }

  REP( i , n ){
    assert( sumb[i] == sumf[n] - sumf[i] );
  }

  ll ansv = 0;
  ll ansf = 0;
  ll ansm = 0;
  REP( i , n ){
    ll usef = a * i - sumf[i];
    if( usef > m ){
      break;
    }
    ll mm = getm( i , m - usef );
    ll force = i * cf + mm * cm;
    if( force > ansv ){
      ansv = force;
      ansf = i;
      ansm = mm;
    }
  }

  if( a * n - sumf[n] <= m ){
    ansv = n * cf + a * cm;
    ansf = n;
    ansm = a;
  }

  REP( i , ansf ){
    ans[ b[i].se ] = a;
  }
  FOR( i , ansf , n ){
    ans[ b[i].se ] = max( b[i].fi , ansm );
  }

  printf( "%lld\n" , ansv );
  REP( i , n ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%lld" , ans[i] );
  }
  printf( "\n" );

  return 0;
}