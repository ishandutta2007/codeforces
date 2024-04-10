#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define razmak(x) cout << x << " _ "
#define red(x) cout << x << endl
using namespace std;

typedef pair<int, int> point;
typedef long long llint;

const int MaxN = 1e5 + 5;

int n;
string s[105];
vector <char> v[105];
bool bio[105][30];

int main() {

    int mx = -1;

    cin >> n;
    REP( i, n ) {
        cin >> s[i];
        REP( j, s[i].size() )
            if( !bio[i][ s[i][j] - 'a' ] ) {
                v[i].push_back( s[i][j] );
                bio[i][ s[i][j] - 'a' ] = true;
            }
    }

    REP( a, 26 ) {
        REP( b, 26 ) {
            if( a == b ) continue;
            int tmp = 0;
            REP( i, n ) {
                bool dobra = true;
                REP( j, v[i].size() )
                    if( ! ( v[i][j] == char( 'a' + a ) or v[i][j] == char( 'a' + b ) ) ) dobra = false;
                if( dobra ) tmp += s[i].size();
            }
            mx = max( mx, tmp );
        }
    }

    cout << mx;
    return 0;
}