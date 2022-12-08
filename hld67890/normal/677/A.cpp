#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int n , h , ans = 0 , i , a;
	cin >> n >> h;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> a;
		if ( a > h ) ans += 2;
		else ans++;
	}
	cout << ans << endl;
	return 0;
}