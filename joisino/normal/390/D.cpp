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

const ll MAX_N = 128;

ll n, m, k;

vpl man[MAX_N];

ll ans;
vpl ansp[MAX_N*MAX_N];

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &k );
  REP( i , n ) REP( j , m ) man[i+j].pb( i , j );

  REP( candy_cnt , k ){
    ll p = 0;
    while( man[p].empty() ) p++;
    ans += p+1;
    pl to = man[p].back(); man[p].pop_back();
    REP( i , to.fi+1 ) ansp[candy_cnt].pb( i , 0 );
    FOR( i , 1 , to.se+1 ) ansp[candy_cnt].pb( to.fi , i );
  }

  printf( "%lld\n" , ans );
  for( ll i = k-1; i >= 0; i-- ){
    YYS( w , ansp[i] ) printf( "(%lld,%lld) " , w.fi+1 , w.se+1 );
    printf( "\n" );
  }
  
  return 0;
}