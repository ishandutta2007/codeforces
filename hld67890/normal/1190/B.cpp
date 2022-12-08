#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120000];
long long ans;
void work () {
	int i , f = 0;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	sort ( a + 1 , a + 1 + n );
	for ( i = 2 ; i <= n ; i++ ) {
		if ( a[i] == a[i-1] ) {
			if ( a[i-1] == 0 ) {
				printf ( "cslnb\n" );
				return ;
			}
			if ( i >= 3 ) {
				if ( a[i-2] + 1 == a[i] ) {
					printf ( "cslnb\n" );
					return ;
				}
			}
			a[i-1]--;
			f = 1;
			break;
		}
	}
	for ( i ; i <= n ; i++ ) {
		if ( a[i] == a[i-1] ) {
			printf ( "cslnb\n" );
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		ans += (long long)(a[i]-i+1);
	}
	ans %= 2;
	ans ^= f;
	if ( ans == 0 ) {
		printf ( "cslnb\n" );
	}
	else printf ( "sjfnb\n" );
}
int main () {
	work ();
	return 0;
}