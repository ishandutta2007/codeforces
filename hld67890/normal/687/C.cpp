#include <iostream>
#include <stdio.h>

using namespace std;

int n , k;
int a[12000] , dp[1100][1100] , f[1100];
int ans;
void work () {
	int i , j , l , o , last;
	scanf ( "%d%d" , &n , &k );
	dp[0][0] = 1; f[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		for ( j = k ; j >= a[i] ; j-- ) {
			//cout << f[j-a[i]] << endl;
			if ( f[j-a[i]] ) {
				f[j]= 1;
				dp[j][j] = 1;
				for ( l = 0 ; l <= k ; l++ ) dp[j][l] = max ( dp[j][l] , dp[j-a[i]][l] ), dp[j][l+a[i]] = max ( dp[j][l+a[i]] , dp[j-a[i]][l] );
			}
		}
		//for ( j = 0 ; j <= k ; j++ ) for ( l = 1 ; l <= k ; l++ ) cout << j << " " << l << " " << dp[j][l] << endl;
		//cout << endl;
	}
	for ( i = 0 ; i <= k ; i++ ) if ( dp[k][i] ) ans++, last = i;
	printf ( "%d\n" , ans );
	for ( i = 0 ; i <= k ; i++ )
		if ( dp[k][i] ) {
			printf ( "%d" , i );
			if ( i != last ) printf ( " " );
		}
}
int main () {
	work ();
	return 0;
}