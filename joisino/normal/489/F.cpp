#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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
// const ll MOD = 1e9+7;

ll MOD;

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


const int MAX_N = 512;

int n, m;

int cnt[MAX_N], c[3];

Mod dp[2][MAX_N][MAX_N];

char s[MAX_N];

int main(){

  scanf( "%d %d %lld" , &n , &m , &MOD );
  REP( i , m ){
    scanf( "%s" , s );
    REP( j , n ) if( s[j] == '1' ) cnt[j]++;
  }

  REP( i , n ) c[ cnt[i] ]++;

  dp[0][c[0]][c[1]] = 1;
  REP( i , n-m ) REP( j , n+1 ) REP( k , n+1 ) if( dp[i%2][j][k].n != 0 ){
    if( j > 1 ) dp[(i+1)%2][j-2][k+2] += dp[i%2][j][k] * ( j * ( j - 1 ) / 2 );
    if( j > 0 && k > 0 ) dp[(i+1)%2][j-1][k] += dp[i%2][j][k] * j * k;
    if( k > 1 ) dp[(i+1)%2][j][k-2] += dp[i%2][j][k] * ( k * ( k - 1 ) / 2 );
  }

  printf( "%d\n" , (int)dp[(n-m)%2][0][0].n );
  
  return 0;
}