#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int ans[1200];
int a[1200];
int sum;
void work () {
	int i , j , k , t , x;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) ans[i] = 1000000007;
	for ( i = 10 ; i >= 1 ; i-- ) {
		for ( j = 1 ; j <= 1000 ; j++ ) a[j] = 0;
		sum = 0;
		for ( j = 1 ; j <= 1000 ; j += (1<<i) ) {
			for ( k = j ; k <= j + (1<<(i-1)) - 1 ; k++ ) {
				a[k] = 1;
				if ( k <= n ) sum++;
			}
		}
		if ( sum != 0 ) {
			printf ( "%d\n" , sum );
			fflush(stdout);
			for ( j = 1 ; j <= n ; j++ ) {
				if ( a[j] == 1 ) printf ( "%d " , j );
			}
			printf ( "\n" );
			fflush(stdout);
			for ( j = 1 ; j <= n ; j++ ) {
				scanf ( "%d" , &x );
				if ( a[j] == 0 ) {
					//printf ( "### %d %d\n" , j , x );
					ans[j] = min ( ans[j] , x );
				}
			}
		}
		if ( n - sum != 0 ) {
			printf ( "%d\n" , n - sum );
			fflush(stdout);
			for ( j = 1 ; j <= n ; j++ ) {
				if ( a[j] == 0 ) printf ( "%d " , j );
			}
			printf ( "\n" );
			fflush(stdout);
			for ( j = 1 ; j <= n ; j++ ) {
				scanf ( "%d" , &x );
				if ( a[j] == 1 ) {
					ans[j] = min ( ans[j] , x );
					//printf ( "### %d %d\n" , j , x );
				}
			}
		}
	}
	printf ( "-1\n" );
	fflush(stdout);
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d " , ans[i] );
	printf ( "\n" );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}