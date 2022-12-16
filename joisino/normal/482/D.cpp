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

const ll MAX_N = 100010;

Mod dp[MAX_N][2];

ll n;
vl G[MAX_N];

inline void append( Mod *v , Mod a , Mod b ){ v[0] = a; v[1] = b; }

void dfs( ll x ){
  dp[x][1] = 1;
  Mod alleven = 1, allodd[2] = { 1 , 0 };
  
  YYS( w , G[x] ){
    dfs( w );
    append( dp[x] , dp[x][0] + dp[w][0] * dp[x][0] + dp[w][1] * dp[x][1] , dp[x][1] + dp[w][0] * dp[x][1] + dp[w][1] * dp[x][0] );
    alleven += alleven * dp[w][0];
    append( allodd , allodd[0] + allodd[1] * dp[w][1] , allodd[1] + allodd[0] * dp[w][1] );
  }

  dp[x][0] = dp[x][0] * 2 - allodd[1];
  dp[x][1] = dp[x][1] * 2 - alleven;
}

int main(){

  scanf( "%lld" , &n );
  FOR( i , 1 , n ){
    ll a;
    scanf( "%lld" , &a ); a--;
    G[a].pb( i );
  }

  dfs( 0 );

  printf( "%lld\n" , (ll)( dp[0][0] + dp[0][1] ).n );

  return 0;
}