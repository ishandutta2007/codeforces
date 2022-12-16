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

struct Starry{
  const ll ID = INFLL; // min
  vl node;
  vl added;
  int size;
  ll op( ll a , ll b ){
    return min( a , b );
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vl( size * 2 - 1 , 0 );
    added = vl( size * 2 - 1 , 0 );
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
  ll get( int k ){
    return node[k] + added[k];
  }
  ll query( ll ad , int k , int l , int r ){
    if( r - l == 1 ){
      if( get(k) + ad == -1 ){
        return l;
      } else {
        return -1;
      }
    }
    ad += added[k];
    if( get( k*2+1 ) + ad < 0 ){
      return query( ad , k*2+1 , l , (l+r)/2 );
    } else {
      return query( ad , k*2+2 , (l+r)/2 , r );
    }
  }
  ll query(){
    return query( 0 , 0 , 0 , size );
  }
};

Starry seg;

int n;

int a[100010];

int main(){

  n = in();
  seg.init( n );
  REP( i , n ){
    int pos = n - in();
    int t = in();
    if( t == 0 ){
      seg.add( pos , n , 1 );
    } else if( t == 1 ){
      seg.add( pos , n , -1 );
      a[pos] = in();
    } else {
      assert( false );
    }
    int x = seg.query();
    if( x == -1 ){
      printf( "-1\n" );
    } else {
      printf( "%d\n" , a[x] );
    }
  }

  return 0;
}