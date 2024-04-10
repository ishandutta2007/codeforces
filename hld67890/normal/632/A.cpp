#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

int main () {
	long long s = 0 , p , k;
	char z[60][60];
	int i , n;
	scanf ( "%d%I64d" , &n , &p );
	k = 0;
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%s" , z[i] );
	for ( i = n ; i >= 1 ; i-- ) {
		if ( strlen ( z[i] ) == 8 ) {
			s += p / 2 + p * k;
			k = k * 2 + 1;
		}
		else {
			s += p * k;
			k = k * 2;
		}
	}
	printf ( "%I64d\n" , s );
	return 0;
}