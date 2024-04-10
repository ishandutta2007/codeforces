#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
const ll MOD = 1e9+9;

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


const int MAX_N = 300010;

Mod fib[MAX_N];
Mod sum[MAX_N];

template<typename T>
struct LazySegtree{
  const T IDENTITY = 0; // identity element
  vector<T> node;
  vector<T> p, x;
  vb lazy_flag;
  int size;
  inline void push( int k , int l , int r ){
    node[k] += sum[r-l] * p[k];
    node[k] += sum[r-l+1] * x[k];
    if( k < size-1 ){
      p[k*2+1] += p[k];
      x[k*2+1] += x[k];
      p[k*2+2] += p[k] * fib[(r-l)/2-1] + x[k] * fib[(r-l)/2];
      x[k*2+2] += p[k] * fib[(r-l)/2] + x[k] * fib[(r-l)/2+1];
      lazy_flag[k*2+1] = lazy_flag[k*2+2] = true;
    }
    p[k] = x[k] = 0;
    lazy_flag[k] = false;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , IDENTITY );
    x = p = vector<T>( size*2-1 , IDENTITY );
    lazy_flag = vb( size*2-1 , false );
  }
  void set( int k , T x ){
    k += size-1;
    node[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      node[k] = node[k*2+1] + node[k*2+2];
    }
  }
  void update( int a , int b , int k , int l , int r ){
    if( lazy_flag[k] ) push( k , l , r );
    if( a <= l && r <= b ){
      x[k] = fib[l-a+1];
      p[k] = fib[l-a];
      push( k , l , r );
    } else if( b <= l || r <= a ){
    } else {
      update( a , b , k*2+1 , l , (l+r)/2 );
      update( a , b , k*2+2 , (l+r)/2 , r );
      node[k] = node[k*2+1] + node[k*2+2];
    }
  }
  void update( int a , int b ){
    update( a , b , 0 , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    if( lazy_flag[k] ) push( k , l , r );
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return IDENTITY;
    } else {
      return query( a , b , k*2+1 , l , (l+r)/2 ) + query( a , b , k*2+2 , (l+r)/2 , r );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};

LazySegtree<Mod> seg;

int n, m;
ll a[MAX_N];

int main(){

  fib[0] = 0; fib[1] = 1;
  FOR( i , 2 , MAX_N ) fib[i] = fib[i-2] + fib[i-1];
  FOR( i , 1 , MAX_N ) sum[i] = sum[i-1] + fib[i-1];

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%lld" , &a[i] );

  seg.init( n );
  REP( i , n ) seg.set( i , a[i] );


  REP( i , m ){
    int t, l , r;
    scanf( "%d %d %d" , &t , &l , &r ); l--;
    if( t == 1 ){
      seg.update( l , r );
    } else if( t == 2 ){
      printf( "%d\n" , (int)seg.query( l , r ).n );
    }
  }
  
  return 0;
}