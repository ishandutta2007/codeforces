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

ll a, b;

int main(){

  a = in();
  b = in();
  
  if( a == 0 ){
    printf( "%lld\n" , -b*b );
    REP( i , b ){
      printf( "x" );
    }
    printf( "\n" );
    return 0;
  }
  if( b == 0 ){
    printf( "%lld\n" , a*a );
    REP( i , a ){
      printf( "o" );
    }
    printf( "\n" );
    return 0;
  }
  if( b == 1 ){
    printf( "%lld\n" , a*a-1 );
    printf( "x" );
    REP( i , a ){
      printf( "o" );
    }
    printf( "\n" );
    return 0;
  }

  ll ansv = -INFLL;
  ll ansi = -1;
  FOR( i , 2 , b+1 ){
    if( a - i + 2 <= 0 ){
      continue;
    }
    ll x = b / i;
    ll me = b - x * i;
    ll mn = i - me;
    // cout << i << " " << me << " " << mn << " " << x << endl;
    if( mn > 0 && x <= 0 ){
      continue;
    }
    // cout << i << endl;
    ll sc = sq( a - i + 2 ) + ( i - 2 ) - sq(x+1) * me - sq(x) * mn;
    if( sc > ansv ){
      ansv = sc;
      ansi = i;
    }
  }

  // cout << ansi << endl;

  ll x = b / ansi;
  ll me = b - x * ansi;
  ll mn = ansi - me;

  printf( "%lld\n" , ansv );
  vector<string> ssx(0);
  REP( i , me ){
    ssx.pb( string( x+1 , 'x' ) );
  }
  REP( i , mn ){
    ssx.pb( string( x , 'x' ) );
  }

  vector<string> sso( ansi-2, "o" );
  sso.pb( string( a - ansi + 2 , 'o' ) );

  assert( SZ(ssx) == SZ(sso) + 1 );

  REP( i , SZ(ssx) ){
    printf( "%s" , ssx[i].c_str() );
    if( i+1 != SZ(ssx) ){
      printf( "%s" , sso[i].c_str() );
    }
  }
  printf( "\n" );

  return 0;
}