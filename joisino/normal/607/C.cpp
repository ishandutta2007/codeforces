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

int fail[1000010];

string s, t, u;

int main(){

  int n = in();
  s = stin();
  t = stin();

  REVERSE( t );
  YYS( w , t ){
    if( w == 'E' ){
      u += "W";
    } else if( w == 'N' ){
      u += "S";
    } else if( w == 'W' ){
      u += "E";
    } else if( w == 'S' ){
      u += "N";
    } else {
      assert( false );
    }
  }

  fail[0] = -1;
  fail[1] = 0;
  int p = 0;
  FOR( q , 2 , SZ(u) ){
    while( p >= 0 && u[q-1] != u[p] ){
      p = fail[p];
    }
    fail[q] = ++p;
  }
  
  // cout << s << " " << u << endl;

  p = 0;
  int q = 0;
  while( p + q < SZ(s) ){
    // cout << p << " " << q << endl;
    if( u[q] == s[p+q] ){
      if( p+q == SZ(s)-1 ){
        puts( "NO" );
        return 0;
      } else {
        q++;
      }
    } else {
      p += q - fail[q];
      if( q > 0 ){
        q = fail[q];
      }
    }
  }

  puts( "YES" );
  
  return 0;
}