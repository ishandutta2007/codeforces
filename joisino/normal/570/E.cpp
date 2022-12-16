#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()1
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
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


const int MAX_N = 512;

int n, m;

string ts[MAX_N];
int s[MAX_N][MAX_N];

ll dp[2][MAX_N][MAX_N];

int main(){

  /*
  int n , m;
  n = m = 500;

  cout << n << " " << m;
  
  REP( i , n ){
    REP( J , n )
      cout << "a";
    cout << endl;
  }

  return 0;
  */
  
  cin >> n >> m;
  REP( i , n )
    cin >> ts[i];

  if( n < m ){
    REP( i , n )
      REP( j , m )
      s[i][j] = ts[i][j] - 'a';
  } else {
    REP( i , m )
      REP( j , n )
      s[i][j] = ts[j][i] - 'a';
    swap( n , m );
  }


  dp[0][0][0] = 1;
  if( s[0][0] != s[n-1][m-1] ) dp[0][0][0] = 0;

  int ni, nj, nk, l , o;
  
  REP( i , (n+m)/2-1 ){
    REP( j , min( i+2 ,n ) )
      REP( k , min( i+2 ,n ) )
      dp[(i+1)&1][j][k] = 0;
    REP( j , min( i+1 ,n ) ){
      REP( k , min( i+1 , n ) ){
	for( l = 0; l < 2; l++ ){
	  for( o = 0; o < 2; o++ ){
	    ni = i + 1;
	    nj = j + l;
	    nk = k + o;
	    if( nj >= n || nk >= n ) continue;
	    if( s[nj][ni-nj] == s[n-1-nk][m-1-ni+nk] ){
	      dp[ni&1][nj][nk] += dp[i&1][j][k];
	      dp[ni&1][nj][nk] %= MOD;
	    }
	  }
	}
      }
    }
  }

  int t = (m+n)/2-1;
  Mod ans = 0;
  if( (n+m)%2 == 0 ){
    REP( i , n )
      ans += dp[t&1][i][n-1-i];
  } else {
    REP( i , n ){
      REP( j , 2 ){
	int k = (n-i-1)-j;
	if( k < 0 ) continue;
	if( s[i][t-i] == s[i+j][t-i+1-j] )
	  ans += dp[t&1][i][k];
      }
    }
  }

  cout << ans.n << endl;
  
  return 0;
}