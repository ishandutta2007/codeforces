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

ll v[MAX_N];

vi G[MAX_N];
int a, b;

pl dfs( int x , int p ){
  pl res = pl( 0 , 0 );
  YYS( w , G[x] ) if( p != w ){
    pl ret = dfs( w , x );
    chmax( res.fi , ret.fi );
    chmax( res.se , ret.se );
  }
  v[x] += res.fi;
  v[x] -= res.se;
  if( v[x] < 0 ) return pl( res.fi + abs(v[x]) , res.se );
  else return pl( res.fi , res.se + abs(v[x]) );
  
}

int main(){

  scanf( "%d" , &n );
  REP( i , n-1 ){
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }
  REP( i , n ) scanf( "%lld" , &v[i] );
  
  pl res = dfs( 0 , -1 );

  cout << res.fi + res.se << endl;
  
  return 0;
}