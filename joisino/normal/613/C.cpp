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

int n;
int a[26];

int sum = 0;

int main(){

  n = in();
  REP( i , n ){
    a[i] = in();
    sum += a[i];
  }

  int g = a[0];
  REP( i , n ){
    g = __gcd( g , a[i] );
  }

  if( g % 2 == 0 ){
    string s = "";
    REP( i , n ){
      s += string( a[i] / g , char( 'a' + i ) );
    }
    string rs = s;
    REVERSE( rs );
    if( g == 1 ){
      printf( "0\n" );
    } else {
      printf( "%d\n" , g );
    }
    REP( i , g ){
      if( i % 2 == 0 ){
        printf( "%s" , s.c_str() );
      } else {
        printf( "%s" , rs.c_str() );
      }
    }
    printf( "\n" );
  } else if( g % 2 == 1 ){
    bool ok = false;
    int x = -1;
    REP( i , n ){
      if( ( a[i] / g ) % 2 == 1 ){
        if( x != -1 ){
          ok = false;
          break;
        }
        ok = true;
        x = i;
      }
    }
    if( ok ){
      printf( "%d\n" , g );
      string rs = "";
      REP( i , n ){
        if( ( a[i] / g ) % 2 == 0 ){
          rs += string( a[i] / g / 2, char( 'a' + i ) );
        }
      }
      string s = rs;
      s += string( a[x] / g, char( 'a' + x ) );
      REVERSE( rs );
      s += rs;
      string ans = "";
      REP( i , g ){
        ans += s;
      }
      printf( "%s\n" , ans.c_str() );
    } else {
      printf( "0\n" );
      REP( i , n ){
        REP( j , a[i] ){
          printf( "%c" , char('a'+i) );
        }
      }
      printf( "\n" );
    }
  }
  
  return 0;
}