#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[410000];
int ans;
void work () {
	int i;
	scanf ( "%d" , &n );
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	if ( a[1] != a[n] ) printf ( "%d\n" , n - 1 );
	else {
		for ( i = 1 ; i <= n ; i++ ) {
			if ( a[i] != a[1] ) {
				ans = max ( ans , i - 1 );
				ans = max ( ans , n - i );
			}
		}
		printf ( "%d\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}