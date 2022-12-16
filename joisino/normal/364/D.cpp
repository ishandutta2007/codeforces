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

vl divisor( ll x ){
  vl res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}

const ll MAX_N = 1000010;

ll n;
ll a[MAX_N];
ll ans;

mt19937 mt;

int main(){

  mt.seed( time(NULL) );

  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i] );

  ll st = clock();
  while( ( clock() - st ) <= 3 * CLOCKS_PER_SEC ){
    ll x = a[mt()%n];
    vl v = divisor( x );
    SORT( v );
    ll s = SZ(v);
    vl cnt( s , 0 );
    REP( i , n ) cnt[ lower_bound( ALL(v) , __gcd(x,a[i]) ) - v.begin() ]++;
    REP( i , s ) REP( j , i ) if( v[i] % v[j] == 0 ) cnt[j] += cnt[i];
    REP( i , s ) if( cnt[i]*2 >= n ) chmax( ans , v[i] );
  }
  
  printf( "%lld\n" , ans );
  
  return 0;
}