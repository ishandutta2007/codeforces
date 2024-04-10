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
    REP( j , i+1 ){
      if( j == 0 || j == i ) C[i][j] = 1;
      else C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}


const int MAX_N = 4010;

Mod memo[MAX_N];
bool used[MAX_N];

Mod rec( int x ){
  if( used[x] ) return memo[x];
  used[x] = true;
  
  if( x == 0 ) return memo[x] = 1;
  
  Mod res = 0;
  FOR( i , 1 , x+1 )
    res += C[x-1][i-1] * rec( x - i );
  
  return memo[x] = res;
}


Mod dp[MAX_N];

int main(){
  init_pascal();

  memo[0] = 1;
  FOR( i , 1 , MAX_N ){
    memo[i] = 0;
    FOR( j , 1 , i+1 )
      memo[i] += C[i-1][j-1] * memo[i-j];
  }
  
  dp[1] = 1;
  
  FOR( i , 2 , MAX_N ){
    dp[i] = 0;
    FOR( j , 1 , i+1 )
      dp[i] += C[i][j] * memo[i-j];
  }

  
  ll n = in();
  cout << dp[n].n << endl;
  
  return 0;
}