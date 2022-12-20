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

int n, t;

char s[200010];

int main(){

  scanf( "%d %d" , &n , &t );
  scanf( "%s" , s );

  int p = n-1;

  bool f = false;
  REP( i , n ){
    if( s[i] == '.' ) f = true;
    if( !f ) continue;
    if( s[i] >= '5' ){
      for( p = i-1; p > max(0,(int)i-t); p-- ){
	if( s[p] != '4' ) break;
      }
      if( s[p] == '.' ){
	p--;
	int q = p;
	while( q >= 0 && s[q] == '9' ){
	  s[q] = '0';
	  q--;
	}
	if( q == -1 ){
	  printf( "1" );
	  REP( i , p+1 ) printf( "0" );
	  printf( "\n" );
	  return 0;
	} else {
	  s[q]++;
	}
      } else {
	assert( s[p] != '9' );
	s[p]++;
      }
      break;
    }
  }
  
  REP( i , p+1 ) printf( "%c" , s[i] );
  printf( "\n" );
  
  return 0;
}