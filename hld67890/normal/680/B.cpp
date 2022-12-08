#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k , a[1200];
int main () {
	int i , ans = 0;
	cin >> n >> k;
	for ( i = 1 ; i <= n ; i++ ) cin >> a[i];
	for ( i = 0 ; i <= n ; i++ ) {
		if ( k - i <= 0 && k + i > n ) break;
		if ( i == 0 ) {
			ans += a[k];
		}
		else {
			if ( k - i <= 0 || k + i > n ) {
				if ( k - i <= 0 ) ans += a[k+i];
				else ans += a[k-i];
			}
			else if ( a[k-i] == 1 && a[k+i] == 1 ) ans += 2;
		}
	}
	cout << ans << endl;
	return 0;
}