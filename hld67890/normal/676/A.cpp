#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int n , i , a[1200] , b , c;
	cin >> n;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> a[i];
		if ( a[i] == 1 ) b = i;
		if ( a[i] == n ) c = i;
	}
	cout << n - min ( min ( b , c ) , min ( n - b , n - c ) + 1 ) << endl;
	return 0;
}