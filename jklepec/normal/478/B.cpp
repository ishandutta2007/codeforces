#include <iostream>
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
using namespace std;

const int MAXN = 100100, MOD = 1e9+7, B = 3137;

typedef long long llint;
typedef pair<int, int> point;

int main() {

    llint n, m;
    cin >> n;
	cin >> m;
	llint mn = 0, mx = 0;
	mn = ( n % m ) * ( n / m ) * ( n / m + 1 ) / 2 + ( m - n % m ) * ( n / m ) * ( n / m - 1 ) / 2;
	mx = ( n - m + 1 ) * ( n - m ) / 2;
	cout << mn << " " << mx;
    return 0;

}