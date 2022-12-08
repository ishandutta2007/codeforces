#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m , ta , tb , k;
int a[220000] , b[220000];
int ans;
void work () {
	int i , j;
	scanf ( "%d%d%d%d%d" , &n , &m , &ta , &tb , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &b[i] );
	}
	ans = -1;
	j = 1;
	if ( k >= n ) {
		printf ( "-1\n" );
		return ;
	}
	for ( i = 0 ; i <= min ( k , n ) ; i++ ) {
		while ( j <= m && b[j] < a[i+1] + ta ) j++;
		if ( j == m + 1 ) {
			printf ( "-1\n" );
			return ;
		}
		if ( j + (k-i) > m ) {
			printf ( "-1\n" );
			return ;
		}
		ans = max ( ans , b[j+(k-i)] + tb );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}