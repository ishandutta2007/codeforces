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

ll n, m, p, q;

vpl G[MAX_N];

ll cmp[MAX_N];
ll re[MAX_N];
ll sum[MAX_N];

ll ca, cb;

set<pl> ss;

vpl ans;

void dfs( ll x , ll k ){
  cmp[x] = k;
  YYS( w , G[x] ){
    ca = x, cb = w.fi;
    sum[k] += w.se;
    if( cmp[w.fi] == -1 ) dfs( w.fi , k );
  }
}

int main(){

  scanf( "%lld %lld %lld %lld" , &n , &m , &p , &q );
  REP( i , m ){
    ll a, b, l;
    scanf( "%lld %lld %lld" , &a , &b , &l ); a--; b--;
    G[a].pb( b , l );
    G[b].pb( a , l );
  }

  ll k = 0;
  REP( i , n ) cmp[i] = -1;
  REP( i , n ) if( cmp[i] == -1 ){
    re[k] = i;
    dfs( i , k );
    sum[k] /= 2;
    ss.insert( pl( sum[k] , k ) );
    k++;
  }

  ll nk = k - q;
  ll od = p - nk;

  if( nk < 0 || od < 0 || ( q == n && p > 0 ) ){
    puts( "NO" );
    return 0;
  }

  REP( i , nk ){
    pl a = *ss.begin(); ss.erase( ss.begin() );
    pl b = *ss.begin(); ss.erase( ss.begin() );
    ans.pb( re[a.se] , re[b.se] );
    ca = re[a.se], cb = re[b.se];
    ss.insert( pl( a.fi + b.fi + min( a.fi + b.fi + 1 , (ll)1e9 ) , a.se ) );
  }
  
  REP( i , od ) ans.pb( ca , cb );
  
  printf( "YES\n" );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi+1 , w.se+1 );
  
  return 0;
}