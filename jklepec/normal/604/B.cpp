#include <iostream>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int A[MAXN];
int n, k;

int main() {

    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    FOR( i, 0, n )
        cin >> A[i];

    int i, sol = 0, j;
    for( i = n-1; i >= 0; --i ) {
        if( 2*(k-1) >= n - 1 )
            sol = max( sol, A[i] ), --k, --n;
        else
            break;
    }

    for( i = 0, j = n-1; i < j; ++i, --j )
        sol = max( sol, A[i] + A[j] );


    cout << sol;
    return 0;
}