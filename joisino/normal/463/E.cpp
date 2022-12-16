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

vi ps;
vb isp;
int max_p;
void init_p( int mp = 1000010 ){
  max_p = mp;
  isp.resize( max_p , true );
  isp[0] = isp[1] = false;
  FOR( i , 2 , max_p ){
    if( isp[i] ){
      ps.pb( i );
      for( int j = i*2; j < max_p; j += i )
	isp[j] = false;
    }
  }
}

vl fact( ll x ){
  vl res;
  for( int i = 0; i < ps.size() && ps[i]*ps[i] <= x; i++ ){
    if( x % ps[i] == 0 ) res.pb( i );
    while( x % ps[i] == 0 ) x /= ps[i];
  }
  if( x > 1 ) res.pb( lower_bound( ALL(ps) , x ) - ps.begin() );
  return res;
}


const int MAX_N = 100010;

int n, q;
ll a[MAX_N];
vl fs[MAX_N];

vi G[MAX_N];

int ds[MAX_N];

int nq;
vi qs[MAX_N];
vi prs[2000010];

int ans[MAX_N];

void dfs( int x , int p , int d ){
  ds[x] = d;
  int res = -2;
  YYS( w , fs[x] ){
    if( prs[w].size() > 0 && ( res == -2 || ds[prs[w].back()] > ds[res] ) ) res = prs[w].back();
    prs[w].pb( x );
  }
  YYS( w , qs[x] ) ans[w] = res + 1;
  qs[x].clear();
  YYS( w , G[x] ) if( w != p ) dfs( w , x , d+1 );
  YYS( w , fs[x] ) prs[w].pop_back();
}

int main(){

  init_p( 2000010 );

  scanf( "%d %d" , &n , &q );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , n ) fs[i] = fact( a[i] );

  REP( i , n-1 ){
    int x, y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    G[x].pb( y );
    G[y].pb( x );
  }

  REP( loop_cnt , q ){
    int t, x, y;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d" , &x ); x--;
      qs[x].pb( nq++ );
    } else if( t == 2 ){
      dfs( 0 , -1 , 0 );
      scanf( "%d %d" , &x , &y ); x--;
      a[x] = y;
      fs[x] = fact( y );
    }
  }

  dfs( 0 , -1 , 0 );

  REP( i , nq ) printf( "%d\n" , ans[i] );
  
  return 0;
}