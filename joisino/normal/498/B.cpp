#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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

const int MAX_N = 5010;

int n, st;
double pp[MAX_N];
int et[MAX_N];

double p[MAX_N];
double dp[MAX_N][MAX_N];

int main(){

  cin >> n >> st;
  REP( i , n ){
    cin >> p[i] >> et[i];
    p[i] /= 100.0;
  }

  double e = 1.0;
  FOR( i , 1 , et[0] ){
    dp[0][i] = e * p[0];
    e *= 1 - p[0];
  }
  dp[0][et[0]] = e;

  int sum = et[0];
  FOR( i , 1 , n ){
    int t = et[i];
    double q = pow( 1 - p[i] , et[i]-1 );
    sum += et[i];
    
    FOR( j , i+1 , min(st,sum)+1 ){
      dp[i][j] = dp[i][j-1];
      if( j-t-1 >= 0 ) dp[i][j] -= dp[i-1][j-t-1] * q;
      dp[i][j] *= 1 - p[i];
      dp[i][j] += dp[i-1][j-1] * p[i];
      if( j-t >= 0 ) dp[i][j] += dp[i-1][j-t] * q * ( 1 - p[i] );
    }
  }
  
  double ans = 0.0;
  REP( i , n )
    FOR( j , i+1 , st+1 )
    ans += dp[i][j];

  cout << setprecision(16) << ans << endl;
  
  return 0;
}