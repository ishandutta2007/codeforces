#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }


const int MAX_N = 32;

int n;
ll a[MAX_N];

int dp[2][1<<23];

vector<int> s[MAX_N];

bool ok( int i , int j ){
  REP( k , s[i].size() )
    if( (j & s[i][k]) == s[i][k] )
      return true;
  return false;
}

int main(){

  cin >> n;

  REP( i , n )
    cin >> a[i];

  REP( i , n ){
    REP( j , i )
      REP( k , i )
      if( a[j] + a[k] == a[i] )
	s[i].pb( (1<<j)|(1<<k) );
    sort( ALL(s[i]) );
    s[i].erase( unique( ALL( s[i] ) ) , s[i].end() );
  }

  /*
  REP( i , n ){
    REP( j , s[i].size() )
      cout << i << " "<< s[i][j] << endl;
  }
  */


  dp[1][0] = INF;
  dp[1][1] = 1;
  FOR( i , 1 , n ){
    REP( j , 1<<(i+1) )
      dp[(i+1)&1][j] = INF;
    
    REP( j , 1<<i ){
      if( ok( i , j ) ){
	REP( k , i ){
	  if( j & (1<<k) )
	    chmin( dp[(i+1)&1][j-(1<<k)+(1<<i)] , dp[i&1][j] );
	}
	chmin( dp[(i+1)&1][j+(1<<i)] , dp[i&1][j] + 1 );
      }
    }
  }

  int ans = INF;
  REP( i , 1<<n )
    chmin( ans , dp[n&1][i] );

  if( ans == INF ) cout << -1 << endl;
  else cout << ans << endl;
  
  return 0;
}