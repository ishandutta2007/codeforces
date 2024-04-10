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

ll n, k;
pl a[MAX_N];
ll x[MAX_N];

ll le[MAX_N], ri[MAX_N];

int main(){
  
  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld" , &a[i].fi );
  REP( i , n ) a[i].se = i;
  scanf( "%lld" , &k );

  sort( a , a+n );
  REP( i , n ) x[i] = a[i].fi;
  
  REP( i , k ) le[k-1] += x[k-1] - x[i];
  FOR( i , k , n ) le[i] = le[i-1] - ( x[i-1] - x[i-k] ) + ( x[i] - x[i-1] ) * ( k - 1 );

  FOR( i , n-k , n ) ri[n-k] += x[i] - x[n-k];
  for( int i = n-k-1; i >= 0; i-- ) ri[i] = ri[i+1] - ( x[i+k] - x[i+1] ) + ( x[i+1] - x[i] ) * ( k - 1 );
  
  ll cur = 0;
  ll add = 0;
  REP( i , k ){
    if( i > 0 ) add += ( x[i] - x[i-1] ) * i;
    cur += add;
  }

  ll ans = cur;
  ll ansp = 0;
  FOR( i , k , n ){
    cur -= ri[i-k];
    cur += le[i];
    if( ans > cur ){
      ans = cur;
      ansp = i-k+1;
    }
  }

  REP( i , k ) printf( "%lld%c" , a[ansp+i].se+1 , i==k-1?'\n':' ' );
  

  return 0;
}