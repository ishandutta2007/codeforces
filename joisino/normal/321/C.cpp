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


int n;
vi G[MAX_N];

int a, b;
int ans[MAX_N];
bool ng;


pi diameter_dfs( int x , int p ){
  pi res = pi( 0 , x );
  YYS( w , G[x] ) if( w != p ){
    pi ret = diameter_dfs( w , x );
    ret.fi++;
    if( res.fi < ret.fi ) res = ret;
  }
  return res;
}
int diameter( int x = 0 ){
  pi resf = diameter_dfs( x , -1 );
  pi ress = diameter_dfs( resf.se , -1 );
  return ress.fi;
}

vi center_dist[2];
void center_dfs( int x , int p , int d , int t ){
  center_dist[t][x] = d;
  YYS( w , G[x] ) if( w != p ) center_dfs( w , x , d+1 , t );
}
int center( int n , int x = 0 ){
  center_dist[0] = center_dist[1] = vi(n);
  pi resf = diameter_dfs( x , -1 );
  pi ress = diameter_dfs( resf.se , -1 );
  center_dfs( resf.se , -1 , 0 , 0 );
  center_dfs( ress.se , -1 , 0 , 1 );
  if( ress.fi % 2 == 0 ){
    REP( i , n ) if( center_dist[0][i] == center_dist[1][i] ) return i;
  } else {
    REP( i , n ) if( center_dist[0][i] == center_dist[1][i]+1 ) return i;
  }
}


int dfs( int x , int p ){
  int f = 0;
  int cnt[26];
  REP( i , 26 ) cnt[i] = 0;
  YYS( w , G[x] ) if( w != p ){
    int res = dfs( w , x );
    REP( i , 26 ) if( res & ( 1 << i ) ) cnt[i]++;
    f |= res;
  }
  int st = 0;
  REP( i , 26 ) if( cnt[i] >= 2 ) st = i+1;
  FOR( i , st , 30 ){
    if( !( f & (1<<i) ) ){
      ans[x] = i;
      f |= 1<<i;
      REP( j , i ) if( f & (1<<j) ) f -= 1<<j;
      break;
    }
    if( i == 25 ) ng = true;
  }
  return f;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  int c = center( n );
  dfs( c , -1 );  

  if( ng ) return puts( "Impossible!" );
  
  REP( i , n ) printf( "%c%c" , 'Z'-ans[i] , i == n-1 ? '\n' : ' ' );
  
  return 0;
}