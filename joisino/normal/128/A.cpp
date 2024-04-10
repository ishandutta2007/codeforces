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

const int dx[] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
const int dy[] = { 0 , -1 , -1 , -1 , 0 , 1 , 1 , 1 };

const int MAX_N = 12;

char field[MAX_N][MAX_N];

vpi statues;

int sy, sx, gy, gx;

bool win = false;
bool used[MAX_N][MAX_N][128];

bool accessible( int y , int x , int turn ){
  if( !( 0 <= y && y < 8 && 0 <= x && x < 8 ) ) return false;
  YYS( w , statues ) if( ( w.fi + turn == y || w.fi + turn + 1 == y ) && w.se == x ) return false;
  return true;
}

void dfs( int y , int x , int turn ){
  if( used[y][x][turn] ) return;
  if( win ) return;
  used[y][x][turn] = true;

  if( y == gy && x == gx ){
    win = true;
    return;
  }

  REP( i , 8 ){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if( accessible( ny , nx , turn ) ) dfs( ny , nx , turn+1 );
  }

  if( accessible( y , x , turn ) ) dfs( y , x , turn+1 );
}

int main(){

  REP( i , 8 ) scanf( "%s" , field[i] );

  REP( i , 8 ) REP( j , 8 ){
    if( field[i][j] == 'M' ) sy = i, sx = j;
    if( field[i][j] == 'A' ) gy = i, gx = j;
    if( field[i][j] == 'S' ) statues.pb( i , j );
  }
  
  dfs( sy , sx , 0 );

  if( win ) puts( "WIN" );
  else puts( "LOSE" );
  
  return 0;
}