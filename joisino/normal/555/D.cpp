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

const ll MAX_N = 200010;

ll n, m;

ll x[MAX_N], xs[MAX_N];
pl ps[MAX_N];

ll solve( ll p , ll l , ll d ){
  if( d == 0 ){
    ll ne = lower_bound( xs , xs+n , xs[p] - l ) - xs;
    if( ne == p ) return ne;
    ll de = xs[p] - xs[ne];
    l %= de * 2;
    if( l >= de ) return solve( ne , l - de , 1-d );
    else return solve( p , l , d );
  } else if( d == 1 ){
    ll ne = upper_bound( xs , xs+n , xs[p] + l ) - xs - 1;
    if( ne == p ) return ne;
    ll de = xs[ne] - xs[p];
    l %= de * 2;
    if( l >= de ) return solve( ne , l - de , 1-d );
    else return solve( p , l , d );
  }
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%lld" , &x[i] );
  REP( i , n ) xs[i] = x[i], ps[i].fi = x[i], ps[i].se = i;
  sort( ps , ps+n );
  sort( xs , xs+n );

  REP( i , m ){
    ll p, l;
    scanf( "%lld %lld" , &p , &l ); p--;
    ll id = lower_bound( xs , xs+n , x[p] ) - xs;
    ll ne = upper_bound( xs , xs+n , xs[id] + l ) - xs - 1;
    ll res = solve( ne , l - ( xs[ne] - xs[id] ) , 0 );
    printf( "%lld\n" , ps[res].se+1 );
  }
  
  return 0;
}