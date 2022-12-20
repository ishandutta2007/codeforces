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



template<typename T>
struct Segtree{
  const Mod ID = Mod(0); // indetity element
  vector<T> node;
  int size;
  T op( T a , T b ){ // operator
    return a + b;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , ID );
  }
  void update( int k , T x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  T query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      T chl = query( a , b , k*2+1 , l , (l+r)/2 );
      T chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return op( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  T get( int a ){
    return node[a+size-1];
  }
};

const int MAX_A = 1000010;
const int MAX_N = 100010;

int n;
ll a;

Segtree<Mod> bit;

int main(){

  scanf( "%d" , &n );

  bit.init( MAX_A );
  bit.update( 0 , 1 );
  
  REP( i , n ){
    scanf( "%lld" , &a );
    bit.update( a , bit.query( 0 , a+1 ) * a );
  }

  printf( "%d\n" , (int)bit.query( 1 , MAX_A ).n );
  
  return 0;
}