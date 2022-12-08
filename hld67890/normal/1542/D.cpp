#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
long long n;
char z[1200];
long long x[1200];
long long dp[510] , tmp[510];
long long ans;
long long solve ( long long i ) {
	long long j , k , sum;
	for ( j = 0 ; j <= n ; j++ ) dp[j] = 0;
	dp[0] = 1;
	for ( j = 1 ; j < i ; j++ ) {
		if ( z[j] == '+' && x[j] <= x[i] ) {
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k] = dp[k];
			}
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k+1] = (tmp[k+1] + dp[k]) % mod;
			}
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = tmp[k];
			}
		}
		if ( z[j] == '+' && x[j] > x[i] ) {
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = (dp[k]*2) % mod;
			}
		}
		if ( z[j] == '-' ) {
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k] = dp[k];
			}
			tmp[0] = (tmp[0] + dp[0]) % mod;
			for ( k = 1 ; k <= n ; k++ ) {
				tmp[k-1] = (tmp[k-1] + dp[k]) % mod;
			}
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = tmp[k];
			}
		}
	}
	for ( j = i + 1 ; j <= n ; j++ ) {
		if ( z[j] == '+' && x[j] < x[i] ) {
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k] = dp[k];
			}
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k+1] = (tmp[k+1] + dp[k]) % mod;
			}
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = tmp[k];
			}
		}
		if ( z[j] == '+' && x[j] >= x[i] ) {
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = (dp[k]*2) % mod;
			}
		}
		if ( z[j] == '-' ) {
			for ( k = 0 ; k <= n ; k++ ) {
				tmp[k] = dp[k];
			}
			for ( k = 1 ; k <= n ; k++ ) {
				tmp[k-1] = (tmp[k-1] + dp[k]) % mod;
			}
			for ( k = 0 ; k <= n ; k++ ) {
				dp[k] = tmp[k];
			}
		}
	}
	sum = 0;
	for ( j = 0 ; j <= n ; j++ ) sum = (sum+dp[j]) % mod;
	return (x[i] * sum) % mod;
}
void work () {
	long long i;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + i );
		if ( z[i] == '+' ) {
			scanf ( "%lld" , &x[i] );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == '+' ) ans = (ans + solve ( i )) % mod;
	}
	printf ( "%lld\n" , ans % mod );
}
int main () {
	work ();
	return 0;
}