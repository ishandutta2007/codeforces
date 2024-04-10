#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
	char z[101000] , c[1000];
	int i , j , l1 , l2 , ans = 0 , f;
	scanf ( "%s" , z );
	scanf ( "%s" , c );
	l1 = strlen ( z ); l2 = strlen ( c );
	for ( i = 0 ; i <= l1 - l2 ; i++ ) {
		f = 1;
		for ( j = 0 ; j < l2 ; j++ ) if ( z[i+j] != c[j] ) f = 0;
		if ( f ) {
			ans++;
			z[i+l2-1] = '#';
		}
	}
	printf ( "%d\n" , ans );
	return 0;
}