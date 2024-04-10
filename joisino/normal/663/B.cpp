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

set<string> ss;

map<string,string> dp;

bool f( string s ){
  if( SZ(s) <= 4 ){
    if( atoi(s.c_str()) < 1989 ){
      return true;
    }
    FOR( i , 1 , SZ(s) ){
      if( dp[s.substr(SZ(s)-i)] == s ){
        return true;
      }
    }
    return false;
  }
  if( s[0] == '1' ){
    if( s[1] == '0' ){
      return true;
    } else {
      return f( s.substr( 1 ) );
    }
  }
  return false;
}

int main(){

  FOR( i , 1989 , 100000 ){
    string s = to_string( i );
    for( int j = SZ(s) - 1; j >= 0; j-- ){
      string t = s.substr( j );
      if( ss.find( t ) == ss.end() ){
        ss.insert( t );
        dp[t] = s;
        break;
      }
    }
  }

  int n = in();
  REP( i , n ){
    string s = stin();
    s = s.substr( 4 );
    if( SZ(s) <= 4 ){
      printf( "%s\n" , dp[s].c_str() );
    } else {
      if( s[0] == '0' || f( s ) ){
        s = "1" + s;
        printf( "%s\n" , s.c_str() );
      } else {
        printf( "%s\n" , s.c_str() );
      }
    }
  }

  return 0;
}