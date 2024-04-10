#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[31000];
void work () {
	int i , j , old;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 2 ; i <= n ; i++ ) {
		if ( a[i] > a[i-1] ) {
			old = a[i];
			a[i] -= a[i-1];
			for ( j = i + 1 ; j <= n ; j++ ) {
				if ( a[j] > a[j-1] ) {
					int tmp = a[j] - max ( a[j-1] , a[j] - a[i-1] );
					a[j] = max ( a[j-1] , a[j] - a[i-1] );
					a[i-1] = tmp;
				}
				else break;
			}
			for ( j = n - 1 ; j >= i ; j-- ) {
				if ( a[j] > a[j+1] ) {
					printf ( "NO\n" );
					return ;
				}
			}
			printf ( "YES\n" );
			return ;
		}
	}
	printf ( "YES\n" );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) {
		work ();
	}
	return 0;
}