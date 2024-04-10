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

const int MAX_N = 1600;
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };

int n, m;
pi used[MAX_N][MAX_N];

char field[MAX_N][MAX_N];

int sy, sx;

queue<pi> que;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , field[i] );

  REP( i , n ) REP( j , m ) if( field[i][j] == 'S' ) sy = i, sx = j;
  
  REP( i , n ) REP( j , m ) used[i][j] = pi( INF , INF );
  used[sy][sx] = pi( 0 , 0 );
  
  que.push( pi( sy , sx ) );
  while( !que.empty() ){
    int y = que.front().fi;
    int x = que.front().se;
    que.pop();
    REP( i , 4 ){
      int ny = y + dy[i];
      int nx = x + dx[i];
      int by = ny / n;
      int bx = nx / m;
      int ty = ( ( ny % n ) + n ) % n;
      int tx = ( ( nx % m ) + m ) % m;
      if( ny < 0 ) by--;
      if( nx < 0 ) bx--;
      if( field[ty][tx] == '#' ) continue;
      if( used[ty][tx] == pi( INF , INF ) ){
	used[ty][tx] = pi( by , bx );
	que.push( pi( ny , nx ) );
      } else if( used[ty][tx] != pi( by , bx ) ){
	puts( "Yes" );
	return 0;
      }
    }
  }

  puts( "No" );
  
  return 0;
}