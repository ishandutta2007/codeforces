#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int p[120];
char z[10];
int main () {
	int i , j , s = 0;
	for ( i = 2 ; i <= 100 ; i++ ) for ( j = 2 ; j < i ; j++ ) if ( i % j == 0 ) p[i] = 1;
	p[4] = p[9] = p[25] = p[49] = 0;
	for ( i = 2 ; i <= 50 ; i++ ) if ( p[i] == 0 ) {
		printf ( "%d\n" , i );
		fflush(stdout);
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'y' ) s++;
	}
	if ( s >= 2 ) printf ( "composite\n" );
	else printf ( "prime\n" );
	fflush(stdout);
	return 0;
}