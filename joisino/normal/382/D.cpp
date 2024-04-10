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

const ll MAX_N = 2010;

ll n, m;
char s[MAX_N][MAX_N];

bool f;
int depth[MAX_N][MAX_N], cmp[MAX_N][MAX_N], cnt[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];

pi que[MAX_N*MAX_N];

int k;
void bfs( int i , int j ){
  ll a = 0, b = 0;
  que[b++] = pi( i , j );
  depth[i][j] = 1;
  while( b > a ){
    int y = que[a].fi;
    int x = que[a].se;
    a++;
    cmp[y][x] = k;
    if( s[y][x+1] == '<' ){
      depth[y][x+1] = depth[y][x]+1;
      que[b++] = pi( y , x+1 );
    }
    if( s[y][x-1] == '>' ){
      depth[y][x-1] = depth[y][x]+1;
      que[b++] = pi( y , x-1 );
    }
    if( s[y+1][x] == '^' ){
      depth[y+1][x] = depth[y][x]+1;
      que[b++] = pi( y+1 , x );
    }
    if( s[y-1][x] == 'v' ){
      depth[y-1][x] = depth[y][x]+1;
      que[b++] = pi( y-1 , x );
    }
  }
}

void bfs2( int i , int j ){
  ll a = 0, b = 0;
  que[b++] = pi( i , j );
  while( b > a ){
    int y = que[a].fi;
    int x = que[a].se;
    a++;
    if( cmp[y][x] == k ){
      f = true;
      return;
    }
    if( cmp[y][x] != 0 ) continue;
    cmp[y][x] = k;
    if( s[y][x] == '<' ) que[b++] = pi( y , x-1 );
    if( s[y][x] == '>' ) que[b++] = pi( y , x+1 );
    if( s[y][x] == '^' ) que[b++] = pi( y-1 , x );
    if( s[y][x] == 'v' ) que[b++] = pi( y+1 , x );
  }
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );

  k = 1;
  REP( i , n ) REP( j , m ) if( !used[i][j] ){
    bfs2( i , j );
    k++;
  }

  if( f ){
    printf( "-1\n" );
    return 0;
  }

  k = 0;
  REP( i , n ) REP( j , m ) if( s[i][j] == '#' ){
    if(        s[i][j+1] == '<' ){ bfs( i , j+1 ); k++; }
    if( j>0 && s[i][j-1] == '>' ){ bfs( i , j-1 ); k++; }
    if(        s[i+1][j] == '^' ){ bfs( i+1 , j ); k++; }
    if( i>0 && s[i-1][j] == 'v' ){ bfs( i-1 , j ); k++; }
  }
  
  int maxd = 0;
  REP( i , n ) REP( j , m ) chmax( maxd , depth[i][j] );

  vi cand(0);
  REP( i , n ) REP( j , m ) if( depth[i][j] == maxd ) cand.pb( cmp[i][j] );
  SORT( cand ); UNIQUE( cand );

  if( maxd == 0 ){
    printf( "0\n" );
  } else if( SZ(cand) >= 2 ){
    printf( "%d\n" , 2*maxd );
  } else {
    printf( "%d\n" , 2*maxd-1 );
  }
  

  return 0;
}