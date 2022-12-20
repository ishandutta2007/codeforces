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
 
// head

int q;
ll n;
ll f[90];

int a[90];
ll dp[91][2][2];

int main(){

  f[0] = 1, f[1] = 2;
  FOR( i , 2 , 90 ) f[i] = f[i-2] + f[i-1];

  scanf( "%d" , &q );
  REP( tc , q ){
    scanf( "%lld" , &n );
    for( int i = 89; i >= 0; i-- ){
      if( n >= f[i] ){
	a[i] = 1;
	n -= f[i];
      } else a[i] = 0;
    }

    REP( i , 91 ) REP( j , 2 ) REP( k , 2 ) dp[i][j][k] = 0;
    dp[90][0][0] = 1;

    for( int i = 90; i >= 1; i-- ) REP( j , 2 ) REP( k , 2 ){
	int x = j;
	int y = k + a[i-1];
	int z = 0;

	// not use
	if( x == 0 ) dp[i-1][y][z] += dp[i][j][k];
	
	// use
	y--;
	if( y < 0 ){ x--; y++; z++; }
	if( x == 0 ) dp[i-1][y][z] += dp[i][j][k];
    }

    printf( "%lld\n" , dp[0][0][0] );
  }

  return 0;
}