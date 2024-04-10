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

const ll MAX_N = 300010;

ll n;
pl a[MAX_N];

ll ne[MAX_N], pr[MAX_N];

ld ans;

int main(){

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i].fi );
  REP( i , n ) ne[i] = i + 1, pr[i] = i - 1;
  REP( i , n ) a[i].se = i;

  sort( a , a + n );

  REP( i , n ){
    ll x = a[i].se;
    ld resr = 0.0, base = 0.5;
    ll cnt = 0;
    while( cnt++ < 100 && x < n ){
      resr += ( ne[x] - x ) * base;
      x = ne[x];
      base *= 0.5;
    }

    x = a[i].se;
    ld resl = 0.0; base = 0.5;
    cnt = 0;
    while( cnt++ < 100 && x >= 0 ){
      resl += ( x - pr[x] ) * base;
      x = pr[x];
      base *= 0.5;
    }

    x = a[i].se;
    if( ne[x] != n  ) pr[ne[x]] = pr[x];
    if( pr[x] != -1 ) ne[pr[x]] = ne[x];
    ans += ( resl * resr * 2 * a[i].fi ) / ld( n * n );
  }

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}