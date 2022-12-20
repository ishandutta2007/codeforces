#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 24;

int n;
int c[MAX_N];

int dp[12][1<<12];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &c[i] );
  vi v;
  REP( i , n ) if( c[i] != 1 ) v.pb( c[i] );
  int m = v.size();  
  int leaf = n - m;
  SORT( v );
  if( m == 0 ){
    if( n == 1 ) return puts( "YES" );
    else return puts( "NO" );
  }
  if( v.back() != n ) return puts( "NO" );
  if( m >= 12 ) return puts( "NO" );
  if( v[0] == 2 ) return puts( "NO" );


  REP( i , m ) REP( j , PW(m) ) dp[i][j] = INF;
  REP( i , m ) dp[1][PW(i)] = v[i];
  
  REP( j , PW(m) ){
    REP( i , m ){
      REP( k , PW(m) ) if( ( k & j ) == j ) chmin( dp[i+1][k] , dp[i][j] + dp[1][k^j] );
      REP( k , m ) if( !( j & PW(k) ) && v[k] > dp[i][j] && v[k] - 1 - dp[i][j] + i >= 2 ){
	chmin( dp[1][j|PW(k)] , v[k] );
      }
    }
  }

  if( dp[1][PW(m)-1] == n ) puts( "YES" );
  else puts( "NO" );
  
  return 0;
}