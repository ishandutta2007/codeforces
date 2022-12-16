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

const ll MAX_N = 100010;

typedef pair<ld,ll> st;

ll k, n, m;
ll a[MAX_N];
ll t[MAX_N], c[MAX_N], b[MAX_N];

vpl x[MAX_N][3];
vector<st> v;

vpl ans;

int main(){

  scanf( "%lld %lld %lld" , &k , &n , &m );
  REP( i , k ) scanf( "%lld" , &a[i] );
  REP( i , n ) scanf( "%lld %lld %lld" , &t[i] , &c[i] , &b[i] ), t[i]--, c[i]--;

  REP( i , n ) x[ c[i] ][ t[i] ].pb( b[i] , i );
  REP( i , k ){
    if( !x[i][0].empty() ){
      SORT( x[i][0] );
      x[i][0].back().fi -= a[i];
      x[i][1].pb( x[i][0].back() );
    }
    
    SORT( x[i][1] );
    REVERSE( x[i][1] );
    
    YYS( w , x[i][1] ){
      v.pb( ld(a[i]+w.fi)/ld(a[i]) , w.se );
      a[i] += w.fi;
    }
    
    YYS( w , x[i][2] ) v.pb( w );
  }

  SORT( v );
  REVERSE( v );

  REP( i , min( SZ(v) , m ) ) if( v[i].fi > 1 ) ans.pb( t[ v[i].se ] , v[i].se );
  SORT( ans );

  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i].se+1 , i == SZ(ans)-1 ? '\n' : ' ' );

  return 0;
}