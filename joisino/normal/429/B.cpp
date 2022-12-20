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

const int MAX_N = 1010;
const int dx[] = { 1 , 0 };
const int dy[] = { 0 , 1 };

int n, m;
ll a[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];
ml dist[2][2];

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs( int sy, int sx, int py, int px, ml &d ){
  REP( i , n ) REP( j , m ) d[i][j] = -INFLL;
  REP( i , n ) REP( j , m ) used[i][j] = false;
  d[sy][sx] = a[sy][sx];
  used[sy][sx] = true;
  queue<pi> que;
  que.push( pi( sy , sx ) );
  while( !que.empty() ){
    int y = que.front().fi;
    int x = que.front().se;
    que.pop();
    REP( i , 2 ){
      int ny = y + dy[i]*py;
      int nx = x + dx[i]*px;
      if( isin( ny, nx ) ){
	chmax( d[ny][nx] , d[y][x] + a[ny][nx] );
	if( !used[ny][nx] ) que.push( pi( ny , nx ) );
	used[ny][nx] = true;
      }
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &a[i][j] );
  REP( i , 2 ) REP( j , 2 ) dist[i][j] = ml( n , vl( m ) );

  bfs( 0   , 0   , 1  , 1  , dist[0][0] );
  bfs( n-1 , m-1 , -1 , -1 , dist[0][1] );  
  bfs( n-1 , 0   , -1 , 1  , dist[1][0] );
  bfs( 0   , m-1 , 1  , -1 , dist[1][1] );

  ll ans = 0;
  FOR( i , 1 , n-1 ){
    FOR( j , 1 , m-1 ){
      chmax( ans , dist[0][0][i-1][j] + dist[0][1][i+1][j] + dist[1][0][i][j-1] + dist[1][1][i][j+1] );
      chmax( ans , dist[0][0][i][j-1] + dist[0][1][i][j+1] + dist[1][0][i+1][j] + dist[1][1][i-1][j] );
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}