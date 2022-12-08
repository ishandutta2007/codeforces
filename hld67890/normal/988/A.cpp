#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int a[200] , b[200];
void work () {
	int i , s , x;
	scanf ( "%d%d" , &n , &k );
	s = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &x );
		if ( !a[x] ) {
			b[++s] = i;
			a[x] = 1;
		}
	}
	if ( s >= k ) {
		printf ( "YES\n" );
		for ( i = 1 ; i <= k ; i++ ) printf ( "%d%c" , b[i] , i==k?'\n':' ' );
	}
	else {
		printf ( "NO\n" );
	}
}
int main () {
	work ();
	return 0;
}