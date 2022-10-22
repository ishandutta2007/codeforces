#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = (a); i < (b); i++ )
#define REP( i, a ) for( int i = 0; i < (a); i++ )
#define np point( 0, 0 )
#define p1g point( p1.x, p1.y + 1 )
#define p1d point( p1.x + 1, p1.y )
#define p2g point( p2.x, p2.y + 1 )
#define p2d point( p1.x + 1, p1.y )
#define p1val ( p1.y - p1.x )
#define p2val ( p2.y - p2.x )
using namespace std;

const int MaxN = 100100, LOG = 19, MOD = 1e9 + 7, B = 3137;
//typedef pair< int, int > point;
typedef long long llint;

int w[MaxN], cnt, n;
bool NO;

struct point {
    int x, y, val;

    point( int _x, int _y ) {
        x = _x;
        y = _y;
        val = y - x;
    }

    friend bool operator < ( const point &A, const point &B ) {
        return A.val < B.val;
    }


};

map< point, int > t, ob;
set< point > s;
set< point >::iterator it;
vector< point > v;

point p1 = point( 0, 1 ), p2 = point( 1, 0 );
/*
bool moze( point A, point B ) {

    if( A.x >= B.x and A.y >= B.y ) return false;
    if( B.x >= A.x and B.y >= A.y ) return false;
    return true;

}*/

void solve() {

    cnt++;

    if( cnt == n ) return;

    it = s.lower_bound( point( 0, w[cnt] ) );

    if( it == s.end() ) {
        NO = true;
        return;
    }

    point p = *it;

    if( p.val != w[cnt] ) {
        NO = true;
        return;
    }

    ob[p] = 1;
    v.push_back( p );
    s.erase( it );

    p = point( p.x, p.y + 1 );
    if( t[p] )
        if( ob[ point( p.x - 1, p.y ) ] or p.x == 0 )
            s.insert( p );

    p = point( p.x + 1, p.y - 1 );
    if( t[p] )
        if( ob[ point( p.x, p.y - 1 ) ] or p.y == 0 )
            s.insert( p );

    solve();

}


int main() {

    ios_base::sync_with_stdio( false );

    cin >> n;
    v.push_back( point( 0, 0 ) );
    ob[ point( 0, 0 ) ] = 1;

    REP( i, n ) {
        int x, y;
        cin >> x >> y;
        t[ point( x, y ) ] = 1;
    }

    REP( i, n )
        cin >> w[i];

    if( w[0] != 0 ) {
        cout << "NO";
        return 0;
    }

    if( t[ point( 1, 0 ) ] ) s.insert( point( 1, 0 ) );
    if( t[ point( 0, 1 ) ] ) s.insert( point( 0, 1 ) );


    solve();

    if( NO )
        cout << "NO";
    else {
        cout << "YES" << endl;
        REP( i, n )
            cout << v[i].x << " " << v[i].y << endl;

    }

    return 0;
}