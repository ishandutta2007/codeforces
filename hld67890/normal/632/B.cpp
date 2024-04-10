#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

long long n , p[600000];
char z[600000];
int main () {
	int i;
	long long s , maxx , s1;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &p[i] );
	scanf ( "%s" , z + 1 );
	s = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'B' ) s += p[i];
	}
	maxx = s1 = s;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'A' ) s += p[i];
		else s -= p[i];
		if ( s > maxx ) maxx = s;
	}
	s = s1;
	for ( i = n ; i >= 1 ; i-- ) {
		if ( z[i] == 'A' ) s += p[i];
		else s -= p[i];
		if ( s > maxx ) maxx = s;
	}
	printf ( "%I64d" , maxx );
	return 0;
}