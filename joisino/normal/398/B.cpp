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
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 2010;

double dp[MAX_N][MAX_N];

int n, m;

bool cf[MAX_N], rf[MAX_N];
int cc, rc;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    cf[a] = rf[b] = true;
  }

  REP( i , n ){
    if( cf[i] ) cc++;
    if( rf[i] ) rc++;
  }

  for( ll i = n-1; i >= 0; i-- ) dp[i][n] = (double)n / (double)( n - i ) + dp[i+1][n];
  for( ll j = n-1; j >= 0; j-- ) dp[n][j] = (double)n / (double)( n - j ) + dp[n][j+1];
  for( ll i = n-1; i >= 0; i-- ){
    for( ll j = n-1; j >= 0; j-- ){
      dp[i][j] = (double)n*n + (double)(n-i)*j*dp[i+1][j] + (double)i*(n-j)*dp[i][j+1] + (double)(n-i)*(n-j)*dp[i+1][j+1];
      dp[i][j] /= (double)(n*n-i*j);
    }
  }

  printf( "%.18lf\n" , dp[cc][rc] );
  
  return 0;
}