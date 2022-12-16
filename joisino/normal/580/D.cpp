#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 20;

int n, m, k;
ll dp[1<<MAX_N][MAX_N];
ll a[MAX_N];
ll c[MAX_N][MAX_N];

int main(){

  cin >> n >> m >> k;
  REP( i , n )
    cin >> a[i];
  
  REP( i , k ){
    int x, y;
    cin >> x >> y; x--; y--;
    cin >> c[x][y];
  }

  REP( i , 1<<n )
    REP( j , n )
    dp[i][j] = -INFLL;

  REP( i , n )
    dp[1<<i][i] = a[i];
  
  REP( i , 1<<n )
    REP( j , n )
    REP( k , n )
    if( ( i & (1<<k) ) == 0 )
      chmax( dp[ i | (1<<k) ][k] , dp[i][j] + a[k] + c[j][k] );

  ll ans = -INFLL;
  REP( i , 1<<n )
    REP( j , n )
    if( __builtin_popcount( i ) == m )
      chmax( ans , dp[i][j] );

  /*
  REP( i , 1<<n ){
    REP( j , n )
    cout << dp[i][j] << " ";
    cout << endl;
  }
  */

  cout << ans << endl;
  
  return 0;
}