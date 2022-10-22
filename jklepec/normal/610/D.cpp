#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; ++i )
#define all(a) (a).begin(), (a).end()
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 1e5 + 5;

struct dulj {
   int x, y;
   int h;
   dulj( int a, int b, int c ) {
      x = a; y = b; h = c;
   }
   friend bool operator < ( const dulj &A, const dulj &B ) {
      if( A.h == B.h ) {
         if( A.x == B.x )
            return A.y < B.y;
         return A.x < B.x;
      }
      return A.h < B.h;
   }
};

struct event {
   int tip;
   int x, lo, hi;
   event( int a, int b, int c, int d ) {
      x = a; lo = b; hi = c; tip = d;
   }
   friend bool operator < ( const event &A, const event &B ) {
      if( A.x == B.x ) {
         return A.tip < B.tip;
      }
      return A.x < B.x;
   }
};

vector< dulj > hor, ver, nh, nv;
vector< event > E;
set< int > s;
map< int, int > vis, rev;
llint sol;

int L[ 3 * MaxN ];
void update( int x, int val ) {
   for( ; x < 3 * MaxN; x += x&-x ) L[ x ] += val;
}
int get( int x, int ret = 0 ) {
   if( !x ) return 0;
   for( ; x; x -= x&-x ) ret += L[ x ];
   return ret;
}

void init() {
   int tmp = 1;
   for( set< int >::iterator it = s.begin(); it != s.end(); ++it ) {
      vis[ *it ] = tmp;
      rev[ tmp ] = *it;
      tmp ++;
   }
}

void solve() {
   for( int i = 0; i < E.size(); ++i ) {
      event tmp = E[ i ];
      if( tmp.tip == 0 )
         update( vis[ tmp.lo ], 1 );
      else if( tmp.tip == 1 )
         update( vis[ tmp.lo ], -1 );
      else {
         sol += tmp.hi - tmp.lo + 1;
         sol -= ( get( vis[ tmp.hi ] ) - get( vis[ tmp.lo - 1 ] ) );
      }
   }
}

int main() {
   int n; cin >> n;
   for( int i = 0; i < n; ++i ) {
      int x, y, a, b; cin >> x >> y >> a >> b;
      if( y == b ) {
         if( x > a ) swap( x, a );
         hor.push_back( dulj( x, a, b ) );
      }
      else {
         if( y > b ) swap( y, b );
         ver.push_back( dulj( y, b, x ) );
      }
      s.insert( y - 1 );
      s.insert( y );
      s.insert( b );
   }
   sort( all(hor) );
   sort( all(ver) );
   if( hor.size() ) {
   dulj l = hor[ 0 ];
   for( int i = 1; i < hor.size(); ++i ) {
      dulj tmp = hor[ i ];
      if( tmp.x > l.y + 1 or tmp.h != l.h ) {
         nh.push_back( l );
         l = tmp;
      }else if( l.y <= tmp.y ) {
         l.y = tmp.y;
      }
   }
   nh.push_back( l );}
   if( ver.size() ) {
   dulj l = ver[ 0 ];
   for( int i = 1; i < ver.size(); ++i ) {
      dulj tmp = ver[ i ];
      if( tmp.x > l.y + 1 or tmp.h != l.h ) {
         nv.push_back( l );
         l = tmp;
      }else if( l.y <= tmp.y ) {
         l.y = tmp.y;
      }
   }
   nv.push_back( l );}
   for( int i = 0; i < nv.size(); ++i ) {
      E.push_back( event( nv[ i ].h, nv[ i ].x, nv[ i ].y, 2 ) );
   }
   for( int i = 0; i < nh.size(); ++i ) {
      sol += ( nh[ i ].y - nh[ i ].x + 1 );
      E.push_back( event( nh[ i ].x, nh[ i ].h, 0, 0 ) );
      E.push_back( event( nh[ i ].y + 1, nh[ i ].h, 0, 1 ) );
   }
   sort( all(E) );
   init();
   solve();
   cout << sol;
   return 0;
}