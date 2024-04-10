#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
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

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int p[MAX_N];
int n, m;
vi G[MAX_N];
bool used[MAX_N];
vi ans;

void dfs( int x ){
  used[x] = true;
  ans.pb( x );
  p[x] = 1 - p[x];
  
  REPR( w , G[x] ){
    if( !used[w] ){
      dfs( w );
      if( p[w] == 1 ){
	ans.pb( x );
	p[x] = 1 - p[x];
	ans.pb( w );
	p[w] = 0;
      }
      ans.pb( x );
      p[x] = 1 - p[x];      
    }
  }
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ) scanf( "%d" , &p[i] );

  REP( i , n ){
    if( p[i] == 1 ){
      dfs( i );
      if( p[i] == 1 ){
	reverse( ALL(ans) );
	ans.pop_back();
	reverse( ALL(ans) );
	p[i] = 0;
      }
      break;
    }
  }

  REP( i , n )
    if( p[i] == 1 )
      return puts( "-1" );

  printf( "%d\n" , ans.size() );
  REP( i , ans.size() )
    printf( "%d%c" , ans[i]+1 , (i+1!=ans.size()?' ':'\n' ) );

  
  return 0;
}