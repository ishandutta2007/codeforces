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

const ll MAX_N = 3010;

ll n;
vpl G[MAX_N];

ll ans = INFLL;

pl dfs( ll x , ll p ){
  ll res = INFLL;
  ll tot = 0;
  YYS( w , G[x] ) if( w.fi != p ){
    pl ret = dfs( w.fi , x );
    ret.fi += 1 - w.se;
    ret.se += w.se;
    tot += ret.se;
    chmin( res , ret.fi - ret.se );
  }
  res += tot;
  chmin( res , tot );
  return pl( res , tot );
}

int main(){

  scanf( "%lld" , &n );
  REP( i , n-1 ){
    ll a, b;
    scanf( "%lld %lld" , &a , &b ); a--; b--;
    G[a].pb( b , 0 );
    G[b].pb( a , 1 );
  }

  REP( r , n ){
    ll tot = 0;
    ll maa = 0, mab = 0;
    YYS( w , G[r] ){
      pl res = dfs( w.fi , r );
      res.fi += 1 - w.se;
      res.se += w.se;
      tot += res.se;
      if( maa < res.se - res.fi ) mab = maa, maa = res.se - res.fi;
      else if( mab < res.se - res.fi ) mab = res.se - res.fi;
    }
    // cout << r << " " << tot << " " << maa << " " << mab << endl;
    tot -= maa + mab;
    chmin( ans , tot );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}