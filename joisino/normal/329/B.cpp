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

const int MAX_N = 1010;

const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

char field[MAX_N][MAX_N];

int n, m;
int dist[MAX_N][MAX_N];

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs( int sy , int sx ){
  queue<pi> que;
  que.push( pi( sy , sx ) );
  REP( i , n ) REP( j , m ) dist[i][j] = INF;
  dist[sy][sx] = 0;
  while( !que.empty() ){
    int y = que.front().fi;
    int x = que.front().se;
    que.pop();
    REP( i , 4 ){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if( isin( ny , nx ) && field[ny][nx] != 'T' && dist[ny][nx] == INF ){
	dist[ny][nx] = dist[y][x] + 1;
	que.push( pi( ny , nx ) );
      }
    }
  }
}

int sy, sx;
int gy, gx;
int ans;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , field[i] );

  REP( i , n ) REP( j , m ) if( field[i][j] == 'S' ) sy = i, sx = j;
  REP( i , n ) REP( j , m ) if( field[i][j] == 'E' ) gy = i, gx = j;

  bfs( sy , sx );
  int d = dist[gy][gx];
  bfs( gy , gx );
  REP( i , n ) REP( j , m ) if( dist[i][j] <= d ){
    if( '1' <= field[i][j] && field[i][j] <= '9' ) ans += field[i][j] - '0';
  }

  printf( "%d\n" , ans );
  
  return 0;
}