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

int a[128];

int x;

int n;

int main(){

  int sgn = 1;
  while( 1 ){
    string s = stin();

    if( s[0] == '?' ){
      a[n] = sgn;
      n++;
    } else if( s[0] == '+' ){
      sgn = 1;
    } else if( s[0] == '-' ){
      sgn = -1;
    } else if( s[0] == '=' ){
      break;
    } else {
      assert( false );
    }
  }

  x = in();

  int ma = 0;
  int mi = 0;
  REP( i , n ){
    if( a[i] == 1 ){
      ma += x;
      mi++;
    } else if( a[i] == -1 ){
      ma--;
      mi -= x;
    }
  }

  if( mi <= x && x <= ma ){
    puts( "Possible" );
    int cur = mi;
    REP( i , n ){
      if( i != 0 ){
        if( a[i] == 1 ){
          printf( " + " );
        } else if( a[i] == -1 ){
          printf( " - " );
        }
      }
      if( a[i] == 1 ){
        if( x - cur < x - 1 ){
          printf( "%d" , 1 + x - cur );
          cur = x;
        } else {
          printf( "%d" , x );
          cur += x - 1;
        }
      } else if( a[i] == -1 ){
        if( x - cur < x - 1 ){
          printf( "%d" , x - ( x - cur ) );
          cur = x;
        } else {
          printf( "%d" , 1 );
          cur += x - 1;
        }
      }
    }
    assert( cur == x );
    printf( " = %d\n" , x );
  } else {
    puts( "Impossible" );
  }
  
  return 0;
}