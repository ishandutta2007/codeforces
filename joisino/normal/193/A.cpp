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

const int MAX_N = 64;

const int dy[] = { 1 , 0 , -1 , 0 };
const int dx[] = { 0 , -1 , 0 , 1 };

int n, m;
char cs[MAX_N][MAX_N];

int cnt;
int c;

int sy, sx;

bool used[MAX_N][MAX_N];

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs( int y , int x ){
  used[y][x] = true;
  c++;
  REP( i , 4 ){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if( isin( ny , nx ) && cs[ny][nx] == '#' && !used[ny][nx] ) dfs( ny , nx );
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , cs[i] );

  REP( i , n ) REP( j , m ) if( cs[i][j] == '#' ) cnt++;

  if( cnt <= 2 ) return puts( "-1" );

  REP( i , n ) REP( j , m ){
    if( cs[i][j] == '#' ){
      cs[i][j] = '.';
      REP( k , n ) REP( l , m ) used[k][l] = false;
      c = 0;

      REP( k , n ) REP( l , m ) if( cs[k][l] == '#' ) sy = k, sx = l;
      
      dfs( sy , sx );
      if( c < cnt-1 ) return puts( "1" );
      
      cs[i][j] = '#';
    }
  }

  puts( "2" );

  return 0;
}