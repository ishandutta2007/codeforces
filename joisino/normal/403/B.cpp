#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

vl fact( ll x ){
  vl res;
  for( ll i = 2; i*i <= x; i++ ){
    while( x % i == 0 ){
      res.pb( i );
      x /= i;
    }
  }
  if( x > 1 ) res.pb( x );
  return res;
}

const int MAX_N = 5010;

int n, m;
ll a[MAX_N];
ll b[MAX_N];
ll g[MAX_N];
map<ll,ll> memo;

ll score( ll x ){
  if( memo.find( x ) != memo.end() ) return memo[x];
  ll res = 0;
  vl q = fact( x );
  REP( i , q.size() ){
    if( binary_search( b , b+m , q[i] ) ) res--;
    else res++;
  }
  return memo[x] = res;
}

ll res = 0;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , m ) scanf( "%lld" , &b[i] );

  REP( i , n ) res += score( a[i] );

  g[0] = a[0]; g[n] = 1;
  FOR( i , 1 , n ) g[i] = __gcd( g[i-1] , a[i] );

  ll prev = 1;
  for( int i = n-1; i >= 0; i-- ){
    ll r = score( g[i] / prev );
    if( r < 0 ) res -= r * (i+1), prev = g[i];
  }

  printf( "%lld\n" , res );
  
  return 0;
}