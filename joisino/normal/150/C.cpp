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
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head


const int MAX_N = 150010;

template<class T>
struct Segtree{
  const ll ID = -INFLL; // identity element
  const T ZERO = 0;
  T op( T a , T b ){ // operator
    return max( a , b );
  }
  struct node{
    T le, ri, su, va;
    node( T le , T ri , T su , T va ) : le(le) , ri(ri) , su(su) , va(va) {}
    node(){}
  };
  vector<node> nodes;
  int size;
  node merge( node a , node b ){
    T le = op( a.le , a.su + b.le );
    T ri = op( b.ri , a.ri + b.su );
    T su = a.su + b.su;
    return node( le , ri , su , op( op( a.va , b.va ) , a.ri + b.le ) );
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    nodes = vector<node>( size*2-1 , node( 0 , 0 , ID , 0 ) );
  }
  void update( int k , T x ){
    k += size - 1;
    nodes[k] = node( op(ZERO,x) , op(ZERO,x) , x , op(ZERO,x) );
    while( k > 0 ){
      k = (k-1)/2;
      nodes[k] = merge( nodes[k*2+1] , nodes[k*2+2] );
    }
  }
  node query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return nodes[k];
    } else if( b <= l || r <= a ){
      return node( 0 , 0 , 0 , 0 );
    } else {
      node chl = query( a , b , k*2+1 , l , (l+r)/2 );
      node chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return merge( chl , chr );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size ).va;
  }
};

Segtree<double> seg;

int n, m, c;
double ans;

int x[MAX_N], p[MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &m , &c );
  REP( i , n ) scanf( "%d" , &x[i] );
  REP( i , n-1 ) scanf( "%d" , &p[i] );
  
  seg.init( n );
  REP( i , n-1 ) seg.update( i , (double)( x[i+1] - x[i] ) / 2.0 - (double)( c * p[i] ) / 100.0 );

  REP( query_cnt , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--; b--;
    ans += max( 0.0 , seg.query( a , b ) );
  }

  printf( "%.18lf\n" , ans );
  
  return 0;
}