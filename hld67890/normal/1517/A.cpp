#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long x;
void work () {
	scanf ( "%lld" , &n );
	if ( n % 2050 == 0 ) {
		x = 0;
		n = n / 2050;
		while ( n ) {
			x = x + (n%10);
			n = n / 10;
		}
		printf ( "%lld\n" , x );
	}
	else {
		printf ( "-1\n" );
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}