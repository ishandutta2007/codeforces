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

struct edge{
  ll to, l, r;
  edge(){}
  edge( ll to, ll l , ll r ) : to(to) , l(l) , r(r) {}
};

const ll MAX_N = 1010;

ll n, m;
vl candl;
vector<edge> G[MAX_N];
ll ans;

bool used[MAX_N];

void dfs( ll x , ll l , ll r ){
  used[x] = true;
  YYS( w , G[x] ) if( !used[w.to] && w.l <= l && r <= w.r ) dfs( w.to , l , r );
}

bool check( ll l , ll r ){
  REP( i , n ) used[i] = false;
  dfs( 0 , l , r );
  return used[n-1];
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , m ){
    ll a, b, l, r;
    scanf( "%lld %lld %lld %lld" , &a , &b , &l , &r ); a--; b--;
    G[a].pb( b , l , r );
    G[b].pb( a , l , r );
    candl.pb( l );
  }

  YYS( l , candl ){
    ll lb = -1, ub = INF;
    while( ub - lb > 1 ){
      ll md = ( lb + ub ) / 2;
      if( check( l , l+md ) ) lb = md;
      else ub = md;
    }
    chmax( ans , lb+1 );
  }

  if( ans == 0 ) printf( "Nice work, Dima!\n" );
  else printf( "%lld\n" , ans );
  
  return 0;
}