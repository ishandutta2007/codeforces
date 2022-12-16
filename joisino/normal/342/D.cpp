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

const ll MAX_N = 10010;

ll n;
Mod dp[MAX_N][PW(6)];

char s[3][MAX_N];

Mod yuyu(){
  REP( i , MAX_N ) REP( j , PW(6) ) dp[i][j] = 0;
  
  ll ini = 0;
  REP( i , 3 ) REP( j , 2 ) if( s[i][j] != '.' ) ini |= PW(i+j*3);
  dp[0][ini] = 1;

  REP( i , n ){
    REP( j , PW(6) ){
      if( !( j & PW(0) ) ){
	if( !( j & ( PW(0) | PW(3) ) ) ) dp[i][j|PW(0)|PW(3)] += dp[i][j];
	if( !( j & ( PW(0) | PW(1) ) ) ) dp[i][j|PW(0)|PW(1)] += dp[i][j];
      } else if( !( j & PW(1) ) ){
	if( !( j & ( PW(1) | PW(4) ) ) ) dp[i][j|PW(1)|PW(4)] += dp[i][j];
	if( !( j & ( PW(1) | PW(2) ) ) ) dp[i][j|PW(1)|PW(2)] += dp[i][j];
      } else if( !( j & PW(2) ) ){
	if( !( j & ( PW(2) | PW(5) ) ) ) dp[i][j|PW(2)|PW(5)] += dp[i][j];
      }
    }
    
    ll ne = 0;
    REP( j , 3 ) if( s[j][i+2] != '.' ) ne |= PW(3+j);
    REP( j , PW(3) ) dp[i+1][j|ne] = dp[i][(j<<3)|(PW(3)-1)];
  }
  return dp[n][0];
}

int main(){

  scanf( "%lld" , &n );
  REP( i , 3 ) scanf( "%s" , s[i] );
  REP( i , 3 ) s[i][n] = s[i][n+1] = '.';

  Mod ans = yuyu();
  
  FOR( j , 1 , n-1 ) if( s[1][j] == 'O' ){
    REP( i , 3 ) FOR( k , j-1 , j+2 ) s[i][k] = 'O';
    ans -= yuyu() * 2;
    break;
  }

  printf( "%lld\n" , (ll)ans.n );
  
  return 0;
}