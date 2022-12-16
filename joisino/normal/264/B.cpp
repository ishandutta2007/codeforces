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

const int MAX_N = 100010;

vl fact( ll x ){
  vl res;
  for( ll i = 2; i*i <= x; i++ ){
    while( x % i == 0 ){
      res.pb( i );
      x /= i;
    }
  }
  if( x > 1 ) res.pb( x );
  return res;
}

vi G[MAX_N];

int n;
int a[MAX_N];
int dp[MAX_N];
int dp2[MAX_N];

int ans = 1;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  sort( a , a+n );

  REP( i , n ){
    vl v = fact( a[i] );
    v.erase( unique( ALL(v) ) , v.end() );
    YYS( w , v ) chmax( dp[a[i]] , dp2[w]+1 );
    YYS( w , v ) chmax( dp2[w] , dp[a[i]] );
  }

  REP( i , MAX_N ) chmax( ans , dp[i] );
  printf( "%d\n" , ans );
  
  return 0;
}