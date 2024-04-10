#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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

const int MAX_N = 1024;

int n, m;

char field[MAX_N][MAX_N];
int sy, sx, leny, lenx;
int sum[MAX_N][MAX_N];
int ans = INF;

int get( int top , int left , int bottom , int right ){
  return sum[bottom][right] - sum[bottom][left] - sum[top][right] + sum[top][left];
}

bool check( int y , int x , int h , int w , int total ){
  if( get( y , x , y+h , x+w ) != 0 ) return false;
  if( n*m-sum[n][m] == total ) return true;

  if( y + h < n && get( y , x+1 , y+h , x+1+w ) != 0 ) return check( y+1 , x , h , w , total + w );
  if( x + w < m && get( y+1 , x , y+1+h , x+w ) != 0 ) return check( y , x+1 , h , w , total + h );

  return false;
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , field[i] );
  
  REP( i , n+1 ) REP( j , m+1 ) sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + ( i == n || j == m || field[i][j] == '.' ? 1 : 0 );
  for( int i = n-1; i >= 0; i-- ) for( int j = m-1; j >= 0; j-- ) if( field[i][j] == 'X' ) sy = i, sx = j;

  while( sy+leny < n && field[sy+leny][sx] == 'X' ) leny++;
  while( sx+lenx < m && field[sy][sx+lenx] == 'X' ) lenx++;

  FOR( j , 1 , m+1 ) if( sx+j <= m && check( sy , sx , leny , j , leny*j ) ) chmin( ans , leny*j );
  FOR( i , 1 , n+1 ) if( sy+i <= n && check( sy , sx , i , lenx , i*lenx ) ) chmin( ans , i*lenx );

  if( ans == INF ) printf( "-1\n" );
  else printf( "%d\n" , ans );

  return 0;
}