#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[120000];
void work () {
	int i , j , k;
	scanf ( "%d%d" , &n , &m );
	a[1] = 1; a[2] = 2;
	for ( i = 3 ; i <= n ; i++ ) {
		if ( m < (i-1) / 2 ) {
			j = i;
			k = (i-1) / 2;
			for ( ; k != m ; k-- , j += 2 );
			a[i] = j;
			for ( i++ ; i <= n ; i++ ) {
				a[i] = 800000000 + 20000 * i;
			}
			m = 0;
			break;
		}
		else {
			a[i] = i;
			m -= (i-1) / 2;
		}
	}
	if ( m != 0 ) {
		printf ( "-1\n" );
		return ;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , a[i] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}