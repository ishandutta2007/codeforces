#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[1200];
void work () {
	int i , j , mx , t , ti;
	scanf ( "%d" , &n );
	mx = -1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		mx = max ( mx , a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		t = -1; ti = 0;
		for ( j = 1 ; j <= n ; j++ ) {
			if ( a[j] > 0 && __gcd ( mx , a[j] ) > t ) {
				t = __gcd ( mx , a[j] );
				ti = j;
			}
		}
		printf ( "%d%c" , a[ti] , i==n?'\n':' ' );
		mx = t;
		a[ti] = -1;
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}