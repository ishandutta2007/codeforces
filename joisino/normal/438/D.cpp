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


const int MAX_N = 100010;

struct Segtree{
  ll sum[MAX_N*4];
  ll max_v[MAX_N*4];
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    REP( i , size*2-1 ) sum[i] = max_v[i] = 0;
  }
  void update( int k , ll x ){
    k += size-1;
    sum[k] = x;
    max_v[k] = x;
    while( k > 0 ){
      k = (k-1)/2;
      sum[k] = sum[k*2+1] + sum[k*2+2];
      max_v[k] = max( max_v[k*2+1] , max_v[k*2+2] );
    }
  }
  void range_mod( int a , int b , int x , int k , int l , int r ){
    if( max_v[k] < x ) return;
    if( b <= l || r <= a ) return;
    if( r-l == 1 ){
      sum[k] %= x;
      max_v[k] = sum[k];
      return;
    }
    range_mod( a , b , x , k*2+1 , l , (l+r)/2 );
    range_mod( a , b , x , k*2+2 , (l+r)/2 , r );
    sum[k] = sum[k*2+1] + sum[k*2+2];
    max_v[k] = max( max_v[k*2+1] , max_v[k*2+2] );
  }
  void range_mod( int a , int b , int x ){
    range_mod( a , b , x , 0 , 0 , size );
  }
  ll query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return sum[k];
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      ll chl = query( a , b , k*2+1 , l , (l+r)/2 );
      ll chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return chl + chr;
    }
  }
  ll query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  ll get( int a ){
    return sum[a+size-1];
  }
};

Segtree seg;
int n, m;
int a;
int t;
int l, r, k, x;

int main(){

  scanf( "%d %d" , &n , &m );
  seg.init( n );
  REP( i , n ){
    scanf( "%d" , &a );
    seg.update( i , a );
  }
  REP( i , m ){
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d" , &l , &r ); l--;
      printf( "%lld\n" , seg.query( l , r ) );
    } else if( t == 2 ){
      scanf( "%d %d %d" , &l , &r , &x ); l--;
      seg.range_mod( l , r , x );
    } else if( t == 3 ){
      scanf( "%d %d" , &k , &x ); k--;
      seg.update( k , x );
    }
  }
  
  return 0;
}