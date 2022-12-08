#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
long long n;
long long a[4][maxn] , s[maxn];
long long dp[4][maxn];
void work () {
	long long i , j;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= 3 ; i++ ) for ( j = 1 ; j <= n ; j++ ) scanf ( "%I64d" , &a[i][j] );
	for ( i = 1 ; i <= n ; i++ ) s[i] = a[1][i] + a[2][i] + a[3][i];
	for ( i = 1 ; i <= 3 ; i++ ) for ( j = 1 ; j <= n ; j++ ) dp[i][j] = -9999999999999999ll;
	dp[1][1] = a[1][1];
	for ( i = 1 ; i < n ; i++ ) {
		dp[1][i+1] = max ( dp[1][i+1] , max ( dp[1][i] , a[1][i] + max ( a[2][i] + dp[3][i] , dp[2][i] ) ) + a[1][i+1] );
		dp[2][i+1] = max ( dp[2][i+1] , max ( dp[2][i] , max ( dp[1][i] , dp[3][i] ) + a[2][i] ) + a[2][i+1] );
		dp[3][i+1] = max ( dp[3][i+1] , max ( dp[3][i] , a[3][i] + max ( a[2][i] + dp[1][i] , dp[2][i] ) ) + a[3][i+1] );
		dp[1][i+2] = max ( dp[1][i+2] , s[i] + s[i+1] - a[3][i] + dp[3][i] + a[1][i+2] );
		dp[3][i+2] = max ( dp[3][i+2] , s[i] + s[i+1] - a[1][i] + dp[1][i] + a[3][i+2] );
		if ( i == n - 1 ) {
			dp[3][n] = max ( dp[3][n] , dp[1][i] + s[i] + s[i+1] - a[1][i] );
		}
	}
	//for ( i = 1 ; i <= 3 ; i++ ,printf("\n")) for ( j = 1 ; j <= n ; j++ ) printf ( "%I64d " , dp[i][j] );
	printf ( "%I64d\n" , max ( dp[3][n] , a[3][n] + max ( dp[2][n] , dp[1][n] + a[2][n] ) ) );
}
int main () {
	work ();
	return 0;
}