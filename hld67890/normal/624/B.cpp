#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int main () {
	map < int , int > m;
	long long ans = 0;
	int i , n , a[200] , k;
	scanf ( "%d" , &n );
	for ( i = 1; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	k = -1;
	for ( i = n ; i >= 1 ; i-- ) {
		if ( m[a[i]] == 0 ) ans += a[i], k = a[i];
		else ans += k - 1, k = k - 1;
		m[k] = 1;
		if ( k == 0 ) break;
	}
	printf ( "%I64d\n" , ans );
	return 0;
}