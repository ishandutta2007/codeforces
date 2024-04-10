#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> point;
#define x first
#define y second
map< point, int > taken;
vector < point > v;

point p, d, t, c;
point p2, d2, t2, c2;
ld sol;
ld sol2;

ld lenght( point a, point b ) {
  return (ld)sqrt( (ld)( a.x - b.x )*( a.x - b.x ) + (ld)( a.y - b.y )*( a.y - b.y ) );
}

int n, m;
void ubaci() {
  cin >> n >> m;
  for( int i=0; i<=min(10,n); i++ )
    v.push_back( point( (ld)i, (ld)0 ) );
  for( int i=1; i<=min(10,m); i++ )
    v.push_back( point( (ld)0, (ld)i ) );
  for( int i=1; i<min(10,n); i++ )
    v.push_back( point( (ld)i, (ld)m ) );
  for( int i=1; i<=min(10,m); i++ )
    v.push_back( point( (ld)n, (ld)i ) );

  for( int i=n; i>=max(0,n-10); i-- )
    v.push_back( point( (ld)i, (ld)0 ) );
  for( int i=m; i>=max(0,m-10); i-- )
    v.push_back( point( (ld)0, (ld)i ) );
  for( int i=n; i>=max(0,n-10); i-- )
    v.push_back( point( (ld)i, (ld)m ) );
  for( int i=m; i>=max(0,m-10); i-- )
    v.push_back( point( (ld)n, (ld)i ) );
}

void solve1() {
  for( int i=0; i<v.size(); i++ ) {
    if( taken[ v[i] ] ) continue;
    taken[ v[i] ] = 1;
    for( int j=0; j<v.size(); j++ ) {
      if( taken[ v[j] ] ) continue;
      if( lenght( v[i], d ) + lenght( d, t ) + lenght( t, v[j] ) > sol ) {
        p = v[i], c = v[j];
        sol = lenght( v[i], d ) + lenght( d, t ) + lenght( t, v[j] );
      }
    }
    taken[ v[i] ] = 0;
  }
}

void solve2() {
  for( int i=0; i<v.size(); i++ ) {
    if( taken[ v[i] ] ) continue;
    taken[ v[i] ] = 1;
    for( int j=0; j<v.size(); j++ ) {
      if( taken[ v[j] ] ) continue;
      if( lenght( p2, d2 ) + lenght( d2, v[i] ) + lenght( v[i], v[j] ) > sol2 ) {
        t2 = v[i], c2 = v[j];
        sol2 = lenght( p2, d2 ) + lenght( d2, v[i] ) + lenght( v[i], v[j] );
      }
    }
    taken[ v[i] ] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  ubaci();
  d = point( 0, 0 ), t = point( n, m );
  p2 = point( 0, 0 ), d2 = point( n, m );
  taken[d] = 1; taken[t] = 1;
  solve1();
  solve2();
  if( sol > sol2 ) {
    cout << p.x << " " << p.y << endl;
    cout << d.x << " " << d.y << endl;
    cout << t.x << " " << t.y << endl;
    cout << c.x << " " << c.y;
  }else {
    cout << p2.x << " " << p2.y << endl;
    cout << d2.x << " " << d2.y << endl;
    cout << t2.x << " " << t2.y << endl;
    cout << c2.x << " " << c2.y;
  }
  return 0;
}