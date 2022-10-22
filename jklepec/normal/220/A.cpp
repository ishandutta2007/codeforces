#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 200100;

int a[MaxN], b[MaxN];

int main() {

	ios_base::sync_with_stdio(0);
	int n;
	int dif = 0;;
	cin >> n;
	for( int i=0; i<n; i++ ) {
		int x;
		cin >> x;
		a[i] = x;
		b[i] = x;
	}
	sort( a, a+n );
	for( int i=0; i<n; i++ ) {
		if( a[i] != b[i] ) dif++;
	}
	if( dif <=2 ) cout << "YES";
	else cout << "NO";
	return 0;
}