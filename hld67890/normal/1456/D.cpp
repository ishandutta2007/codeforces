#include <stdio.h>
#include <algorithm>

using namespace std;

long long n;
long long a[5100] , t[5100];
long long go[5100][5100];
long long dp[5100][3];
void work () {
	long long i , j , l , pos , tim;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld%lld" , &t[i] , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		go[i][i] = 1;
		for ( j = i + 1 ; j <= n ; j++ ) {
			if ( go[i][j-1] == 1 && t[j-1] + abs ( a[j-1] - a[j] ) <= t[j] ) {
				go[i][j] = 1;
			}
		}
	}
	dp[0][1] = 0;
	dp[0][2] = 2147483647777ll;
	for ( i = 1 ; i <= n ; i++ ) {
		dp[i][1] = dp[i][2] = 2147483647777ll;
	}
	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 1 ; j <= 2 ; j++ ) {
			if ( dp[i][j] != 2147483647777ll ) {
				if ( j == 1 ) {
					pos = a[i];
					tim = dp[i][j];
				}
				else {
					pos = a[i-1];
					tim = t[i-1];
				}
				if ( abs ( pos - a[i+1] ) <= t[i+1] - tim ) {
					dp[i+1][1] = min ( dp[i+1][1] , max ( t[i] , tim + abs ( pos - a[i+1] ) ) );
				}
				for ( l = i + 2 ; l <= n ; l++ ) {
					//printf ( "%d %d %d %d\n" , i , l , tim , pos );
					if ( max ( tim + abs ( pos - a[l] ) , t[i] ) + abs ( a[l] - a[i+1] ) <= t[i+1] && go[i+1][l-1] == 1 ) {
						dp[l][2] = min ( dp[l][2] , t[l-1] );
					}
				}
			}
		}
		//printf ( "%d %d\n" , dp[i][1] , dp[i][2] );
	}
	//printf ( "%d %d\n" , dp[n][1] , dp[n][2] );
	if ( dp[n][1] != 2147483647777ll || dp[n][2] != 2147483647777ll ) {
		printf ( "YES\n" );
	}
	else {
		printf ( "NO\n" );
	}
}
int main () {
	work ();
	return 0;
}