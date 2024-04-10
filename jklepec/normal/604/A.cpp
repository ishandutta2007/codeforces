#include <bits/stdc++.h>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int m[MAXN], w[MAXN];
int n;

int main() {

    ios_base::sync_with_stdio(false);

    double sol = 0;

    FOR( i, 0, 5 )
        cin >> m[i];
    FOR( i, 0, 5 )
        cin >> w[i];

    FOR( i, 0, 5 )
        sol += max( double( 0.3*(double)(i+1)*500. ), ( (double)1 - (double)m[i]/(double)250. )*(double)(i+1)*500. - (double)50*(double)w[i] );
    double a, b;
    cin >> a >> b;
    cout << max( 0., sol + 100.*a - 50.*b );


    return 0;
}