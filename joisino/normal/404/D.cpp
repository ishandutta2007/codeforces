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


const int MAX_N = 1000010;

char s[MAX_N];
ll n;

Mod dp[MAX_N][3];
Mod ans;

int main(){

  scanf( "%s" , s );
  n = strlen( s );

  if( s[0] == '?' ) dp[0][0] = dp[0][1] = dp[0][2] = 1;
  if( s[0] == '0' ) dp[0][0] = 1;
  if( s[0] == '1' ) dp[0][1] = 1;
  if( s[0] == '*' ) dp[0][2] = 1;

  FOR( i , 1 , n ){
    if( s[i] == '?' ){
      dp[i][0] = dp[i-1][0] + dp[i-1][2];
      dp[i][1] = dp[i-1][2] + dp[i-1][0];
      dp[i][2] = dp[i-1][1] + dp[i-1][2];
    } else if( s[i] == '*' ){
      dp[i][2] = dp[i-1][1] + dp[i-1][2];
    } else if( s[i] == '0' ){
      dp[i][0] = dp[i-1][0];
    } else if( s[i] == '1' ){
      dp[i][1] = dp[i-1][0];
      dp[i][0] = dp[i-1][2];
    } else if( s[i] == '2' ){
      dp[i][1] = dp[i-1][2];
    }
  }

  ans = dp[n-1][0] + dp[n-1][2];

  printf( "%lld\n" , (ll)ans.n );
  
  return 0;
}