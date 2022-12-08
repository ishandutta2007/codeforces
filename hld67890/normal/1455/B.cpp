#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long check ( long long x ) {
	long long i , tot;
	tot = (x+1) * x / 2;
	if ( tot == n ) return 1;
	for ( i = 1 ; i <= x ; i++ ) {
		if ( tot - 1 - i == n ) return 1;
	}
	return 0;
}
void work () {
	long long i , t = 0;
	scanf ( "%lld" , &n );
	for ( i = 1 ; t < n ; i++ ) {
		t += i;
	}
	i--;
	//printf ( "##%d %d\n" , i , t );
	if ( check ( i ) ) {
		printf ( "%lld\n" , i );
	}
	else printf ( "%lld\n" , i + 1 );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}