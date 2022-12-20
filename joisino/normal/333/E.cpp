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

const int MAX_N = 3010;

bitset<MAX_N> G[MAX_N];

typedef pair<double,int> di;

vector<di> v;

int n;
int x[MAX_N], y[MAX_N];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d %d" , &x[i] , &y[i] );

  REP( i , n ) REP( j , i ) v.pb( hypot( x[i] - x[j] , y[i] - y[j] ) / 2.0 , i * n + j );
  SORT( v );
  REVERSE( v );

  YYS( w , v ){
    int a = w.se / n, b = w.se % n;
    if( ( G[a] & G[b] ) != 0 ){
      printf( "%.18lf\n" , w.fi );
      break;
    }
    G[a][b] = G[b][a] = 1;
  }
  
  return 0;
}