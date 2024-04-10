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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

void binary_basis_insert( vi &v, int a ){
  YYS( w , v ){
    if( w & (-w) & a ){
      a ^= w;
    }
  }
  if( a == 0 ){
    return;
  }
  YYS( w , v ){
    if( a & (-a) & w ){
      w ^= a;
    }
  }
  v.pb( a );
}
vi binary_basis( vi v ){
  vi res(0);
  YYS( w , v ){
    binary_basis_insert( res , w );
  }
  return res;
}

class Basis{
public:
  vi operator () ( vi a , vi b ){
    if( SZ(a) < SZ(b) ){
      swap( a , b );
    }
    YYS( w , b ){
      binary_basis_insert( a , w );
    }
    return binary_basis( a );
  }
};


template<typename T, class OpFunc>
struct Segtree{
  T ID;
  vector<T> node;
  int size;
  OpFunc op;
  void init( int n , T identity, OpFunc opfunc ){
    op = opfunc;
    ID = identity;
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , ID );
  }
  void init( int n , T identity, vector<T> initial, OpFunc opfunc ){
    op = opfunc;
    ID = identity;
    size = 1;
    while( size < n ) size *= 2;
    node = vector<T>( size*2-1 , ID );
    REP( i , n ){
      node[i+size-1] = initial[i];
    }
    for( int i = size-2; i >= 0; i-- ){
      node[i] = op( node[i*2+1], node[i*2+2] );
    }
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


struct BIT{
  vi bit;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vi( size , 0 );
  }
  void add( int k , int v ){
    for( int i = k+1; i <= size; i += i & -i ) bit[i-1] ^= v;
  }
  int sum( int k ){ // [0,k]
    int res = 0;
    for( int i = k+1; i > 0; i -= i & -i ) res ^= bit[i-1];
    return res;
  }
};


Segtree<vi,Basis> seg;
BIT bit;

int n, q;
int a[200010];
int b[200010];

int main(){

  n = in();
  q = in();

  bit.init( n+1 );
  REP( i , n ){
    a[i] = in();
    bit.add( i , a[i] );
    bit.add( i+1 , a[i] );
  }
  
  FOR( i , 1 , n ){
    b[i] = a[i] ^ a[i-1];
  }

  mi initial(1,vi(0));
  FOR( i , 1 , n ){
    initial.pb( vi( { b[i] } ) );
  }
  
  seg.init( n, vi(0), initial, Basis() );


  REP( i , q ){
    int t = in();
    if( t == 1 ){
      int l = in() - 1;
      int r = in();
      ll k = in();
      bit.add( l , k );
      bit.add( r , k );
      if( l > 0 ){
        seg.update( l , { bit.sum( l-1 ) ^ bit.sum( l ) } );
      }
      if( r < n ){
        seg.update( r , { bit.sum( r-1 ) ^ bit.sum( r ) } );
      }
    } else {
      int l = in() - 1;
      int r = in();
      vi res = seg.query( l+1 , r );
      // SHOWA( res, SZ(res) );
      binary_basis_insert( res , bit.sum( l ) );
      printf( "%lld\n" , PW(SZ(res)) );
    }
  }

  return 0;
}