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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 15;

int n, m, q;

bool G[MAX_N][MAX_N];
int lca[MAX_N][MAX_N];
ll dp[MAX_N][PW(MAX_N)];

int main(){

  scanf( "%d %d %d" , &n , &m , &q );

  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a][b] = G[b][a] = true;
  }

  REP( i , n ) REP( j , n ) lca[i][j] = -1;
  
  REP( i , q ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c ); a--; b--; c--;
    if( ( lca[a][b] != -1 && lca[a][b] != c ) || a == b && a != c ){
      printf( "0\n" );
      return 0;
    }
    lca[a][b] = lca[b][a] = c;
  }

  REP( j , PW(n) ) REP( i , n ) if( j & PW(i) ){
    if( j == PW(i) ){
      dp[i][j] = 1;
      continue;
    }
    
    int sup = j - PW(i);
    
    bool ok = true;
    REP( k , n ) if( sup & PW(k) && lca[i][k] != -1 && lca[i][k] != i ) ok = false;
    if( !ok ) continue;

    int mind = INF;
    REP( k , n ) if( sup & PW(k) ) chmin( mind , k );
    
    int sub = sup;
    do {
      if( (sub & PW(mind)) ){
	ok = true;
	REP( k , n ) if( sub & PW(k) ){
	  REP( l , n ) if( sup & PW(l) && !( sub & PW(l) ) ){
	    if( lca[k][l] != -1 && lca[k][l] != i ) ok = false;
	    if( G[k][l] ) ok = false;
	  }
	}
	
	if( ok ){
	  int ch = -1;
	  REP( k , n ) if( sub & PW(k) && G[i][k] ){
	    if( ch == -1 ) ch = k;
	    else ch = -2;
	  }
      
	  if( ch == -1 ){
	    REP( k , n ) if( sub & PW(k) ) dp[i][j] += dp[k][sub] * dp[i][j-sub];
	  } else if( ch >= 0 ){
	    dp[i][j] += dp[ch][sub] * dp[i][j-sub];
	  }
	}
      } 
      
      sub = ( sub - 1 ) & sup;
    } while( sub != sup );
  }

  printf( "%lld\n" , dp[0][PW(n)-1] );
  
  
  return 0;
}