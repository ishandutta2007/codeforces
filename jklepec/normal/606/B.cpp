#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 100100, MOD = 1e9 + 7, B = 3137;

int sol[MaxN];
int x, y;
int n, m;
bool bio[501][501];
int uk;

bool pomakni( int dx, int dy ) {
    if( x + dx < 1 or x + dx > n )
        return false;
    else
        x += dx;
    if( y + dy < 1 or y + dy > m )
        return false;
    else
        y += dy;
    return true;
}

int main() {

    //ios_base::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    string s; cin >> s;
    uk = 1;
    sol[0] = 1;
    bio[x][y] = true;
    REP( i, s.size() ) {
        int down = 0, rght = 0;
        if( s[i] == 'U' ) down = -1;
        if( s[i] == 'D' ) down =  1;
        if( s[i] == 'R' ) rght =  1;
        if( s[i] == 'L' ) rght = -1;
        if( pomakni( down, rght ) and !bio[x][y] ) {
            sol[i+1] = 1;
            uk ++;
            if( bio[x][y] )
                sol[i+1] = n*m - uk;
        }
        else
            sol[i+1] = 0;
        bio[x][y] = true;
    }

    sol[s.size()] = n*m - uk + sol[s.size()];

    REP( i, s.size()+1 )
        cout << sol[i] << " ";
    return 0;
}