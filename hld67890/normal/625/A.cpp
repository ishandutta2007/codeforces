#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	long long a , b , c , n , ans;
	scanf ( "%I64d%I64d%I64d%I64d" , &n , &a , &b , &c );
	c = b - c;
	if ( n < b && n < a ) {
		printf ( "0\n" );
		return 0;
	}
	if ( c <= a && n >= b ) {
		ans = (n-b)/c+1;
		//cout <<n <<  " " << ans << " " << c << " " << a << endl;
		ans += (n-ans*c)/a;
		printf ( "%I64d\n" , ans );
	}
	else printf ( "%I64d\n" , n / a );
	return 0;
}