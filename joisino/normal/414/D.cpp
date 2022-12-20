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

const int MAX_N = 100010;

ll m, k, p;
vi G[MAX_N];

ll cnt[MAX_N];
ll sum[MAX_N];
ll ssum[MAX_N];

void dfs( int x , int p , int d ){
  cnt[d]++;
  YYS( w , G[x] ) if( w != p ) dfs( w , x , d+1 );
}

ll calc( ll x , ll y ){
  return ssum[y+1] - ssum[x] - ( sum[y+1] - sum[x] ) * ( MAX_N - y );
}

bool check( ll x , ll y ){
  return calc( x , y ) <= p;
}

int main(){

  scanf( "%lld %lld %lld" , &m , &k , &p );
  REP( i , m-1 ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 , 0 );

  REP( i , MAX_N ) sum[i+1] = sum[i] + cnt[i];
  REP( i , MAX_N ) ssum[i+1] = ssum[i] + cnt[i] * (MAX_N-i);

  ll ans = 0;
  FOR( i , 1 , m+1 ){
    ll lb = 0, ub = i;
    while( ub - lb > 1 ){
      ll md = ( lb + ub ) / 2;
      if( check( md , i ) ) ub = md;
      else lb = md;
    }
    ll res = p - calc( ub , i );
    ll a = sum[i+1] - sum[ub];
    if( ub > 1 ) a += res / ( i - ub + 1 );
    chmax( ans , min( a , k ) );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}