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
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

ll memo[100010];

ll c( ll x ){
  return x * x * x;
}

ll ic( ll x ){
  ll lb = 1, ub = 100010;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( c( md ) <= x ){
      lb = md;
    } else {
      ub = md;
    }
  }
  return lb;
}

ll dfs( ll x ){
  assert( x >= 0 );
  if( memo[x] != -1 ){
    return memo[x];
  }
  if( x == 0 ){
    return 0;
  }
  return memo[x] = dfs( x - c( ic(x) ) ) + 1;
}

pl solve( ll m ){
  if( m <= 100000 ){
    ll ansv = -1;
    ll ansM = 0;
    FOR( i , 1 , m+1 ){
      ll res = dfs( i );
      if( ansv == res ){
        chmax( ansM , i );
      } else if( res > ansv ){
        ansv = res;
        ansM = i;
      }
    }
    return pl( ansv, ansM );
  }
  ll cic = ic( m );
  ll nma = m - c( cic );
  pl resa = solve( nma );
  resa.fi += 1;
  resa.se += c( cic );
  ll med = c( cic ) - 1;
  ll nmb = med - c( cic - 1 );
  pl resb = solve( nmb );
  resb.fi += 1;
  resb.se += c( cic - 1 );
  return max( resa, resb );
}

int main(){

  REP( i , 100010 ){
    memo[i] = -1;
  }
  
  ll m = in();

  auto ans = solve( m );
  
  printf( "%lld %lld\n" , ans.fi , ans.se );

  return 0;
}