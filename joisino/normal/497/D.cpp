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

#define X real()
#define Y imag()
#define curr(pol, i) pol[i]
#define next(pol, i) pol[(i+1)%pol.size()]

typedef complex<ll> P;
typedef vector<P> Pol;

namespace std{
  template<class T> bool operator<(const complex<T> &a , const complex<T> &b ){
    return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
  }
}

inline ll dot( P a , P b ){ return (conj(a)*b).X; }
inline ll cross( P a , P b ){ return (conj(a)*b).Y; }
inline ll nor( P a ){ return dot(a,a); }
ll ccw( P a , P b , P c ){
  b -= a, c -= a;
  if( cross( b , c ) > 0 ) return +1; // counter clockwise
  if( cross( b , c ) < 0 ) return -1; // clockwise
  if( dot( b , c ) < 0 )   return +2; // c--a--b on line
  if( norm(b) < norm(c) )  return -2; // a--b--c on line
  return 0;
}

// completely cross
inline bool cross( const P &a , const P &b , const P &c , const P &d ){
  return ccw(a,c,b)*ccw(a,d,b) == -1 && ccw(c,a,d)*ccw(c,b,d) == -1;
}

Pol convex_hull( vector<P> ps ){
  int n = SZ(ps);
  int k = 0;
  SORT( ps );
  vector<P> ch(2*n);
  for( int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
  for( int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
  ch.resize(k-1);
  return ch;
}

enum{ OUT , ON , IN };
int contains( const Pol pol, const P p) {
  bool in = false;
  for (int i = 0; i < pol.size(); ++i) {
    P a = curr(pol,i) - p, b = next(pol,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if( cross( a , b ) == 0 && dot( a , b ) <= 0 ) return ON;
  }
  return in ? IN : OUT;
}


ll px, py, qx, qy;
P p, q;
Pol a, b;
ll n, m;

ll x, y;

bool ans;

ll sq( ll x ){ return x * x; }

int main(){

  scanf( "%lld %lld" , &px , &py ); p = P( px , py );
  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld %lld" , &x , &y ), a.pb( P( x , y ) );

  scanf( "%lld %lld" , &qx , &qy ); q = P( qx , qy );
  scanf( "%lld" , &m );
  REP( i , m ) scanf( "%lld %lld" , &x , &y ), b.pb( P( x , y ) );

  REP( swap_swap , 2 ){

    REP( i , m ){
      P c = p + ( b[i] - q );
      ll rr = nor( p - q );

      REP( j , n ){
	P s = c - curr( a , j );
	P t = c - next( a , j );
	P u = next( a , j ) - curr( a , j );
	ll aa = nor( s );
	ll bb = nor( t );
	if( aa < rr && bb < rr ) continue;
	if( aa <= rr || bb <= rr || ( dot( s , u ) > 0 && dot( t , u ) < 0 && sq( cross( s , u ) ) <= rr * nor( u ) ) ) ans = true;
      }
    }
    
    swap( p , q );
    swap( a , b );
    swap( n , m );
  }

  if( ans ) printf( "YES\n" );
  else printf( "NO\n" );
  
  return 0;
}