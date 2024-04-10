#include <iostream>
#include <stdio.h>

using namespace std;

int n , k;
int a , b , c , d;
int main () {
	int i , tmp;
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	if ( n == 4 || k <= n ) {
		cout << -1 << endl;
		return 0;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i != a && i != b && i != c && i != d ) tmp = i;
	}
	cout << a;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i != tmp && i != a && i != b && i != c && i != d ) cout << " " << i;
	}
	cout << " " << c << " " << tmp << " " << d << " " << b << endl;
	cout << c;
	for ( i = n ; i >= 1 ; i-- ) {
		if ( i != tmp && i != a && i != b && i != c && i != d ) cout << " " << i;
	}
	cout << " " << a << " " << tmp << " " << b << " " << d << endl;
	return 0;
}