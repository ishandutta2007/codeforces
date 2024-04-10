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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}


template<typename T>
struct Segtree{
  const T ID = INF; // indetity element
  vector<T> node;
  int size;
  T op( T a , T b ){ // operator
    return min( a , b );
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



const int INSERT_QUERY = 1;
const int ANSWER_QUERY = 0;

const int MAX_N = 2000010;

int n, m;

int last[MAX_N];

vi a;

int ls[MAX_N], rs[MAX_N];

int ans[MAX_N];

typedef pair<int,pi> sw;
vector<sw> sweep;

Segtree<int> seg;

int main(){

  scanf( "%d %d" , &n , &m );
  a.resize( n );
  REP( i , n ) scanf( "%d" , &a[i] );
  a = compress( a ).fi;

  REP( i , n ) last[i] = -1;
  REP( i , n ){
    if( last[a[i]] != -1 ) sweep.pb( last[a[i]] , pi( INSERT_QUERY , i ) );
    last[a[i]] = i;
  }

  REP( i , m ){
    scanf( "%d %d" , &ls[i] , &rs[i] ); ls[i]--;
    sweep.pb( ls[i] , pi( ANSWER_QUERY , i ) );
  }

  SORT( sweep );
  REVERSE( sweep );

  seg.init( n );
  
  YYS( w , sweep ){
    int l = w.fi;
    if( w.se.fi == INSERT_QUERY ){
      int r = w.se.se;
      if( seg.get(r) > r-l ) seg.update( r , r-l );
    } else if( w.se.fi == ANSWER_QUERY ){
      int r = rs[ w.se.se ];
      int res = seg.query( l , r );
      if( res == INF ) res = -1;
      ans[w.se.se] = res;
    }
  }

  REP( i , m ) printf( "%d\n" , ans[i] );
  
  return 0;
}