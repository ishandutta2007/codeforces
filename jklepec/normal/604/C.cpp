#include <iostream>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int A[MAXN];
int n;
int j;
int curj, curd;

int main() {

    ios_base::sync_with_stdio(false);

    string s;
    cin >> n >> s;
    n = s.size();
    FOR( i, 0, n ) {
        A[i] = s[i] - '0';
        if( A[i] )
            curj = curd + 1;
        else
            curd = curj + 1;
        if( !i ) continue;
        if( A[i] == A[i-1] ) j++;
    }

    int sol = max( curd, curj );
    j = min( 2, j );

    cout << sol + j;

    return 0;
}