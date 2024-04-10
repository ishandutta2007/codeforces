#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

// head

const int MAX_N = 64;
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };
const int ccp[] = { 1 , -1 };

int n, m, pc;
char s[MAX_N][MAX_N];

int pr[MAX_N][MAX_N][4][2];

pi memo[MAX_N][MAX_N][4];

pi nex( int y , int x , int d ){
  if( memo[y][x][d].fi != -1 ) return memo[y][x][d];
  int ny = y, nx = x;
  while( s[y][x] == s[y+dy[d]][x+dx[d]] ){
    y += dy[d];
    x += dx[d];
  }
  return memo[ny][nx][d] = pi( y , x );
}

int main(){

  REP( i , MAX_N ) REP( j , MAX_N ) REP( k , 4 ) memo[i][j][k] = pi( -1 , -1 );
  REP( i , MAX_N ) REP( j , MAX_N ) REP( k , 4 ) REP( l , 2 ) pr[i][j][k][l] = -1;
  
  scanf( "%d %d" , &n , &pc );
  REP( i , n ) scanf( "%s" , s[i+1]+1 );
  m = strlen( s[1]+1 );

  REP( i , n+2 ) s[i][0] = s[i][m+1] = '0';
  REP( j , m+2 ) s[0][j] = s[n+1][j] = '0';

  int y = 1, x = 1, dp = 0, cp = 0;

  while( pc-- ){
    if( pr[y][x][dp][cp] != -1 ) m %= pr[y][x][dp][cp] - pc;
    pr[y][x][dp][cp] = pc;
    auto ne = nex( y , x , dp );
    ne = nex( ne.fi , ne.se , ( dp + ccp[cp] + 4 ) % 4 );
    ne = pi( ne.fi + dy[dp] , ne.se + dx[dp] );
    if( s[ne.fi][ne.se] == '0' ){
      if( cp == 0 ) cp = 1;
      else cp = 0, dp = ( dp + 3 ) % 4;
    } else {
      y = ne.fi;
      x = ne.se;
    }
  }

  printf( "%c\n" , s[y][x] );
  
  return 0;
}