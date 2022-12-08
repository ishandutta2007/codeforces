#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m , k;
int dislr[510][510] , disud[510][510];
int dp[22][510][510];
void work () {
	int i , j , l;
	scanf ( "%d%d%d" , &n , &m , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m - 1 ; j++ ) {
			scanf ( "%d" , &dislr[i][j] );
		}
	}
	for ( i = 1 ; i <= n - 1 ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			scanf ( "%d" , &disud[i][j] );
		}
	}
	if ( k % 2 == 1 ) {
		for ( i = 1 ; i <= n ; i++ ) {
			for ( j = 1 ; j <= m ; j++ ) {
				printf ( "%d%c" , -1 , j==m?'\n':' ' );
			}
		}
		return ;
	}
	for ( i = 1 ; i <= k / 2 ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			for ( l = 1 ; l <= m ; l++ ) {
				dp[i][j][l] = 200000000;
				if ( l != 1 )
					dp[i][j][l] = min ( dp[i][j][l] , dp[i-1][j][l-1] + 2 * dislr[j][l-1] );
				if ( l != m )
					dp[i][j][l] = min ( dp[i][j][l] , dp[i-1][j][l+1] + 2 * dislr[j][l] );
				if ( j != 1 ) 
					dp[i][j][l] = min ( dp[i][j][l] , dp[i-1][j-1][l] + 2 * disud[j-1][l] );
				if ( j != n )
					dp[i][j][l] = min ( dp[i][j][l] , dp[i-1][j+1][l] + 2 * disud[j][l] );
			}
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			printf ( "%d%c" , dp[k/2][i][j] , j==m?'\n':' ' );
		}
	}
}
int main () {
	work ();
	return 0;
}