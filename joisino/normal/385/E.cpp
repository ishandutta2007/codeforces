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

typedef vector<Mod> vec;
typedef vector<vec> mat;

mat mul( mat a , mat b ){
  mat c = mat( a.size() , vec( b[0].size() , 0 ) );
  REP( i , c.size() )
    REP( j , c[i].size() )
      REP( k , a[i].size() )
      c[i][j] = c[i][j] + a[i][k]*b[k][j];
  return c;
}

mat pow( mat a , ll k ){
  mat res = mat( a.size() , vec( a.size() , 0 ) );
  REP( i , res.size() )
    res[i][i] = 1;
  
  while( k > 0 ){
    if( k % 2 == 1 ){
      res = mul( res , a );
    }
    a = mul( a , a );
    k /= 2;
  }
  return res;
}

ll n, sx, sy, dx, dy, t;

mat A( 6 , vec(6) );
mat b( 6 , vec(1) );

int main(){

  scanf( "%lld %lld %lld %lld %lld %lld" , &n , &sx , &sy , &dx , &dy , &t );

  MOD = n;

  A[0][0] = 2; A[0][1] = 1; A[0][2] = 1; A[0][3] = 0; A[0][4] = 1; A[0][5] = 0; b[0][0] = sx;
  A[1][0] = 1; A[1][1] = 2; A[1][2] = 0; A[1][3] = 1; A[1][4] = 1; A[1][5] = 0; b[1][0] = sy;
  A[2][0] = 1; A[2][1] = 1; A[2][2] = 1; A[2][3] = 0; A[2][4] = 1; A[2][5] = 0; b[2][0] = dx;
  A[3][0] = 1; A[3][1] = 1; A[3][2] = 0; A[3][3] = 1; A[3][4] = 1; A[3][5] = 0; b[3][0] = dy;
  A[4][0] = 0; A[4][1] = 0; A[4][2] = 0; A[4][3] = 0; A[4][4] = 1; A[4][5] = 1; b[4][0] = 0;
  A[5][0] = 0; A[5][1] = 0; A[5][2] = 0; A[5][3] = 0; A[5][4] = 0; A[5][5] = 1; b[5][0] = 1;
  
  A = pow( A , t );
  mat res = mul( A , b );

  ll ansx = res[0][0].n == 0 ? n : res[0][0].n;
  ll ansy = res[1][0].n == 0 ? n : res[1][0].n;

  printf( "%lld %lld\n" , ansx , ansy );

  return 0;
}