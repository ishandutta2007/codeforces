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

ll a, b, c;

vl ans;

ll s( ll x ){
  ll res = 0;
  while( x > 0 ) res += x % 10, x /= 10;
  return res;
}

int main(){

  scanf( "%lld %lld %lld" , &a , &b , &c );
  FOR( i , 1 , 100 ){
    ll x = 1;
    REP( j , a ) x *= i;
    x *= b;
    x += c;
    if( s(x) == i && x < (ll)1e9 ) ans.pb( x );
  }

  SORT( ans );

  printf( "%lld\n" , SZ(ans) );
  REP( i , SZ(ans) ) printf( "%lld%c" , ans[i] , i==SZ(ans)-1?'\n':' ' );
  
  return 0;
}