#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
// const ll MOD = 1e9+7;
ll MOD;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


const int MAX_N = 128;

int n, m;
ll w[MAX_N][MAX_N];
ll mo = INF;
Mod a[MAX_N], b[MAX_N];

vl x, v;

ll maxv;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &w[i][j] );

  REP( rev_loop , 2 ){
    REP( j , m-1 ){
      v.clear();
      REP( i , n ) v.pb( w[i][j] - w[i][j+1] );
      SORT( v );
      UNIQUE( v );
      if( v.size() == 1 ) continue;
      x.clear();
      FOR( i , 1 , v.size() ) x.pb( abs( v[i] - v[0] ) );
      ll gcd = x[0];
      YYS( w , x ) gcd = __gcd( gcd , w );
      if( mo == INF ) mo = gcd;
      else mo = __gcd( mo , gcd );
    }

    REP( i , max(n,m) ) REP( j , i ) swap( w[i][j] , w[j][i] );
    swap( n , m );
  }

  REP( i , n ) REP( j , m ) chmax( maxv , w[i][j] );
  
  if( mo <= maxv ){
    printf( "NO\n" );
    return 0;
  }

  MOD = mo;

  a[0] = 0;
  REP( i , n ) a[i+1] = a[i] + w[i+1][0] - w[i][0];

  b[0] = w[0][0];
  REP( i , m ) b[i+1] = b[i] + w[0][i+1] - w[0][i];
  
  printf( "YES\n" );
  printf( "%lld\n" , mo );
  REP( i , n ) printf( "%d%c" , (int)a[i].n , i==n-1?'\n':' ' );
  REP( i , m ) printf( "%d%c" , (int)b[i].n , i==m-1?'\n':' ' );  
  
  return 0;
}