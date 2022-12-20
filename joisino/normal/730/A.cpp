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
ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

int n;
vpi v;

vector<string> ans;

int main(){

  n = in();
  REP( i , n ){
    v.pb( in() , i );
  }

  
  while( 1 ){
    SORT( v );
    if( v[0].fi == v[n-1].fi ){
      break;
    }

    string cur( n , '0' );
    if( n >= 4 and v[n-1].fi == v[n-2].fi and v[n-2].fi == v[n-3].fi and v[n-3].fi != v[n-4].fi and v[n-1].fi == v[0].fi + 1 ){
      REP( i , 3 ){
	v[n-1-i].fi = max( 0 , v[n-1-i].fi - 1 );
	cur[ v[n-1-i].se ] = '1';
      }
    } else {
      REP( i , 2 ){
	v[n-1-i].fi = max( 0 , v[n-1-i].fi - 1 );
	cur[ v[n-1-i].se ] = '1';
      }
    }

    ans.pb( cur );
  }

  SORT( v );
  assert( v[0].fi == v[n-1].fi );
  
  printf( "%d\n" , v[0].fi );
  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ){
    printf( "%s\n" , w.c_str() );
  }

  return 0;
}