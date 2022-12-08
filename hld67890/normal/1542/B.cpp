#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , a , b;
void work () {
	long long i , x;
	scanf ( "%lld%lld%lld" , &n , &a , &b );
	if ( a == 1 ) {
		if ( (n-1) % b == 0 ) printf ( "Yes\n" );
		else printf ( "No\n" );
		return ;
	}
	x = 1;
	for ( i = 0 ; x <= n ; i++ , x = x * a ) {
		if ( (n-x) % b == 0 ) {
			printf ( "Yes\n" );
			return ;
		}
	}
	printf ( "No\n" );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}