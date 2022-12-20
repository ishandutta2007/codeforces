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

const int MAX_N = 100010;

int n;
ll a[MAX_N], b[MAX_N];

ll dp[MAX_N][2][3];

ll ans = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ) scanf( "%lld" , &a[i] );

  REP( i , n ) b[i] = a[i] + (i>0?a[i-1]:0);

  REP( i , MAX_N ) REP( j , 2 ) REP( k , 3 ) dp[i][j][k] = -INFLL;
  dp[0][0][0] = 0;
  
  REP( i , n - 1 ) REP( j , 2 ) REP( k , 3 ){
    if( ( b[i] - j ) % 2 == 0 ) chmax( dp[i+1][0][k] , dp[i][j][k] + a[i] );
    else if( k + 1 <= 2 ) chmax( dp[i+1][0][k+1] , dp[i][j][k] + a[i] );
    
    if( a[i] > 1 ){
      if( ( b[i] - j - 1 ) % 2 == 0 ) chmax( dp[i+1][1][k] , dp[i][j][k] + a[i] - 1 );
      else if( k + 1 <= 2 ) chmax( dp[i+1][1][k+1] , dp[i][j][k] + a[i] - 1 );
    } else {
      chmax( ans , dp[i][j][k] );
    }
  }

  REP( j , 2 ) REP( k , 3 ) chmax( ans , dp[n-1][j][k] );  

  REP( i , MAX_N ) REP( j , 2 ) REP( k , 3 ) dp[i][j][k] = -INFLL;
  dp[n-1][0][0] = 0;

  for( int i = n-1; i >= 1; i-- ) REP( j , 2 ) REP( k , 3 ){
    if( ( b[i] - j ) % 2 == 0 ) chmax( dp[i-1][0][k] , dp[i][j][k] + a[i-1] );
    else if( k + 1 <= 2 ) chmax( dp[i-1][0][k+1] , dp[i][j][k] + a[i-1] );
    
    if( a[i-1] > 1 ){
      if( ( b[i] - j - 1 ) % 2 == 0 ) chmax( dp[i-1][1][k] , dp[i][j][k] + a[i-1] - 1 );
      else if( k + 1 <= 2 ) chmax( dp[i-1][1][k+1] , dp[i][j][k] + a[i-1] - 1 );
    } else {
      chmax( ans , dp[i][j][k] );
    }
  }

  REP( j , 2 ) REP( k , 3 ) chmax( ans , dp[0][j][k] );    

  printf( "%lld\n" , ans );
  
  return 0;
}