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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

int n, m;
int a[MAX_N];

char t[MAX_N];
int p[MAX_N];

int dp[1<<20][21];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );
  sort( a , a+n ); reverse( a , a+n );
  scanf( "%d\n" , &m );
  
  REP( i , m ) scanf( "%c %d\n" , &t[i] , &p[i] );

  for( int i = m-1; i >= 0; i-- ){
    REP( j , 1<<m ){
      if( __builtin_popcount( j ) != i ) continue;
      if( p[i] == 1 ){
	dp[j][i] = -INF;
	REP( k , m ) if( !( j & (1<<k) ) ){
	  if( t[i] == 'b' ) chmax( dp[j][i] , dp[ j | (1<<k) ][ i+1 ] );
	  if( t[i] == 'p' ) chmax( dp[j][i] , dp[ j | (1<<k) ][ i+1 ] + a[k] );
	}
      } else {
	dp[j][i] = INF;
	REP( k , m ) if( !( j & (1<<k) ) ){
	  if( t[i] == 'b' ) chmin( dp[j][i] , dp[ j | (1<<k) ][ i+1 ] );
	  if( t[i] == 'p' ) chmin( dp[j][i] , dp[ j | (1<<k) ][ i+1 ] - a[k] );
	}
      }      
    }
  }
  
  printf( "%d\n" , dp[0][0] );
  
  return 0;
}