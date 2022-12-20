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

vi compress( vi a ){
  vi ord = a, res;
  SORT( ord );
  ord.erase( unique( ALL(ord) ) , ord.end() );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

const int MAX_N = 100010;

int n;
vi c;

int cnt[MAX_N*2];
vi v;
int ans = INF;

int main(){

  scanf( "%d" , &n );
  c.resize( 2*n );
  REP( i , 2*n ) scanf( "%d" , &c[i] );
  c = compress( c );
  YYS( w , c ) cnt[w]++;
  REP( i , MAX_N*2 ) if( cnt[i] >= (n+1)/2 ) v.pb( i );
  YYS( w , v ){
    int res = 0;
    REP( i , n ) if( c[i*2] == w || c[i*2+1] == w ) res++;
    if( res < (n+1)/2 ) continue;
    res = 0;
    REP( i , 2*n ) if( c[i] == w && i % 2 == 0 ) res++;
    chmin( ans , max( 0 , (n+1)/2 - res ) );
  }
  if( ans == INF ) return puts( "-1" );
  cout << ans << endl;
  
  return 0;
}