#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
int n;
int a[maxn];
int sgn ( int x ) {
	if ( x > 0 ) return 1;
	if ( x == 0 ) return 0;
	if ( x < 0 ) return -1;
}
void work () {
	int l , r , mid;
	scanf ( "%d" , &n );
	if ( n % 4 == 2 ) {
		printf ( "! -1\n" );
		fflush(stdout);
		return ;
	}
	printf ( "? %d\n" , 1 );
	fflush(stdout);
	scanf ( "%d" , &a[1] );
	printf ( "? %d\n" , 1 + n / 2 );
	fflush(stdout);
	scanf ( "%d" , &a[1+n/2] );
	l = 1; r = n / 2;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d\n" , mid );
		fflush(stdout);
		scanf ( "%d" , &a[mid] );
		printf ( "? %d\n" , mid + n / 2 );
		fflush(stdout);
		scanf ( "%d" , &a[mid+n/2] );
		if ( a[mid] == a[mid+n/2] ) {
			printf ( "! %d\n" , mid );
			fflush(stdout);
			return ;
		}
		if ( sgn(a[1+n/2]-a[1]) == sgn (a[mid+n/2]-a[mid]) ) {
			l = mid;
		}
		else r = mid;
		//printf ( "%d %d\n" , l , r );
	}
	printf ( "? %d\n" , l );
	fflush(stdout);
	scanf ( "%d" , &a[l] );
	printf ( "? %d\n" , l + n / 2 );
	fflush(stdout);
	scanf ( "%d" , &a[l+n/2] );
	if ( a[l] == a[l+n/2] ) {
		printf ( "! %d\n" , l );
		fflush(stdout);
		return ;
	}
	printf ( "? %d\n" , r );
	fflush(stdout);
	scanf ( "%d" , &a[r] );
	printf ( "? %d\n" , r + n / 2 );
	fflush(stdout);
	scanf ( "%d" , &a[r+n/2] );
	if ( a[r] == a[r+n/2] ) {
		printf ( "! %d\n" , r );
		fflush(stdout);
		return ;
	}
	printf ( "! -1\n" );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}