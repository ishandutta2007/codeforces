#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }



const ll MOD = 1e9 + 7;

struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};

Mod operator + ( Mod a  , Mod b ){ return Mod( ( a.n + b.n ) % MOD ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( ( a.n - b.n + MOD ) % MOD ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( ( (ll)a.n * b.n ) % MOD ); }
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
Mod operator / ( Mod a  , Mod b ){ return Mod( ( (ll)a.n * inv(b).n ) % MOD ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


const int MAX_LHM = 3;
const ll MUL[3] = { 72727 , 51419 , 79393  };
const ll RHMOD[3] = { 1000000007 , 765876961 , 727272727 };
struct RollingHash{
  vl h[MAX_LHM];
  vl e[MAX_LHM];
  int n;
  void init( const string &s ){
    n = s.length();
    
    REP( j , MAX_LHM ){
      h[j] = vl( n+1 , 0 );
      e[j] = vl( n+1 , 1 );
    }

    REP( i , n )
      REP( j , MAX_LHM )
	h[j][i+1] = ( h[j][i] * MUL[j] + s[i] ) % RHMOD[j];

    REP( j , MAX_LHM )
      REP( i , n )
	e[j][i+1] = e[j][i] * MUL[j] % RHMOD[j];
  }
  RollingHash(){}
  RollingHash( const string &s ){
    init( s );
  }
  vl get( int s , int t ){
    chmin( s , n ); chmax( s , 0 );
    chmin( t , n ); chmax( t , 0 );
    vl res;
    REP( j , MAX_LHM )
      res.pb( ( h[j][t] - h[j][s] * e[j][t-s] % RHMOD[j] + RHMOD[j] ) % RHMOD[j] );

    return res;
  }
};

const int MAX_N = 100010;

string s, t;

Mod dp[MAX_N];
Mod ds[MAX_N];
Mod dss[MAX_N];

Mod ans;

RollingHash sr, tr;

int p;

int main(){

  cin >> s >> t;
  sr.init( s );
  tr.init( t );

  dss[s.length()] = 1;
  p = s.length()+1;
  for( int i = s.length()-1; i >= 0; i-- ){
    if( sr.get( i , i + t.length() ) == tr.get( 0 , t.length() ) )
      p = i + t.length();
    dp[i] = dss[p];
    ds[i] = ds[i+1] + dp[i];
    dss[i] = dss[i+1] + ds[i] + 1;
    ans += dss[p];
  }

  cout << ans.n << endl;
  
  return 0;
}