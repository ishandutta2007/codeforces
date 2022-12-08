#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 320000;
long long n;
long long a[3][maxn];
long long s[3][maxn];
long long g[3][maxn];
long long dp[3][maxn];
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[1][i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[2][i] );
	}
	for ( i = n ; i >= 1 ; i-- ) {
		s[1][i] = s[1][i+1] + a[1][i];
		s[2][i] = s[2][i+1] + a[2][i];
	}
	for ( i = n ; i >= 1 ; i-- ) {
		g[1][i] = g[1][i+1] + s[1][i+1] + s[2][i+1] + a[2][i] * ((n-i)*2+1);
		g[2][i] = g[2][i+1] + s[1][i+1] + s[2][i+1] + a[1][i] * ((n-i)*2+1);
	}
	for ( i = n ; i >= 1 ; i-- ) {
		dp[1][i] = max ( g[1][i] , a[2][i] + dp[2][i+1] + 2 * s[2][i+1] + 2 * s[1][i+1] );
		dp[2][i] = max ( g[2][i] , a[1][i] + dp[1][i+1] + 2 * s[2][i+1] + 2 * s[1][i+1] );
		//printf ( "%I64d %I64d %I64d\n" , i , dp[1][i] , dp[2][i] );
	}
	printf ( "%I64d\n" , dp[1][1] );
}
int main () {
	work ();
	return 0;
}