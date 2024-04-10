#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = (a); i < (b); i++ )
#define REP( i, a ) for( int i = 0; i < (a); i++ )
using namespace std;

const int MaxN = 100100, LOG = 19, MOD = 1e9 + 7, B = 3137;
typedef pair< int, int > point;
typedef long long llint;

int add(int x, int y) {
    return (x + y) % MOD;
}
int mult(int x, int y) {
    return (llint)x * y % MOD;
}
int sub(int x, int y) {
    x -= y;
    if (x < 0)
       x += MOD;
    else
        x %= MOD;
    return x;
}


vector < int > f[MaxN], sol;

int main() {

    int n, m;

    cin >> n >> m;

    REP( i, n ) {
        int x;
        cin >> x;
        f[x].push_back(i + 1);
    }

    bool am = false;

    REP( i, m ) {
        int x;
        cin >> x;
        if( f[x].size() > 1 )
            am = true;
        else if( f[x].size() == 1 )
            sol.push_back( f[x][0] );
        else {
            cout << "Impossible";
            return 0;
        }
    }

    if( am )
        cout << "Ambiguity";
    else {
        cout << "Possible\n";
        REP( i, m )
            cout << sol[i] << " ";
    }
    return 0;
}