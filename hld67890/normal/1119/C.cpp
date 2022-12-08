#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 510;
int n , m;
int a[maxn][maxn] , b[maxn][maxn];
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ )
		for ( j = 1 ; j <= m ; j++ )
			scanf ( "%d" , &a[i][j] );
	for ( i = 1 ; i <= n ; i++ )
		for ( j = 1 ; j <= m ; j++ )
			scanf ( "%d" , &b[i][j] );
	for ( i = 2 ; i <= n ; i++ ) {
		for ( j = 2 ; j <= m ; j++ ) {
			if ( a[i][j] ) {
				a[1][1] ^= 1;
				a[1][j] ^= 1;
				a[i][1] ^= 1;
				a[i][j] = 0;
			}
			if ( b[i][j] ) {
				b[1][1] ^= 1;
				b[1][j] ^= 1;
				b[i][1] ^= 1;
				b[i][j] = 0;
			}
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			if ( a[i][j] != b[i][j] ) {
				printf ( "No\n" );
				return ;
			}
		}
	}
	printf ( "Yes\n" );
}
int main () {
	work ();
	return 0;
}