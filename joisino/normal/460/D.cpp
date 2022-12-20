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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

ll l, r, k;

ll eval( vl v ){
  ll res = 0;
  YYS( w , v ) res ^= w;
  return res;
}

int answer( vl ans ){
  printf( "%lld\n" , eval(ans) );
  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i] , i==SZ(ans)-1?'\n':' ' );
  return 0;
}

int main(){
  
  scanf( "%lld %lld %lld" , &l , &r , &k );
  
  if( r-l <= 9 ){
    ll ansv = INFLL;
    vl ans(0);
    FOR( mask , 1 , PW(r-l+1) ) if( __builtin_popcount( mask ) <= k ){
      vl res(0);
      REP( i , r-l+1 ) if( mask & PW(i) ) res.pb( l+i );
      if( eval(res) < ansv ) ansv = eval(res), ans = res;
    }
    return answer( ans );
  }
  
  if( k == 1 ) return answer( { l } );
  else if( k == 2 ){
    if( l % 2 == 1 ) l++;
    return answer( { l , l+1 } );
  } else if( k == 3 ){
    ll x = 0, y = 0, z = 0;
    REP( i , 64 ) if( PW(i) > l ){
      x = PW(i)-1;
      y += PW(i) + PW(i-1);
      z = y-1;
      if( max(y,z) <= r ) return answer( { x , y , z } );
      break;
    }
    if( l % 2 == 1 ) l++;
    return answer( { l , l+1 } );
  } else {
    while( l % 4 != 0 ) l++;
    return answer( { l , l+1 , l+2 , l+3 } );
  }

  return 0;
}