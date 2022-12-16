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

const int MAX_M = 10024;
const int MAX_N = 128;

char s[MAX_N][MAX_M];

int a[MAX_N][MAX_M];

int n, m;

ll ans = INFLL;

int main(){

  scanf( "%d %d\n" , &n , &m );
  REP( i , n ) scanf( "%s\n" , s[i] );

  REP( i , n ) REP( j , m ) a[i][j] = INF;
  REP( i , n ) REP( j , m ) if( s[i][j] == '1' ) a[i][j] = 0;
  REP( i , n ){
    FOR( j , 1 , m ) chmin( a[i][j] , a[i][j-1] + 1 );
    chmin( a[i][0] , a[i][m-1] + 1 );
    FOR( j , 1 , m ) chmin( a[i][j] , a[i][j-1] + 1 );
    chmin( a[i][0] , a[i][m-1] + 1 );
  }
  REP( i , n ){
    for( int j = m-2; j >= 0; j-- ) chmin( a[i][j] , a[i][j+1] + 1 );
    chmin( a[i][m-1] , a[i][0] + 1 );
    for( int j = m-2; j >= 0; j-- ) chmin( a[i][j] , a[i][j+1] + 1 );
    chmin( a[i][m-1] , a[i][0] + 1 );
  }
  
  REP( j , m ){
    ll res = 0;
    REP( i , n ) res += a[i][j];
    chmin( ans , res );
  }

  if( ans >= MAX_N*MAX_M ) cout << -1 << endl;
  else cout << ans << endl;
  
  
  return 0;
}