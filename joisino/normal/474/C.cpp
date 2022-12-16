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

bool eq( const ld &a , const ld &b ){
  return abs(a-b) < EPS;
}
bool eq( const P &a , const P &b ){
  return eq( a.X , b.X ) && eq( a.Y , b.Y );
}

inline ld det( const P &a , const P &b ){
  return imag(conj(a)*b);
}
inline ld dot( const P &a , const P &b ){
  return real(conj(a)*b);
}

inline ld len( const P &a ){
  return sqrt( norm( a ) );
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


bool is_sq( Pol pol ){
  REP( i , 4 ){
    if( !eq( len( curr(pol,i) - next(pol,i) ) , len( curr(pol,0) - next(pol,0) ) ) ) return false;
  }

  REP( i , 4 ) if( eq( curr(pol,i) , next(pol,i) ) ) return false;

  REP( i , 4 ) if( !eq( dot( curr(pol,i) - next(pol,i) , curr(pol,(i+1)%4) - next(pol,(i+1)%4) ) , 0 ) ) return false;

  return true;
}

int n;
int x[4], y[4], a[4], b[4];
P np[4], p[4], h[4];

int main(){
  
  scanf( "%d" , &n );

  REP( regiment_loop , n ){
    REP( i , 4 ){
      scanf( "%d %d %d %d" , &x[i] , &y[i] , &a[i] , &b[i] );
      p[i] = P( x[i] , y[i] );
      h[i] = P( a[i] , b[i] );
    }
    int ans = INF;
    REP( ta , 4 ) REP( tb , 4 ) REP( tc , 4 ) REP( td , 4 ){
      int ts[4] = { ta , tb , tc , td };
      REP( i , 4 ) np[i] = rotate( p[i] , h[i] , dtor( 90 * ts[i] ) );
      vi v(4);
      REP( i , 4 ) v[i] = i;
      bool ok = false;
      do{
	Pol pol(4);
	REP( i , 4 ) pol[i] = np[ v[i] ];
	if( is_sq( pol ) ) ok = true;
      } while( next_permutation( ALL(v) ) );
      if( ok ) chmin( ans , ta + tb + tc + td );
    }
    if( ans == INF ) printf( "-1\n" );
    else printf( "%d\n" , ans );
  }
  
  return 0;
}