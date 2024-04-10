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

template<typename T>
struct LazySegtree{
  const T IDENTITY = -1; // identity element
  vector<T> node;
  vector<T> lazy;
  vb lazy_flag;
  int size;
  T op( T a , T b ){ // operator
    return max( a , b );
  }
  inline void push( int k , int l , int r ){
    node[k] = lazy[k];
    if( k < size-1 ){
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
      lazy_flag[k*2+1] = lazy_flag[k*2+2] = true;
    }
    lazy_flag[k] = false;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    lazy = vector<T>( size*2-1 , IDENTITY );
    node = vector<T>( size*2-1 , IDENTITY );
    lazy_flag = vb( size*2-1 , false );
  }
  void update( int a , int b , T x , int k , int l , int r ){
    if( lazy_flag[k] ) push( k , l , r );
    if( a <= l && r <= b ){
      lazy[k] = x;
      push( k , l , r );
    } else if( b <= l || r <= a ){

    } else {
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  void update( int a , int b , T x ){
    update( a , b , x , 0 , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    if( lazy_flag[k] ) push( k , l , r );
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return IDENTITY;
    } else {
      return op( query( a , b , k*2+1 , l , (l+r)/2 ) , query( a , b , k*2+2 , (l+r)/2 , r ) );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  T get( int a ){
    return query( a , a+1 );
  }
};

vl compress( vl a ){
  vl ord = a, res;
  SORT( ord );
  ord.erase( unique( ALL( ord ) ) , ord.end() );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return res;
}

LazySegtree<ll> seg;

const int MAX_N = 500010;

int n;
vl a;
int last[MAX_N];

vi ans;

int p;

multiset<int> ss;

int main(){

  scanf( "%d" , &n );
  a.resize( n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  vl c = compress( a );

  seg.init( n );

  REP( i , n ) last[i] = -1;
  
  REP( i , n ){
    int w = c[i];
    ss.insert( w );
    if( ss.count( w ) >= 4 ){
      ans.pb( a[i] ); ans.pb( a[i] ); ans.pb( a[i] ); ans.pb( a[i] );
      seg.update( 0 , i , -1 );      
      ss.clear();
      p = i+1;
    }
    if( last[w] != -1 && last[w] >= p ){
      ll res = seg.get( last[w] );
      if( res >= 0 ){
	ans.pb( res ); ans.pb( a[i] ); ans.pb( res ); ans.pb( a[i] );
	seg.update( 0 , i , -1 );
	ss.clear();
	p = i+1;
      } else {
	seg.update( last[w]+1 , i , a[i] );
      }
    }
    last[w] = i;
  }

  printf( "%d\n" , (int)ans.size() );
  REP( i , ans.size() ) printf( "%d%c" , ans[i] , i == (int)ans.size()-1 ? '\n' : ' ' );
  
  return 0;
}