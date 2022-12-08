#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	long long n , i , a[110] , ans = 1 , sum;
	bool f = 0;
	scanf ( "%I64d" , &n );
	sum = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		if ( a[i] == 1 ) {
			f = 1;
			i++;
			break;
		}
	}
	for ( ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		if ( !a[i] ) sum++;
		else ans = ans * sum, sum = 1;
	}
	if ( f == 0 ) ans = 0;
	printf ( "%I64d" , ans );
	return 0;
}