#include <iostream>
#include <stdio.h>

using namespace std;

long long n;
int main () {
	scanf ( "%I64d" , &n );
	if ( n == 1 || n == 2 ) {
		printf ( "-1\n" );
		return 0;
	}
	if ( n % 2 == 0 ) printf ( "%I64d %I64d\n" , (n/2)*(n/2) + 1 , (n/2)*(n/2) - 1 );
	else printf ( "%I64d %I64d\n" , (n*n-1) / 2 , (n*n-1) / 2 + 1 );
	return 0;
}