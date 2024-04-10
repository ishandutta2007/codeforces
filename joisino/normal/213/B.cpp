#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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

class Comb : public vector<vector<Mod> > {
 public:
  Comb( int max_n ){
    resize( max_n , vector<Mod>( max_n , 0 ) );
    REP( i , max_n ){
      at(i).at(0) = at(i).at(i) = 1;
      FOR( j , 1 , i )
	at(i).at(j) = at(i-1).at(j-1) + at(i-1).at(j);
    }
  }
};

const int MAX_N = 110;

int n;
int a[MAX_N];

Mod dp[MAX_N][MAX_N];

Comb C( MAX_N );

int main(){

  scanf( "%d" , &n );
  REP( i , 10 ) scanf( "%d" , &a[i] );

  FOR( i , a[9] , MAX_N ) dp[9][i] = 1;
  for( int i = 8; i > 0; i-- ){
    REP( j , MAX_N ) dp[i][j] = 0;
    FOR( j , a[i] , MAX_N ) FOR( k , a[i] , j+1 ){
      dp[i][j] += C[j][k] * dp[i+1][j-k];
    }
  }

  Mod ans = 0;
  FOR( j , 1 , n+1 ) FOR( k , a[0] , j+1 ){
    ans += C[j-1][k] * dp[1][j-k];
  }

  cout << ans.n << endl;
  
  return 0;
}