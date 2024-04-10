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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int P = 18;
const int MAX_N = PW(P);

ll sz, k;

ll a[MAX_N];
ll s[P][MAX_N];

void init( int l , int r , int d ){
  if( d == P ) return;
  sort( s[d] + l , s[d] + r );
  init( l , (l+r)/2 , d+1 );
  init( (l+r)/2 , r , d+1 );
}

ll count( ll x , ll l , ll r , ll d ){
  ll md = (l+r)/2;
  ll it = l;
  ll res = 0;
  FOR( i , md , r ){
    if( s[d][i] == INFLL ) break;
    while( it < md && s[d][i] - s[d][it] >= x ) it++;
    res += it - l;
  }
  return res;
}

ll count( ll x ){
  ll res = 0;
  FOR( i , 1 , P ){
    for( ll l = 0; l < PW(P-1); l += PW(i) ) res += count( x , l , l+PW(i) , P-i );
  }
  return res;
}

int main(){

  scanf( "%lld %lld" , &sz , &k );
  REP( i , sz ) scanf( "%lld" , &a[i] );
  REP( i , sz ) s[0][i+1] = s[0][i] + a[i];
  FOR( i , sz , PW(P-1) ) s[0][i+1] = INFLL;

  FOR( i , 1 , P ) REP( j , PW(P-1) ) s[i][j] = s[0][j];

  init( 0 , PW(P-1) , 0 );

  ll lb = -INFLL, ub = INFLL;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( count( md ) >= k ) lb = md;
    else ub = md;
  }

  printf( "%lld\n" , lb );
  
  return 0;
}