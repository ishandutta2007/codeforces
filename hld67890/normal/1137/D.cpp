#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char z[120][120];
int ex[120];
void work () {
	int i , j , k , f;
	j = 0;
	while ( 1 ) {
		if ( j ) {
			printf ( "next 0 1\n" );
			fflush(stdout);
			scanf ( "%d" , &k );
			f = 0;
			for ( i = 1 ; i <= k ; i++ ) {
				scanf ( "%s" , z[i] + 1 );
				ex[0] = ex[1] = 0;
				for ( int l = 1 ; l <= strlen ( z[i] + 1 ) ; l++ ) {
					ex[z[i][l]-'0']++;
				}
				if ( ex[0] == 1 && ex[1] == 1 ) {
					f = 1;
				}
			}
			if ( f == 1 ) break;
		}
		else {
			printf ( "next 0\n" );
			fflush(stdout);
			scanf ( "%d" , &k );
			for ( i = 1 ; i <= k ; i++ ) {
				scanf ( "%s" , z[i] + 1 );
			}
		}
		j ^= 1;
	}
	while ( 1 ) {
		printf ( "next 0 1 2 3 4 5 6 7 8 9\n" );
		fflush(stdout);
		scanf ( "%d" , &k );
		for ( i = 1 ; i <= k ; i++ ) scanf ( "%d" , &z[i] + 1 );
		if ( k == 1 ) break;
	}
	printf ( "done\n" );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}