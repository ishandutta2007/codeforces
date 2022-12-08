#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[410000] , b[410000] , k;
void work () {
	int i , s1 , s2;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i == 1 || a[i] != a[i-1] ) k++;
		b[k]++;
	}
	//for ( i = 1 ; i <= k ; i++ ) printf ( " %d\n" , b[i] );
	if ( k <= 3 ) {
		printf ( "0 0 0\n" );
		return ;
	}
	s1 = s2 = 0;
	for ( i = 2 ; i <= k ; i++ ) {
		s1 += b[i];
		if ( s1 > b[1] ) break;
	}
	if ( i > k ) {
		printf ( "0 0 0\n" );
		return ;
	}
	for ( i++ ; i <= k ; i++ ) {
		s2 += b[i];
		if ( s2 > b[1] ) break;
	}
	if ( i > k ) {
		printf ( "0 0 0\n" );
		return ;
	}
	if ( (b[1] + s1 + s2) * 2 > n ) {
		printf ( "0 0 0\n" );
		return ;
	}
	for ( i++ ; i <= k ; i++ ) {
		if ( (b[1] + s1 + s2 + b[i]) * 2 <= n ) {
			s2 += b[i];
		}
		else break;
	}
	printf ( "%d %d %d\n" , b[1] , s1 , s2 );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) {
		work ();
		for ( int i = 1 ; i <= k ; i++ ) b[i] = 0;
		k = 0;
	}
	return 0;
}