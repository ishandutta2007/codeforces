#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[1200] , b[1200];
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &b[i] );
	}
	sort ( a + 1 , a + 1 + n );
	sort ( b + 1 , b + 1 + n );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , a[i] , i==n?'\n':' ' );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , b[i] , i==n?'\n':' ' );
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}