#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }




const int MOD = 1e9 + 7;

struct Mod{
  ll n;
  Mod(){}
  Mod( ll n ) : n((n%MOD+MOD)%MOD) {}
};

Mod operator + ( Mod a  , Mod b ){ return Mod( ( a.n + b.n ) % MOD ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( ( a.n + MOD - b.n ) % MOD ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( ( a.n * b.n ) % MOD ); }
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
Mod operator / ( Mod a  , Mod b ){ return Mod( ( a.n * inv(b).n ) % MOD ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }

const int MAX_COMB = 4010;
Mod C[MAX_COMB][MAX_COMB];
void init_pascal(){
  REP( i , MAX_COMB ){
    REP( j , MAX_COMB ){
      if( j == 0 || j == i ) C[i][j] = 1;
      else C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}

const int MAX_FACT = 200010;
Mod Fact[MAX_FACT];
Mod Factinv[MAX_FACT];
void init_fact(){
  Fact[0] = 1;
  FOR( i , 1 , MAX_FACT )
    Fact[i] = Fact[i-1] * i;
  REP( i , MAX_FACT )
    Factinv[i] = inv( Fact[i] );
}

Mod comb( int n , int r ){
  return Fact[n] * Factinv[r] * Factinv[n-r];
}


const int MAX_N = 2010;

Mod dp[MAX_N];

typedef pair<ll,P> IP;
vector<IP> ps;
ll x( int a ){ return ps[a].se.fi; }
ll y( int a ){ return ps[a].se.se; }

int main(){

  init_fact();

  int h , w , n;
  cin >> h >> w >> n;

  REP( i , n ){
    int a , b;
    cin >> a >> b; a--; b--;
    ps.pb( IP( a+b , P( a , b ) ) );
  }
  ps.pb( IP( h+w-2 , P( h-1 , w-1 ) ) );

  sort( ALL(ps) );

  REP( i , n+1 ){
    dp[i] = comb( x(i) + y(i) , x(i) );
    REP( j , i ){
      if( x(i) >= x(j) && y(i) >= y(j) )
	dp[i] -= dp[j] * comb( x(i) - x(j) + y(i) - y(j) , x(i) - x(j) );
    }
  }

  cout << dp[n].n << endl;
  
  return 0;
}