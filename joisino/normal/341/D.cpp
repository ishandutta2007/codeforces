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

struct Bit2d{
  ml bit;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = ml( size+1 , vl( size+1 , 0 ) );
  }
  void add( int x , int y , ll v ){
    for( int i = x; i <= size; i += i & -i )
      for( int j = y; j <= size; j += j & -j )
	bit[i][j] ^= v;
  }
  ll sum( int x , int y ){
    ll res = 0;
    for( int i = x; i > 0; i -= i & -i )
      for( int j = y; j > 0; j -= j & -j )
	res ^= bit[i][j];
    return res;
  }
};

Bit2d bit[4];

int n, m;

ll get( int x , int y ){
  if( x % 2 == 0 && y % 2 == 0 ) return bit[0].sum( x , y );
  if( x % 2 == 0 && y % 2 == 1 ) return bit[1].sum( x , y );
  if( x % 2 == 1 && y % 2 == 0 ) return bit[2].sum( x , y );
  if( x % 2 == 1 && y % 2 == 1 ) return bit[3].sum( x , y );
}

void add( int x , int y , ll v ){
  if( x % 2 == 0 && y % 2 == 0 ) bit[0].add( x , y , v );
  if( x % 2 == 0 && y % 2 == 1 ) bit[1].add( x , y , v );
  if( x % 2 == 1 && y % 2 == 0 ) bit[2].add( x , y , v );
  if( x % 2 == 1 && y % 2 == 1 ) bit[3].add( x , y , v );
}


int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , 4 ) bit[i].init( n + 1 );

  REP( i , m ){
    ll t, xa, ya, xb, yb, v;
    scanf( "%lld %lld %lld %lld %lld" , &t , &xa , &ya , &xb , &yb ); xa++; ya++; xb++; yb++;
    if( t == 1 ){
      ll ans = get( xb , yb ) ^ get( xb , ya-1 ) ^ get( xa-1 , yb ) ^ get( xa-1 , ya-1 );
      printf( "%lld\n" , ans );
    } else if( t == 2 ){
      scanf( "%lld" , &v );
      add( xa   , ya   , v );
      add( xa   , yb+1 , v );
      add( xb+1 , ya   , v );
      add( xb+1 , yb+1 , v );
    }
  }
  
  return 0;
}