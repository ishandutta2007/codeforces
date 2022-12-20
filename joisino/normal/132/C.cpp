#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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

const int MAX_N = 256;


// dp[k][i][j] min number of the change to leach i with direction j when process is done from k
int dp[MAX_N][MAX_N][2];

char s[MAX_N];

int ans = 0;

int change_times;


int main(){

  scanf( "%s" , s );
  int n = strlen( s );

  scanf( "%d" , &change_times );
  
  REP( k , MAX_N ) REP( i , MAX_N ) REP( j , 2 ) dp[k][i][j] = INF;
  dp[0][128][0] = 0;

  REP( i , n ) REP( j , MAX_N ) REP( k , 2 ) if( dp[i][j][k] != INF ){
    int dx = ( k == 0 ? 1 : -1 );
    if( s[i] == 'F' ){
      chmin( dp[i+1][j+dx][k] , dp[i][j][k] );
      chmin( dp[i+1][j][1-k] , dp[i][j][k] + 1 );
    } else {
      chmin( dp[i+1][j+dx][k] , dp[i][j][k] + 1 );
      chmin( dp[i+1][j][1-k] , dp[i][j][k] );
    }
  }

  REP( i , MAX_N ) REP( j , 2 ) if( dp[n][i][j] <= change_times ){
    if( ( change_times - dp[n][i][j] ) % 2 == 0 ) chmax( ans , abs( i - 128 ) );
    else chmax( ans , abs( i - 128 ) - 1 );
  }
  
  printf( "%d\n" , ans );
  
  return 0;
}