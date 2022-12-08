#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 100010;
const long long mod = 998244353;
long long n;
long long dp[10][204][2];
long long sum[10][204][2];
long long a[maxn];
long long ans;
void work () {
	long long i , j;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	if ( a[1] == -1 ) for ( i = 1 ; i <= 200 ; i++ ) dp[1][i][0] = 1;
	else dp[1][a[1]][0] = 1;
	for ( i = 1 ; i <= 200 ; i++ ) {
		sum[1][i][0] = sum[1][i-1][0] + dp[1][i][0];
		sum[1][i][1] = sum[1][i-1][1] + dp[1][i][1];
	}
	for ( i = 2 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= 200 ; j++ ) {
			dp[i%2][j][0] = ( sum[(i-1)%2][j-1][0] + sum[(i-1)%2][j-1][1] ) % mod;
			dp[i%2][j][1] = ( sum[(i-1)%2][200][1] - sum[(i-1)%2][j-1][1] + dp[(i-1)%2][j][0] + mod ) % mod;
		}
		for ( j = 1 ; j <= 200 ; j++ ) {
			if ( a[i] != -1 ) {
				if ( a[i] != j ) dp[i%2][j][0] = dp[i%2][j][1] = 0;
			}
			//printf ( "%I64d %I64d %I64d %I64d\n" , i , j , dp[i%2][j][0] , dp[i%2][j][1] );
			sum[i%2][j][0] = ( sum[i%2][j-1][0] + dp[i%2][j][0] ) % mod;
			sum[i%2][j][1] = ( sum[i%2][j-1][1] + dp[i%2][j][1] ) % mod;
		}
	}
	printf ( "%I64d\n" , sum[n%2][200][1] );
}
int main () {
	work ();
	return 0;
}