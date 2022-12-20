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

const int MAX_N = 192;

int dp[MAX_N][MAX_N*MAX_N];
int a[MAX_N];

int n, k, s;

int ans = INF;

int main(){

  scanf( "%d %d %d" , &n , &k , &s );
  REP( i , n ) scanf( "%d" , &a[i] );

  REP( i , MAX_N ) REP( j , MAX_N*MAX_N ) dp[i][j] = INF;
  dp[0][0] = 0;
  
  REP( i , n ) for( ll j = i; j >= 0; j-- ) REP( k , i*(i+1)/2+1 ) chmin( dp[j+1][k+i-j] , dp[j][k] + a[i] );

  REP( i , min(s,n*(n+1)/2)+1 ) chmin( ans , dp[k][i] );

  printf( "%d\n" , ans );
  
  return 0;
}