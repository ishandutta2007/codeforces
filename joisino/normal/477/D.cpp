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



const int MAX_N = 5010;

string s;

Mod sum[MAX_N][MAX_N];
int mdp[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int cs[MAX_N][MAX_N];

int main(){

  cin >> s;
  int n = s.length();

  for( int i = n-1; i >= 0; i-- )
    for( int j = n-1; j >= 0; j-- )
      if( s[i] == s[j] ) cs[i][j] = cs[i+1][j+1] + 1;

  FOR( i , 1 , MAX_N ) sum[0][i] = 1;
  FOR( i , 1 , n+1 ) FOR( j , 1 , i+1 ){
    if( s[i-j] == '1' ){
      int t = j-1;
      if( i-2*j < 0 ) chmin( t , i-j );
      else if( cs[i-2*j][i-j] >= j || s[ i-2*j+cs[i-2*j][i-j]] < s[i-j+ cs[i-2*j][i-j]] ) t = j;
      sum[i][j+1] = sum[i][j] + sum[i-j][t+1];
    } else sum[i][j+1] = sum[i][j];
  }

  cout << sum[n][n+1].n << endl;

  FOR( i , 1 , MAX_N ) sum[0][i] = 1;
  FOR( i , 1 , n+1 ) FOR( j , 1 , i+1 ){
    if( s[i-j] == '1' ){
      int t = j-1;
      if( i-2*j < 0 ) chmin( t , i-j );
      else if( cs[i-2*j][i-j] >= j || s[ i-2*j+cs[i-2*j][i-j]] < s[i-j+ cs[i-2*j][i-j]] ) t = j;
      sum[i][j+1] = sum[i][j] + sum[i-j][t+1];
    } else sum[i][j+1] = sum[i][j];
  }

  REP( i , MAX_N ) REP( j , MAX_N ) dp[i][j] = mdp[i][j] = INF;
  FOR( i , 1 , MAX_N ) mdp[0][i] = 0;
  FOR( i , 1 , n+1 ) FOR( j , 1 , i+1 ){
    if( s[i-j] == '1' ){
      int t = j-1;
      if( i-2*j < 0 ) chmin( t , i-j );
      else if( cs[i-2*j][i-j] >= j || s[ i-2*j+cs[i-2*j][i-j]] < s[i-j+ cs[i-2*j][i-j]] ) t = j;
      dp[i][j] = mdp[i-j][t+1] + 1;
      mdp[i][j+1] = min( mdp[i][j] , dp[i][j] );
    } else mdp[i][j+1] = mdp[i][j];
  }

  ll ans = INFLL;
  REP( i , MAX_N ){
    if( dp[n][i] < INF ){
      Mod res = dp[n][i];
      Mod base = 1;
      REP( j , i ){
	if( s[n-1-j] == '1' ) res += base;
	base *= 2;
      }
      if( i >= 20 ){
	if( ans == INFLL ) cout << res.n << endl;
	else cout << ans << endl;
	return 0;
      }
      chmin( ans , (ll)res.n );
    }
  }

  cout << ans << endl;

  return 0;
}