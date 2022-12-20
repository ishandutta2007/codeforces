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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


template<typename T>
struct Segtree{
  const ll ID = INFLL; // indetity element
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


const int MAX_N = 1000010;

char cs[MAX_N]; string s;
Segtree<ll> seg;
int sum[MAX_N];
int n;
int m, l, r;

int main(){

  scanf( "%s\n" , cs ); s = cs;
  n = s.length();
  seg.init( n+1 );
  REP( i , n ){
    sum[i+1] = sum[i];
    if( s[i] == '(' ) sum[i+1]++;
    else sum[i+1]--;
  }
  REP( i , n+1 ) seg.update( i , sum[i] );
  
  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%d %d" , &l , &r ); l--;
    int x = sum[l] - seg.query( l , r+1 );
    printf( "%d\n" , r-l-(sum[r]+x-sum[l])-x );
  }
  
  return 0;
}