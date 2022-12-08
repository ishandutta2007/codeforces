#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[3000] , b[3000] , f[3000];
void work () {
	int i , j , ans , cnt;
	scanf ( "%d%d" , &n , &m );
	ans = n / m;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( a[i] <= m ) {
			b[a[i]]++;
			if ( b[a[i]] > ans ) f[i] = 1;
		}
		else f[i] = 1;
	}
	j = 1; cnt = 0;
	for ( i = 1 ; i <= m ; i++ ) {
		while ( b[i] < ans ) {
			while ( f[j] != 1 ) j++;
			f[j] = 0; cnt++;
			a[j] = i;
			b[i]++;
		}
	}
	printf ( "%d %d\n" , ans , cnt );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d" , a[i] );
		if ( i == n ) printf ( "\n" );
		else printf ( " " );
	}
}
int main () {
	work ();
	return 0;
}