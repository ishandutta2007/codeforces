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
const string s = "RLUD";

ll n;
pl p[MAX_N];

vpl ans;

bool cmp( pl x , pl y ){
  return abs( x.fi ) + abs( x.se ) < abs( y.fi ) + abs( y.se );
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld %lld" , &p[i].fi , &p[i].se );

  sort( p , p+n , cmp );

  REP( i , n ){
    ll x = p[i].fi;
    ll y = p[i].se;

    if( x > 0 ) ans.pb( 0 , x );
    if( x < 0 ) ans.pb( 1 , -x );
    if( y > 0 ) ans.pb( 2 , y );
    if( y < 0 ) ans.pb( 3 , -y );

    ans.pb( 4 , 0 );
    
    if( y > 0 ) ans.pb( 3 , y );
    if( y < 0 ) ans.pb( 2 , -y );
    if( x > 0 ) ans.pb( 1 , x );
    if( x < 0 ) ans.pb( 0 , -x );

    ans.pb( 5 , 0 );
  }

  printf( "%lld\n" , SZ(ans) );
  YYS( w , ans ){
    if( w.fi < 4 ) printf( "1 %lld %c\n" , w.se , s[w.fi] );
    if( w.fi == 4 ) printf( "2\n" );
    if( w.fi == 5 ) printf( "3\n" );
  }

  return 0;
}