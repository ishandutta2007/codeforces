#include <iostream>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int n;

int main() {

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if( ( a + b + c + d + e ) % 5 == 0 and ( a + b + c + d + e ) > 0 )
        cout << ( a + b + c + d + e ) / 5;
    else
        cout << -1;

    return 0;
}