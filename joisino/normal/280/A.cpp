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

double w, h, a;

Pol pol, npol;

int main(){

  cin >> w >> h >> a;
  pol.pb( w/2 , h/2 );
  pol.pb( -w/2 , h/2 );
  pol.pb( -w/2 , -h/2 );
  pol.pb( w/2 , -h/2 );


  npol = rotate( pol , dtor(a) );
  REP( i , 4 ) pol = convex_cut( pol , L(curr(npol,i),next(npol,i)) )[0];

  printf( "%.18lf\n" , (double)area( pol ) );
  
  return 0;
}