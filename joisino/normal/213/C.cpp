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

const int MAX_N = 310;

int n;
ll a[MAX_N][MAX_N];
ll dp[2][MAX_N][MAX_N];
ll dq[2][MAX_N][MAX_N];
ll ans = -INFLL;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) REP( j , n ) scanf( "%lld" , &a[i][j] );

  dp[1][0][0] = a[0][0];
  FOR( i , 1 , n ){
    REP( j , MAX_N ) REP( k , MAX_N ) dp[(i+1)%2][j][k] = -INFLL;
    REP( j , i ) REP( k , i ){
      REP( l , 2 ) REP( m , 2 ){
	if( j+l == k+m ) chmax( dp[(i+1)%2][j+l][k+m] , dp[i%2][j][k] + a[i-(j+l)][j+l] );
	else chmax( dp[(i+1)%2][j+l][k+m] , dp[i%2][j][k] + a[i-(j+l)][j+l] + a[i-(k+m)][k+m] );
      }
    }
  }

  dq[1][0][0] = a[n-1][n-1];
  FOR( i , 1 , n ){
    REP( j , MAX_N ) REP( k , MAX_N ) dq[(i+1)%2][j][k] = -INFLL;
    REP( j , i ) REP( k , i ){
      REP( l , 2 ) REP( m , 2 ){
	if( j+l == k+m ) chmax( dq[(i+1)%2][j+l][k+m] , dq[i%2][j][k] + a[n-1-(j+l)][n-1-i+j+l] );
	else chmax( dq[(i+1)%2][j+l][k+m] , dq[i%2][j][k] + a[n-1-(j+l)][n-1-i+j+l] + a[n-1-(k+m)][n-1-i+k+m] );
      }
    }
  }

  REP( i , n ) REP( j , n ){
    if( i == j ) chmax( ans , dp[n%2][i][j] + dq[n%2][i][j] - a[n-1-i][i] );
    else chmax( ans , dp[n%2][i][j] + dq[n%2][i][j] - a[n-1-i][i] - a[n-1-j][j] );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}