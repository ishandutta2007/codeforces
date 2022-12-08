#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[300000] , ans[300000] , cnt;
void work () {
	int i , j , m , s;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	j = 1;
	for ( i = 1 ; i <= m ; i++ ) {
		if ( a[j] == i ) {
			j++;
			continue;
		}
		m -= i;
		ans[++cnt] = i;
	}
	printf ( "%d\n" , cnt );
	if ( cnt ) printf ( "%d" , ans[1] );
	for ( i = 2 ; i <= cnt ; i++ ) printf ( " %d" , ans[i] );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}