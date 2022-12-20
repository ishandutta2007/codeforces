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

struct Bit{
  vl bit;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
  }
  void add( int k , ll v ){
    for( int i = k+1; i <= size; i += i & -i ) bit[i-1] += v;
  }
  ll sum( int k ){ // [0,k)
    ll res = 0;
    for( int i = k; i > 0; i -= i & -i ) res += bit[i-1];
    return res;
  }
  ll sum( int l , int r ){ // [l,r)
    return sum( r ) - sum( l );
  }
  ll get( int k ){
    return sum( k+1 ) - sum( k );
  }
  ll update( int k , ll x ){
    add( k , x - get(k) );
  }
};

const int MAX_N = 1000010;
const int X_START = 0;
const int Y_QUERY = 1;
const int X_END = 2;

int n;

typedef pair<int,pi> sw;
vector<sw> sweep;

int cnt[MAX_N];
Bit bit;

vl ys;
vi cy;

ll ans = 0;

unordered_map<ll,vpl> vs;

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    ll xa, ya, xb, yb;
    scanf( "%lld %lld %lld %lld" , &xa , &ya , &xb , &yb );
    ys.pb( min(ya,yb) );
    ys.pb( max(ya,yb) );
    if( xa == xb ){
      ans += abs( yb - ya ) + 1;
      sweep.pb( xa , pi( Y_QUERY , i ) );
      vs[xa].pb( min(ya,yb) , i );
    } else {
      ans += abs( xb - xa ) + 1;
      sweep.pb( min(xa,xb) , pi( X_START , i ) );
      sweep.pb( max(xa,xb) , pi( X_END   , i ) );
      vs[ya+INFLL].pb( min(xa,xb) , max(xa,xb) );
    }
  }

  
  YYS( ve , vs ){
    vpl v = ve.se;
    SORT( v );
    ll cur = -INFLL;
    YYS( w , v ){
      ll end = ( ve.fi < INFLL/2 ? ys[w.se*2+1] : w.se );
      if( w.fi <= cur ){
	ans -= min(end,cur) - w.fi + 1;
	if( ve.fi < INFLL/2 ) ys[w.se*2] = min(end,cur)+1;
      }
      chmax( cur , end );
    }
  }

  cy = compress( ys ).fi;

  SORT( sweep );
  bit.init( 2*n );

  YYS( w , sweep ){
    int x = w.fi;
    int t = w.se.fi;
    int id = w.se.se;
    int ya = cy[id*2];
    int yb = cy[id*2+1];
    if( t == X_START ){
      if( cnt[ya] == 0 ) bit.add( ya , 1 );
      cnt[ya]++;
    } else if( t == X_END ){
      cnt[ya]--;
      if( cnt[ya] == 0 ) bit.add( ya , -1 );
    } else if( t == Y_QUERY ){
      ans -= bit.sum( ya , yb+1 );
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}