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

#define X real()
#define Y imag()

#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]

typedef complex<ld> P;
typedef vector<P> Pol;

namespace std{
  template<class T> bool operator<(const complex<T> &a , const complex<T> &b ){
    return a.X == b.X ? a.Y < b.Y : a.X < b.X;
  }
}

const ld PI = atan(1)*4.0;

struct L : public vector<P> {
  L( const P a , const P b ){
    pb( a ); pb( b );
  }
  L(){}
};

struct C{
  P p; ld r;
  C( const P p , ld r ) : p(p) , r(r) {}
  C(){}
};

inline ld det( const P &a , const P &b ){
  return imag(conj(a)*b);
}
inline ld dot( const P &a , const P &b ){
  return real(conj(a)*b);
}

inline P unit( const P &a ){
  return a / abs( a );
}

inline ld arg( const P &p ){
  return atan2l( p.Y , p.X );
}

inline P ort( P a ){
  return P( -a.Y , a.X );
}

inline P mid( const P a , const P b ){
  return ( a + b ) * (ld)0.5;
}

ld dtor( ld d ){
  return d * PI / 180.0;
}

int ccw( P a , P b , P c ){
  b -= a; c -= a;
  if( det( b , c ) >  EPS )     return +1; // counter clockwise
  if( det( b , c ) < -EPS )     return -1; // clockwise
  if( dot( b , c ) < -EPS )     return +2; // c--a--b on line
  if( norm(b) < norm(c) - EPS ) return -2; // a--b--c on line
  return 0;
}

bool intersectLL( const L &l , const L &m ){
  return abs( det( l[1] - l[0] , m[1] - m[0] ) ) > EPS || abs( det( l[1] - l[0] , m[0] - l[0] ) ) < EPS;
}

bool parallel( const L l , const L m ){
  return abs( det( l[1] - l[0] , m[1] - m[0] ) ) < EPS;
}

bool intersectSP( const L &s , const P &p ){
  return abs( s[0] - p ) + abs( s[1] - p ) - abs( s[1] - s[0] ) < EPS;
}

bool intersectLP( const L l , const P p ){
  return abs( det( l[1] - p , l[0] - p ) ) < EPS;
}

// including touch
bool intersectSS( const L s , const L t ){
  return ccw( s[0] , s[1] , t[0] ) * ccw( s[0] , s[1] , t[1] ) <= 0 && ccw( t[0] , t[1] , s[0] ) * ccw( t[0] , t[1] , s[1] ) <= 0;
}

bool intersectLS( const L l , const L s ){
  return det( l[1] - l[0] , s[0] - l[0] ) * det( l[1] - l[0] , s[1] - l[0] ) < EPS;
}

P projection( const L &l , const P &p ){
  ld t = dot( p - l[0] , l[1] - l[0] ) / norm( l[1] - l[0] );
  return l[0] + t * ( l[1] - l[0] );
}

P symmetry( const L l , const P p ){
  P proj = projection( l , p );
  return proj + ( proj - p );
}

ld distanceSP( const L &s , const P &p ){
  const P r = projection( s , p );
  if( intersectSP( s , r ) ) return abs( r - p );
  return min( abs( s[0] - p ) , abs( s[1] - p ) );
}

int n;

double x, y;

P c;
P p[100010];

int main(){

  n = in();
  x = in();
  y = in();

  c = P( x , y );

  REP( i , n ){
    x = in();
    y = in();
    p[i] = P( x , y );
  }

  double ma = -INF;
  double mi = INF;
  REP( i , n ){
    double d = abs( p[i] - c );
    chmax( ma , d );
    chmin( mi , d );
  }

  REP( i , n ){
    P cur = p[i];
    P nex = p[(i+1)%n];
    L l = L( cur , nex );
    double d = distanceSP( l , c );
    chmax( ma , d );
    chmin( mi , d );
  }
  

  double ans = ma * ma * PI - mi * mi * PI;

  printf( "%.18lf\n" , ans );
  
  return 0;
}