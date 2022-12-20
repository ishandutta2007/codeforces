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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 800010;

int node[MAX_N][26];
int cnt[MAX_N];
int it = 1;
int ra, rb;
vi belong[MAX_N];

ll ans;

bool used[MAX_N];
int match[MAX_N];

void add( int x , char *s , int id ){
  belong[x].pb( id );
  if( (*s) == '\0' ) return;
  int c = (*s) - 'a';
  int nex = node[x][c];
  if( nex == 0 ) nex = node[x][c] = it++;
  cnt[nex]++;
  add( nex , s+1 , id );
}

void dfs( int x , int y ){
  if( x == 0 || y == 0 ) return;
  ans += min( cnt[x] , cnt[y] );
  REP( i , 26 ) dfs( node[x][i] , node[y][i] );

  int p = 0;
  YYS( w , belong[x] ){
    if( match[w] != 0 ) continue;
    while( p < SZ(belong[y]) && used[ belong[y][p] ] ) p++;
    if( p == SZ(belong[y]) ) break;
    match[w] = belong[y][p] + 1;
    used[  belong[y][p] ] = true;
  }
}

int n;

char s[MAX_N];

int main(){

  scanf( "%d" , &n );
  ra = it++;
  REP( i , n ){
    scanf( "%s" , s );
    add( ra , s , i );
  }

  rb = it++;
  REP( i , n ){
    scanf( "%s" , s );
    add( rb , s , i );
  }

  dfs( ra , rb );
  
  printf( "%lld\n" , ans );
  REP( i , n ) printf( "%d %d\n" , (int)i+1 , match[i] );

  return 0;
}