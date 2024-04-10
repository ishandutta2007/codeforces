#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
void work () {
	int i , a[120];
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	if ( n == 1 ) {
		if ( a[1] == 0 ) printf ( "UP\n" );
		else {
			if ( a[1] == 15 ) printf ( "DOWN\n" );
			else printf ( "-1\n" );
		}
	}
	else {
		if ( a[n] == 0 ) printf ( "UP\n" );
		else {
			if ( a[n] == 15 ) printf ( "DOWN\n" );
			else {
				if ( a[n] - a[n-1] > 0 ) {
					printf ( "UP\n" );
				}
				else printf ( "DOWN\n" );
			}
		}
	}
}
int main () {
	work ();
	return 0;
}