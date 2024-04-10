#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
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

const int MAX_N = 300010;

ll n, k;
vec a;

ll sum[MAX_N];

vector<vec> dp;

int main(){

  cin >> n >> k;
  REP( i , n )
    a.pb( in() );

  sort( ALL(a) );

  REP( i , n )
    sum[i+1] = sum[i] + a[i+1] - a[i];

  ll p = n/k;

  dp = vector<vec>( k+1 , vec( k+1 , INFLL ) );
  
  dp[0][0] = 0;
  REP( i , k ){
    REP( j , i+1 ){
      ll s = p * i + j;
      chmin( dp[i+1][j  ] , dp[i][j] + sum[s+p-1] - sum[s] );
      chmin( dp[i+1][j+1] , dp[i][j] + sum[s+p ] - sum[s] );
    }
  }

  cout << dp[k][n%k] << endl;

  return 0;
}