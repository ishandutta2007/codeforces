#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int m[MAXN], w[MAXN];
int n;
vector < int > sol;
multiset< int > s;

int main() {

    //ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int N = n*n;

    FOR( i, 0, N ) {
        int x;
        cin >> x;
        s.insert( x );
    }

    while( sol.size() != n ) {
        int x = *( --s.end() );
        FOR( i, 0, sol.size() ) {
            int GCD = __gcd( x, sol[i] );
            s.erase( s.lower_bound( GCD ) );
            s.erase( s.lower_bound( GCD ) );
        }
        s.erase( s.lower_bound( x ) );
        sol.push_back( x );
    }

    FOR( i, 0, n )
        cout << sol[i] << " ";

    return 0;
}