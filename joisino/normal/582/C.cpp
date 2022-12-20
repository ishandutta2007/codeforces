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

vi factor( ll x ){
  vi res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}

const int MAX_N = 200010;

int n;
int a[MAX_N];

vi v;

int ma[MAX_N];

bool f[MAX_N];

ll ans;

bool ok( int c , int x ){
  if( c % x != 0 ) return false;
  return __gcd( c / x , n / x ) == 1;
}

void allmax( int x ){
  ll cur = 0;
  FOR( i , 1 , n ) if( ok( i , x ) ) cur++;
  ans += cur * n;
}

void add( int c , int x ){
  ll cur = 0;
  FOR( i , 1 , c+1 ){
    if( ok( i , x ) ) cur++;
    ans += cur;
  }
}

void yuyu( int x ){
  REP( i , x ) ma[i] = 0;
  REP( i , n ) chmax( ma[i%x] , a[i] );

  REP( i , n ) f[i] = ma[i%x] == a[i];

  int p = 0;
  while( p < n && f[p] ) p++;
  if( p == n ){
    allmax( x );
    return;
  }

  int sp = p;
  int cur = 0;
  do {
    p = ( p + 1 ) % n;
    
    if( !f[p] ){
      add( cur , x );
      cur = 0;
    } else cur++;
    
  } while( p != sp );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  v = factor( n );

  YYS( w , v ) yuyu( w );

  printf( "%lld\n" , ans );
  
  return 0;
}