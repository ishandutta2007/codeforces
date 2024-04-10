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

const int MAX_N = 128;

ld dp[MAX_N][MAX_N]; // cnt , len

int n, p;
int a[MAX_N];

ld ans = 0;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  scanf( "%d" , &p );

  dp[0][0] = 1.0;
  REP( i , n ) for( int j = i+1; j >= 0; j-- ) for( int k = p; k >= 0; k-- ){
      dp[j][k] = dp[j][k] * ld(i+1-j) / ld(i+1);
      if( j-1 >= 0 && k-a[i] >= 0 ) dp[j][k] += dp[j-1][k-a[i]] * (ld)j / ld(i+1);
    }

  FOR( j , 1 , n+1 ) REP( k , p+1 ) ans += dp[j][k];

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}