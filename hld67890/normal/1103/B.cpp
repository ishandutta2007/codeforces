#include <stdio.h>
#include <algorithm>

using namespace std;

int l , r , ll , rr , mid;
char x[12];
void work () {
	l = 1; r = 2;
	printf ( "? 0 1\n" );
	fflush(stdout);
	scanf ( "%s" , x + 1 );
	if ( x[1] == 'x' ) {
		printf ( "! 1\n" );
		fflush(stdout);
		return ;
	}
	while ( 1 ) {
		printf ( "? %d %d\n" , l , r );
		fflush(stdout);
		scanf ( "%s" , x + 1 );
		if ( x[1] == 'x' ) break;
		else {
			l = r;
			r = r * 2;
		}
	}
	ll = l; rr = r;
	while ( ll < rr - 1 ) {
		mid = (ll+rr)/2;
		printf ( "? %d %d\n" , l , mid );
		fflush(stdout);
		scanf ( "%s" , x + 1 );
		if ( x[1] == 'x' ) {
			rr = mid;
		}
		else ll = mid;
	}
	printf ( "! %d\n" , rr );
	fflush(stdout);
}
int main () {
	char z[120];
	while ( 1 ) {
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'e' ) break;
		work ();
	}
	return 0;
}