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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

#define X real()
#define Y imag()

#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]

typedef complex<ld> P;
typedef vector<P> Pol;

const ld PI = atan(1)*4.0;

struct L : public vector<P> {
  L( const P &a , const P &b ){
    pb( a ); pb( b );
  }
};

inline ld det( const P &a , const P &b ){
  return imag(conj(a)*b);
}
inline ld dot( const P &a , const P &b ){
  return real(conj(a)*b);
}

ld dtor( ld d ){
  return d * PI / 180.0;
}

int ccw( P a , P b , P c ){
  b -= a; c -= a;
  if( det( b , c ) >  EPSLD )     return +1; // counter clockwise
  if( det( b , c ) < -EPSLD )     return -1; // clockwise
  if( dot( b , c ) < -EPSLD )     return +2; // c--a--b on line
  if( norm(b) < norm(c) - EPSLD ) return -2; // a--b--c on line
  return 0;
}

bool intersectSP( const L &s , const P &p ){
  return abs( s[0] - p ) + abs( s[1] - p ) - abs( s[1] - s[0] ) < EPS;
}

P projection( const L &l , const P &p ){
  ld t = dot( p - l[0] , l[1] - l[0] ) / norm( l[1] - l[0] );
  return l[0] + t * ( l[1] - l[0] );
}

ld distanceSP( const L &s , const P &p ){
  const P r = projection( s , p );
  if( intersectSP( s , r ) ) return abs( r - p );
  return min( abs( s[0] - p ) , abs( s[1] - p ) );
}

P crosspoint( const L &l , const L &m ){
  ld a = det( l[1] - l[0] , m[1] - m[0] );
  ld b = det( l[1] - l[0] , l[1] - m[0] );
  if( abs(a) < EPSLD && abs(a) < EPSLD ) return m[0];
  if( abs(a) < EPSLD ) assert(false);
  return m[0] + b / a * (m[1]-m[0]);
}

P rotate( P p , ld t ){
  return p * exp( t * P( 0 , 1 ) );
}

Pol rotate( Pol pol , ld t ){
  YYS( p , pol ) p = rotate( p , t );
  return pol;
}

P rotate( P p , P c , ld t ){
  return rotate( p - c , t ) + c;
}

// first : left , second : right
vector<Pol> convex_cut( const Pol &pol, L l ){
  vector<Pol> Q(2);
  REP( i , pol.size() ){
    P a = curr(pol,i), b = next(pol,i);
    if( ccw(l[0] , l[1] , a ) != -1 ) Q[0].pb( a );
    if( ccw(l[0] , l[1] , a ) != 1  ) Q[1].pb( a );
    if( ccw(l[0] , l[1] , a )*ccw(l[0] , l[1] , b ) < 0 ){
      Q[0].pb( crosspoint( L(a,b) , l ) );
      Q[1].pb( crosspoint( L(a,b) , l ) );
    }
  }
  return Q;
}

ld area( const Pol &pol ){
  ld a = 0;
  REP( i , pol.size() ) a += det( curr(pol,i) , next(pol,i) );
  return a/2;
}


enum{ OUT , ON , IN };
int contains( const Pol pol, const P p) {
  bool in = false;
  REP( i , SZ(pol) ){
    P a = curr(pol,i) - p, b = next(pol,i) - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) < EPSLD && EPSLD < imag(b))
      if( det(a, b) < -EPSLD) in = !in;
    if( abs( det( a , b ) ) < EPSLD && dot( a , b ) < EPSLD ) return ON;
  }
  return in ? IN : OUT;
}


const ll MAX_N = 100010;

ll n, m;
ll x[MAX_N], y[MAX_N];

Pol p, q;
P g = P ( 0.0 , 0.0 );

ld ans;

int main(){
  scanf( "%lld" , &n );
  REP( i , n ) scanf( "%lld %lld" , &x[i] , &y[i] );
  REP( i , n ) p.pb( P( x[i] , y[i] ) );

  REP( i , n ) g += p[i];
  g = g * ( 1.0 / (ld)n );

  REP( i , n ) ans += norm( p[i] - g );

  scanf( "%lld" , &m );
  REP( i , m ) scanf( "%lld %lld" , &x[i] , &y[i] );
  REP( i , m ) q.pb( P( x[i] , y[i] ) );
  REVERSE( q );

  if( contains( q , g ) != IN ){
    ld res = INFLL;
    REP( i , m ) chmin( res , distanceSP( L( curr(q,i) , next(q,i) ) , g ) );
    ans += n * res * res;
  }

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}