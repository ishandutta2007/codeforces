#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int a[1200];
void work () {
	int i , ans = 0;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	a[0] = k;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] + a[i-1] < k ) {
			ans += k - (a[i]+a[i-1]);
			a[i] = k - a[i-1];
		}
	}
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d" , a[i] );
		if ( i != n ) printf ( " " );
		else printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}