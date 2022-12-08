#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long mod = 998244353;
long long n , m , k;
long long dp[2100][2100];
void work () {
	long long i , j;
	scanf ( "%I64d%I64d%I64d" , &n , &m , &k );
	dp[1][0] = m;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= k ; j++ ) {
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
			dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (m-1)) % mod;
		}
	}
	printf ( "%I64d\n" , dp[n][k] );
}
int main () {
	work ();
	return 0;
}