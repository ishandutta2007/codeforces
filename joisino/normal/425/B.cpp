#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
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

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 128;

int n, m, k;
int a[MAX_N][MAX_N];
int b[MAX_N];
int ans = INF;

int main(){

  scanf( "%d %d %d" , &n , &m , &k );
  REP( i , n ) REP( j , m ) scanf( "%d" , &a[i][j] );

  
  if( m <= 2*k+1 ){
    REP( i , n ) REP( j , m ) if( a[i][j] ) b[i] += 1<<j;
    REP( i , 1<<m ){
      int res = 0;
      REP( j , n ){
	int r = __builtin_popcount( i ^ b[j] );
	res += min( r , m-r );
      }
      chmin( ans , res );
    }
  } else {
    REP( i , n ){
      int r = 0;
      REP( j , m ) if( a[i][j] != a[0][j] ) r++;
      if( r > m-r ) REP( j , m ) a[i][j] ^= 1;
    }
    ans = 0;
    REP( j , m ){
      int r = 0;
      REP( i , n ) r += a[i][j];
      ans += min( r , n-r );
    }
  }

  if( ans > k ) printf( "-1\n" );
  else printf( "%d\n" , ans );
  
  return 0;
}