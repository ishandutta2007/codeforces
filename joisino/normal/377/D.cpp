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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Starry{
  const ll ID = 0; // max
  vl node;
  vl added;
  int size;
  ll op( ll a , ll b ){
    return max( a , b );
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vl( size * 2 - 1 , 0 );
    added = vl( size * 2 - 1 , 0 );
  }
  void set( int k , ll x ){ // for init
    k += size - 1;
    node[k] = x;
    while( k > 0 ){
      k = ( k - 1 ) / 2;
      node[k] = op( node[k*2+1] , node[k*2+2] );
    }
  }
  void add( int a , int b , ll x , int k , int l , int r ){
    if( a <= l && r <= b ){
      added[k] += x;
    } else if( b <= l || r <= a ){
      return;
    } else {
      add( a , b , x , k*2+1 , l , (l+r)/2 );
      add( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = op( node[k*2+1] + added[k*2+1] , node[k*2+2] + added[k*2+2] );
    }
  }
  void add( int a , int b , ll x ){
    add( a , b , x , 0 , 0 , size );
  }
  ll query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k] + added[k];
    } else if( b <= l || r <= a ){
      return ID;
    } else {
      ll chl = query( a , b , k*2+1 , l , (l+r)/2 );
      ll chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return op( chl , chr ) + added[k];
    }
  }
  ll query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
  int maxid( int k , int l , int r ){
    if( r - l == 1 ) return l;
    if( node[k*2+1] + added[k*2+1] > node[k*2+2] + added[k*2+2] ){
      return maxid( k*2+1 , l , (l+r)/2 );
    } else {
      return maxid( k*2+2 , (l+r)/2 , r );
    }
  }
  int maxid(){
    return maxid( 0 , 0 , size );
  }
};

typedef pair<int,pi> pii;

const int MAX_N = 300010;

int n;

int l[MAX_N], r[MAX_N], v[MAX_N];

vector<pii> sweep;

int maxv;
int maxl, maxr;

Starry seg;

vi ans;

int main(){

  scanf( "%d" , &n );
  seg.init( MAX_N );
  REP( i , n ){
    scanf( "%d %d %d" , &l[i] , &v[i] , &r[i] );
    sweep.pb( v[i] , pi( 1 , i ) );
    sweep.pb( r[i] , pi( 2 , i ) );
  }

  SORT( sweep );

  YYS( w , sweep ){
    int id = w.se.se;
    if( w.se.fi == 1 ){
      seg.add( l[id] , v[id]+1 , 1 );
      if( seg.query( 0 , MAX_N ) > maxv ){
	maxv = seg.query( 0 , MAX_N );
	maxl = seg.maxid();
	maxr = w.fi;
      }
    } else if( w.se.fi == 2 ){
      seg.add( l[id] , v[id]+1 , -1 );
    }
  }
  
  REP( i , n ) if( l[i] <= maxl && maxr <= r[i] && maxl <= v[i] && v[i] <= maxr ) ans.pb( i );

  printf( "%d\n" , (int)ans.size() );
  REP( i , ans.size() ) printf( "%d%c" , ans[i]+1 , i==(int)ans.size()-1?'\n':' ' );
  
  return 0;
}