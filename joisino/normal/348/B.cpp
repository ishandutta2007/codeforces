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

vi G[MAX_N];
ll a[MAX_N];
ll sum;
int n, x, y;

pl dfs( int x , int p ){
  if( p != -1 && G[x].size() == 1 ) return pl( a[x] , 1 );
  ll lcm = 1, mn = INFLL, cnt = 0, cnt2 = 0;
  YYS( w , G[x] ) if( w != p ){
    pl res = dfs( w , x );
    if( lcm <= INF ) lcm = lcm * res.se / __gcd( lcm , res.se );
    cnt += res.se; cnt2++;
    chmin( mn , res.fi );
  }
  if( lcm == 0 ) return pl( 0 , cnt2*lcm );
  return pl( mn/lcm*lcm*cnt2 , cnt2*lcm );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) sum += a[i];
  REP( i , n-1 ){
    scanf( "%d %d" , &x , &y ); x--; y--;
    G[x].pb( y );
    G[y].pb( x );
  }

  printf( "%lld\n" , sum - dfs( 0 , -1 ).fi );
  
  return 0;
}