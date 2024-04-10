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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 200010;

ll e, s, n, m;

vl xs[3];

ll dp[3][MAX_N];

int main(){

  scanf( "%lld %lld %lld %lld" , &e , &s , &n , &m );
  REP( gas , n ){
    ll t, x;
    scanf( "%lld %lld" , &t , &x );
    if( x < e ) REP( i , t ) xs[i].pb( x );
  }
  REP( i , 3 ) xs[i].pb( e );
  REP( i , 3 ){
    SORT( xs[i] );
    UNIQUE( xs[i] );
  }

  REP( i , 3 ) for( int j = (int)xs[i].size()-2; j >= 0; j-- ){
    dp[i][j] = dp[i][j+1] + max( 0LL , xs[i][j+1] - xs[i][j] - s );
  }

  REP( st , m ){
    ll f, shortage[3];
    scanf( "%lld" , &f );
    REP( i , 3 ){
      int p = lower_bound( ALL(xs[i]) , f ) - xs[i].begin();
      shortage[i] = dp[i][p] + max( 0LL , xs[i][p] - f - s );
    }
    if( shortage[0] > 0 ) printf( "-1 -1\n" );
    else printf( "%lld %lld\n" , shortage[1] , shortage[2]-shortage[1] );
  }
  
  
  return 0;
}