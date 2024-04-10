#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 5010;

int n;
ll h[MAX_N];

ll dp[MAX_N][MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &h[i] );

  REP( i , MAX_N ) REP( j , MAX_N ) dp[i][j] = INF;
  REP( i , MAX_N ) dp[0][i] = 0;
    
  REP( i , n ){
    FOR( j , 1 , MAX_N ) chmin( dp[i][j] , dp[i][j-1] );
    ll sum = 0;
    int p = n;
    FOR( j , i , n ){
      sum += h[j];
      while( p > 0 && dp[i][p-1] <= sum ) p--;
      if( dp[i][p] <= sum ) chmin( dp[j+1][p+j-i] , sum );
    }
  }

  REP( i , MAX_N ) if( dp[n][i] < INF ){
    cout << i << endl;
    return 0;
  }
  
  return 0;
}