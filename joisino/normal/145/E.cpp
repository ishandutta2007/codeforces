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
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Segtree{
  vi ma, mi, f, s, la;
  int size;
  void init( int n , string st ){
    size = 1;
    while( size < n ) size *= 2;
    ma = mi = f = s = la = vi( size*2-1 , 0 );
    for( int i = size-1+SZ(st)-1; i >= 0; i-- ){
      if( i < size - 1 ) merge( i );
      else{
	if( st[i-(size-1)] == '4' ) ma[i] = f[i] = 1, s[i] = mi[i] = 0;
	if( st[i-(size-1)] == '7' ) mi[i] = -1, ma[i] = f[i] = 0, s[i] = 1;
      }
    }
  }
  inline void merge( int k ){
    int en = f[k*2+1] - s[k*2+1];
    ma[k] = max( ma[k*2+1] , ma[k*2+2] + en );
    mi[k] = min( mi[k*2+1] , mi[k*2+2] + en );
    f[k] = f[k*2+1] + f[k*2+2];
    s[k] = s[k*2+1] + s[k*2+2];
  }
  inline void flip( int k ){
    int tma = ma[k], tmi = mi[k];
    ma[k] = -tmi;
    mi[k] = -tma;
    swap( f[k] , s[k] );
  }
  inline void push( int k ){
    flip( k );
    if( k < size - 1 ){
      la[k*2+1] ^= 1;
      la[k*2+2] ^= 1;
    }
    la[k] = 0;
  }
  void flip( int a , int b , int k , int l , int r ){
    if( la[k] == 1 ) push( k );
    if( a <= l && r <= b ){
      push( k );
    } else if( b <= l || r <= a ){
      return;
    } else {
      flip( a , b , k*2+1 , l , (l+r)/2 );
      flip( a , b , k*2+2 , (l+r)/2 , r );
      merge( k );
    }
  }
  void flip( int a , int b ){
    flip( a , b , 0 , 0 , size );
  }
};

const ll MAX_N = 1000010;

ll n, m;

char s[MAX_N];

char t[72];
ll x, y;

Segtree seg;

int main(){

  scanf( "%lld %lld" , &n , &m );
  scanf( "%s" , s );

  seg.init( n , s );

  REP( i , m ){
    scanf( "%s" , t );
    if( t[0] == 'c' ){
      if( seg.la[0] == 1 ) seg.flip( 0 );
      ll ma = seg.ma[0];
      ll s = seg.s[0];
      printf( "%lld\n" , ma + s );
    } else if( t[0] == 's' ){
      scanf( "%lld %lld" , &x , &y ); x--;
      seg.flip( x , y );
    }
  }
  
  return 0;
}