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

struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};
typedef vector<Mod> vm;

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

Mod pp( ll a , ll b ){
  Mod res = 1;
  REP( i , b ) res *= a-i;
  return res;
}

Mod cc( ll a , ll b ){
  Mod res = 1;
  REP( i , b ) res *= i+1;
  return pp(a,b) / res;
}

const int MAX_N = 11;

ll m;

// [0,10^p)
vl dg[100];

int d[100];
ll e[100];
ll cnt[100];

Mod dp[100][100][100];
Mod ans;

int main(){

  scanf( "%lld" , &m );
  REP( i , 11 ){
    d[i] = m % 10;
    m /= 10;
  }

  e[0] = 1;
  FOR( i , 1 , 11 ) e[i] = e[i-1] * 10;
  
  dg[0].resize(MAX_N); dg[0][0] = 1;
  FOR( i , 1 , 11 ){
    dg[i].resize(MAX_N);
    REP( j , MAX_N ){
      dg[i][j] = dg[i-1][j]*8;
      if( j > 0 ) dg[i][j] += dg[i-1][j-1]*2;
    }
  }

  /*
  REP( i , 5 ){
    REP( j , 5 ) cout << dg[i][j] << " ";
    cout << endl;
  }
  */

  int c = 0;
  for( int j = 10; j >= 0; j-- ){
    REP( i , 11 ) REP( k , d[j] ){
      if( k == 4 || k == 7 ){
	if( 0 <= i-c-1 && i-c-1 <= 10 ) cnt[i] += dg[j][i-c-1];
      } else if( i-c >= 0 )  cnt[i] += dg[j][i-c];
    }
    if( d[j] == 4 || d[j] == 7 ) c++;
  }
  cnt[c]++;
  cnt[0]--;

  /*
  REP( i , 11 ) cout << cnt[i] << " ";
  cout << endl;
  */

  dp[0][0][0] = 1;
  REP( i , 11 ) REP( j , 7 ) REP( k , 11 ) REP( l , 7 ){
    if( cnt[i] >= l && j-l >= 0 && k-i*l >= 0 ) dp[i+1][j][k] += dp[i][j-l][k-i*l] * pp(cnt[i],l) * cc( 6-(j-l) , l );
  }

  /*
  REP( i , 11 ) cout << dp[11][6][i].n << " ";
  cout << endl;
  */

  ans = 0;
  REP( i , 11 ) if( cnt[i] > 0 ) REP( k , i ) ans += dp[11][6][k] * cnt[i];

  printf( "%lld\n" , (ll)ans.n );
  
  return 0;
}