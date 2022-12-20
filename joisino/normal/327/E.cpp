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

const int MAX_N = 24;

int n, k;
int a[PW(MAX_N)];
int s[PW(MAX_N)];
int x[MAX_N];

int dp[PW(MAX_N)];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[PW(i)] );
  FOR( i , 1 , PW(n) ) s[i] = min( (int)INF , s[i-(i&-i)] + a[i&-i] );

  scanf( "%d" , &k );
  REP( i , k ) scanf( "%d" , &x[i] );

  dp[0] = 1;
  FOR( i , 1 , PW(n) ){
    if( s[i] == x[0] || s[i] == x[1] ) continue;
    for( int j = i; j > 0; j -= j & -j ){
      dp[i] += dp[i-(j&-j)];
      if( dp[i] >= MOD ) dp[i] -= MOD;
    }
  }

  printf( "%d\n" , dp[PW(n)-1] );
  
  return 0;
}