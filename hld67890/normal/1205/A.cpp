#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[210000];
void work () {
	int i;
	scanf ( "%d" , &n );
	if( n % 2 == 0 ) {
		printf ( "NO\n" );
	}
	else {
		printf ( "YES\n" );
		for ( i = 1 ; i <= n ; i++ ) {
			if ( i % 2 == 1 ) {
				a[i] = 2 * i - 1;
				a[i+n] = 2 * i;
			}
			else {
				a[i] = 2 * i;
				a[i+n] = 2 * i - 1;
			}
		}
		for ( i = 1 ; i <= n * 2 ; i++ ) {
			printf ( "%d " , a[i] );
		}
	}
}
int main () {
	work ();
	return 0;
}