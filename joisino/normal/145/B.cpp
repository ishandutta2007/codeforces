#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int a, b, c, d;

string s;
int p;

int main(){

  scanf( "%d %d %d %d" , &a , &b , &c , &d );

  if( abs( c-d ) > 1 ){
    puts( "-1" );
    return 0;
  }

  if( c < d || ( c == d && a == c ) ) p = 1;

  while( c > 0 || d > 0 ){
    if( p == 0 ){
      s += '4';
      if( s.length() >= 2 ) d--;
      a--;
    } else if( p == 1 ){
      s += '7';
      if( s.length() >= 2 ) c--;
      b--;
    }
    p = 1 - p;
  }

  if( a < 0 || b < 0 ){
    puts( "-1" );
    return 0;
  }

  int n = s.length();
  REP( i , n ){
    if( s[i] == '4' ){
      s = s.substr( 0 , i ) + string( a , '4' ) + s.substr( i );
      break;
    }
  }

  n = s.length();
  for( int i = n-1; i >= 0; i-- ){
    if( s[i] == '7' ){
      s = s.substr( 0 , i ) + string( b , '7' ) + s.substr( i );
      break;
    }
  }
  
  printf( "%s\n" , s.c_str() );
  
  return 0;
}