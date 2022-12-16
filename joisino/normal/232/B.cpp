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



class Comb : public vector<vector<Mod> > {
 public:
  Comb( int max_n ){
    resize( max_n , vector<Mod>( max_n ) );
    REP( i , max_n ){
      at(i).at(0) = at(i).at(i) = 1;
      FOR( j , 1 , i )
	at(i).at(j) = at(i-1).at(j-1) + at(i-1).at(j);
    }
  }
};

const int MAX_N = 128;

Comb comb(MAX_N);

Mod dp[MAX_N][MAX_N*MAX_N];

ll n, m, l;

Mod powres[MAX_N][2];

int main(){

  cin >> n >> m >> l;

  REP( i , n+1 ){
    powres[i][0] = modpow( comb[n][i] , m/n );
    powres[i][1] = modpow( comb[n][i] , m/n+1 );
  }
  
  dp[0][0] = 1;
  REP( i , n ){
    int p = 0;
    if( i < m%n ) p = 1;
    REP( j , l+1 ) REP( k , n+1 )
      dp[i+1][j+k] += dp[i][j] * powres[k][p];
  }

  cout << dp[n][l].n << endl;

  return 0;
}