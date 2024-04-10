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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

int n;
ll a, b;

bool check( int x , int p ){
  if( x == 0 ) return true;
  int s = 1;
  bool res = false;
  while( !res and x >= s ){
    res = !check( x - s, p );
    s *= p;
  }
  return res;
}

bool win( ll a, ll b ){
  if( a == 0 ) return false;
  if( !win( b % a , a ) ) return true;

  b /= a;
  
  if( a % 2 == 0 ){
    if( ( b % ( a + 1 ) ) % 2 == 1 ) return false;
    return true;
  } else {
    if( b % 2 == 0 ) return true;
    return false;
  }
}

int main(){
  
  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%lld %lld" , &a , &b );
    if( a > b ) swap( a , b );
    if( win( a , b ) ) puts( "First" );
    else puts( "Second" );
  }

  return 0;
}