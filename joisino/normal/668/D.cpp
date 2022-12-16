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

template<class T> vi compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

template<class T>
class SumOp{
public:
  T operator () ( T a , T b ){ return a + b; }
};

template<typename T>
struct NodePool{
  struct node{
    T val;
    int chl, chr;
    node( T val , int chl, int chr ) : val(val) , chl(chl) , chr(chr){}
  };
  int cnt;
  vector<node> pool;
  NodePool( int size ){
    pool = vector<node>( size , node(0,-1,-1) );
  }
  int newnode( T v , int chl = -1 , int chr = -1 ){
    pool[cnt] = node( v , chl , chr );
    return cnt++;
  }
  int& chl( int id ){
    return pool[id].chl;
  }
  int& chr( int id ){
    return pool[id].chr;
  }
  T& val( int id ){
    return pool[id].val;
  }
};

template<typename T, class OpFunc>
struct PartialSegtree{
  T ID;
  NodePool<T> *pool;
  int size;
  OpFunc op;
  int root;
  void init( int n , OpFunc opfunc , T identity , NodePool<T> *nodepool ){
    op = opfunc;
    ID = identity;
    size = 1;
    while( size < n ) size *= 2;
    pool = nodepool;
    root = pool->newnode( ID );
  }
  void update( int a , T x , int k , int l , int r ){
    // cout << a << " " << x << " " << k << " " << l << " " << r << endl;
    if( r - l == 1 ){
      pool->val( k ) = x;
      return;
    } else if( a < (l+r)/2 ){
      if( pool->chl(k) == -1 ){
        pool->chl(k) = pool->newnode(ID);
      }
      update( a , x , pool->chl(k) , l , (l+r)/2 );
    } else {
      if( pool->chr(k) == -1 ){
        pool->chr(k) = pool->newnode(ID);
      }
      update( a , x , pool->chr(k) , (l+r)/2 , r );
    }
    pool->val(k) = 0;
    int chl = pool->chl(k);
    int chr = pool->chr(k);
    if( chl == -1 ){
      chl = ID;
    } else {
      chl = pool->val(chl);
    }
    if( chr == -1 ){
      chr = ID;
    } else {
      chr = pool->val(chr);
    }
    pool->val(k) = op( chl , chr );
    // cout << pool->val(k) << endl;
  }
  void update( int a , T x ){
    update( a , x , root , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    // cout << a << " " << b << " " << k << " " << l << " " << r << endl;
    if( a <= l && r <= b ){
      return pool->val( k );
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      T chl = ID;
      T chr = ID;
      if( pool->chl(k) != -1 ){
        chl = query( a , b , pool->chl(k) , l , (l+r)/2 );
      }
      if( pool->chr(k) != -1 ){
        chr = query( a , b , pool->chr(k) , (l+r)/2 , r );
      }
      return op( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , root , 0 , size );
  }
};

PartialSegtree<int,SumOp<int> > seg[100010];
NodePool<int> np(10000010);

int n;

vi a, t , x;

int main(){

  n = in();
  REP( i , n ){
    a.pb( in() );
    t.pb( in() );
    x.pb( in() );
  }

  t = compress( t );
  x = compress( x );

  REP( i , 100010 ){
    seg[i].init( n , SumOp<int>() , 0 , &np );
  }
  
  REP( i , n ){
    // cout << i << " " << a[i] << " " << x[i] << " " << t[i] << endl;
    if( a[i] == 1 ){
      int cur = seg[ x[i] ].query( t[i] , t[i] + 1 );
      seg[ x[i] ].update( t[i] , cur + 1 );
    } else if( a[i] == 2 ){
      int cur = seg[ x[i] ].query( t[i] , t[i] + 1 );
      seg[ x[i] ].update( t[i] , cur - 1 );
    } else if( a[i] == 3 ){
      int res = seg[ x[i] ].query( 0 , t[i] + 1 );
      printf( "%d\n" , res );
    }
  }
  
  return 0;
}