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

const int MAX_N = 100010;

int n, m, d;
vi G[MAX_N];
bool q[MAX_N];
int a, b;

int down[MAX_N];
int val[MAX_N];

int ans;

int dfs( int x , int p ){
  down[x] = -INF;
  if( q[x] ) down[x] = 0;
  YYS( w , G[x] ) if( w != p ){
    chmax( down[x] , dfs( w , x )+1 );
  }
  return down[x];
}

void dfs2( int x , int p , int t ){
  int mv1 = -1, mv2 = -1;
  if( q[x] ) chmax( t , 0 );
  val[x] = max( t , down[x] );
  YYS( w , G[x] ) if( w != p ){
    if( mv1 == -1 || down[w] >= down[mv1] ){
      mv2 = mv1;
      mv1 = w;
    } else if( mv2 == -1 || down[w] >= down[mv2] ){
      mv2 = w;
    }
  }
  YYS( w , G[x] ) if( w != p ){
    int nt = t;
    if( mv1 != w ) chmax( nt , down[mv1]+1 );
    else if( mv2 != -1 ) chmax( nt , down[mv2]+1 );
    dfs2( w , x , nt+1 );
  }
}

int main(){

  scanf( "%d %d %d" , &n , &m , &d );
  REP( i , m ){ scanf( "%d" , &a ); a--; q[a] = true; }
  REP( i , n-1 ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );
  dfs2( 0 , -1 , -INF );

  REP( i , n ) if( val[i] <= d ) ans++;

  printf( "%d\n" , ans );
  
  return 0;
}