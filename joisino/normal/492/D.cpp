#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
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
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int n;
ll x, y;
ll a;

bool check( ll h , ll t ){
  return h - t/x - t/y <= 0;
}

int main(){

  scanf( "%d %lld %lld" , &n , &x , &y );
  REP( i , n ){
    scanf( "%lld" , &a );
    a %= ( x + y );
    ll lb = -1, ub = x*y+1;
    while( ub - lb > 1 ){
      ll md = ( lb + ub ) / 2;
      if( check( a , md ) ) ub = md;
      else lb = md;
    }
    if( ub % x == 0 && ub % y == 0 ) puts( "Both" );
    else if( ub % y == 0 ) puts( "Vanya" );
    else if( ub % x == 0 ) puts( "Vova" );
  }
  
  return 0;
}