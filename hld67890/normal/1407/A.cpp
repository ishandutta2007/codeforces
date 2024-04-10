#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[12000] , del[12000];
void work () {
	int i , j , k , s;
	scanf ( "%d" , &n );
	s = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		s += a[i];
	}
	if ( s <= n / 2 ) {
		printf ( "%d\n" , n / 2 );
		for ( i = 1 ; i <= n / 2 ; i++ ) {
			printf ( "%d%c" , 0 , i==n/2?'\n':' ' );
		}
	}
	else {
		if ( s % 2 == 1 ) s--;
		printf ( "%d\n" , s );
		for ( i = 1 ; i <= s ; i++ ) {
			printf ( "%d%c" , 1 , i==s?'\n':' ' );
		}
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}