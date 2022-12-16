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
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll MAX_N = 310;

ll n, m, k;
ll a[MAX_N];
bool f[MAX_N];
bool G[MAX_N][MAX_N];

vpl ans;

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &k );
  REP( i , k ) scanf( "%lld" , &a[i] ), a[i]--;
  sort( a , a+n ); reverse( a , a+n );
  REP( i , k ) f[ a[i] ] = true;

  REP( i , n ) REP( j , i ) G[i][j] = G[j][i] = true;
  
  REP( i , n ) G[ a[0] ][i] = G[i][ a[0] ] = !f[i];
  
  REP( i , n ) REP( j , i ) if( G[i][j] ) ans.pb( j , i );
  SORT( ans );
  if( !G[0][a[0]] && SZ(ans) > n-2 ) REP( i , SZ(ans) ) if( ans[i].fi == a[0] || ans[i].se == a[0] ) swap( ans[n-2] , ans[i] );

  if( n == k || SZ(ans) < m ) printf( "-1\n" );
  else REP( i , m ) printf( "%lld %lld\n" , ans[i].fi+1 , ans[i].se+1 );

  return 0;
}