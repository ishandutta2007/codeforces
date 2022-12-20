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
  Comb( int max_n , int max_m ){
    resize( max_n , vector<Mod>( max_m , 0 ) );
    REP( i , max_n ){
      at(i).at(0) = 1;
      if( i < max_m ) at(i).at(i) = 1;
      FOR( j , 1 , min( i , max_m ) )
	at(i).at(j) = at(i-1).at(j-1) + at(i-1).at(j);
    }
  }
};


const int MAX_N = 101010;

int n, m;

Mod dp[128][MAX_N];
int a[MAX_N];

Comb C( MAX_N , 128 );

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &a[i] );
  
  REP( query_cnt , m ){
    int l, r, k;
    scanf( "%d %d %d" , &l , &r , &k ); l--;
    dp[k][l] += 1;
    REP( i , k+1 ) dp[i][r] -= C[k+r-l-1-i][k-i];
  }

  for( int i = 127; i >= 0; i-- ) REP( j , MAX_N-1 ){
      if( i > 0 ) dp[i-1][j] += dp[i][j];
      dp[i][j+1] += dp[i][j];
    }

  
  REP( i , n ) dp[0][i] += a[i];

  REP( i , n ) printf( "%d%c" , dp[0][i].n , i==n-1?'\n':' ' );
  
  return 0;
}