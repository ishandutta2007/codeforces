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
#define SHOW(x) cout << #x << " = " << x << endl
 
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
typedef vector<vi> mi;
 
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

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



// typedef vector<Mod> vec;
// typedef vector<vec> mat;

struct mat{
  Mod a[2][2];
  mat(){
    REP( i , 2 ) REP( j , 2 ) a[i][j] = 0;
  }
};

mat id_mat(){
  mat res;
  REP( i , 2 ) res.a[i][i] = 1;
  return res;
}
mat operator +( mat a , mat b ){
  mat c;
  REP( i , 2 ) REP( j , 2 ) c.a[i][j] = a.a[i][j] + b.a[i][j];
  return c;
}
mat operator +=( mat &a , mat b ){ return a = a + b; }
mat operator *( mat a , mat b ){
  mat c;
  REP( i , 2 ) REP( j , 2 ) REP( k , 2 ) c.a[i][j] += a.a[i][k] * b.a[k][j];
  return c;
}
mat operator *=( mat &a , mat b ){ return a = a * b; }
mat pow( mat a , ll k ){
  mat res = id_mat();
  while( k > 0 ){
    if( k % 2 == 1 ) res *= a;
    a *= a;
    k /= 2;
  }
  return res;
}


mat fib( ll k ){
  mat A;
  A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
  return A = pow( A , k );
}


struct Starry{
  vector<mat> node;
  vector<mat> added;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<mat>( size * 2 - 1 );
    added = vector<mat>( size * 2 - 1 , id_mat() );
  }
  void set( int k , mat x ){ // for init
    k += size - 1;
    node[k] = x;
    while( k > 0 ){
      k = ( k - 1 ) / 2;
      node[k] = node[k*2+1] + node[k*2+2];
    }
  }
  void add( int a , int b , mat x , int k , int l , int r ){
    if( a <= l && r <= b ){
      added[k] *= x;
    } else if( b <= l || r <= a ){
      return;
    } else {
      add( a , b , x , k*2+1 , l , (l+r)/2 );
      add( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = node[k*2+1] * added[k*2+1] + node[k*2+2] * added[k*2+2];
    }
  }
  void add( int a , int b , mat x ){
    add( a , b , x , 0 , 0 , size );
  }
  mat query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k] * added[k];
    } else if( b <= l || r <= a ){
      return mat();
    } else {
      mat chl = query( a , b , k*2+1 , l , (l+r)/2 );
      mat chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return ( chl + chr ) * added[k];
    }
  }
  mat query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};

Starry seg;

int n, m;
int a[100010];

int main(){

  scanf( "%d %d" , &n , &m );
  seg.init( n );
  REP( i , n ) seg.set( i , fib(in()-1) );

  REP( i , m ){
    int t, l , r , x;
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d %d" , &l , &r , &x ); l--;
      seg.add( l , r , fib(x) );
    } else if( t == 2 ){
      scanf( "%d %d" , &l , &r ); l--;
      printf( "%d\n" , (int)seg.query( l , r ).a[0][0].n );
    }
  }

  return 0;
}