#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
long long n , k;
long long a[1200];
int dp[1200][1200];
int s[1200] , now[1200];
long long tot[120000];
long long ans;
long long solve ( long long x ) {
	int i , j , ret;
	for ( i = 0 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= k ; j++ ) {
			dp[i][j] = 0;
		}
		s[i] = now[i] = 0;
	}
	dp[0][0] = 1;
	s[0] = 1; now[0] = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 0 ; j < k && j < i ; j++ ) {
			while ( now[j] < i - 1 && a[i] - a[now[j]+1] >= x ) {
				now[j]++;
				s[j] = (s[j] + dp[now[j]][j]);
				if ( s[j] > mod ) s[j] -= mod;
			}
			dp[i][j+1] = s[j];
		}
	}
	ret = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		ret = (ret + dp[i][k]) % mod;
	}
	return ret;
}
void work () {
	long long i;
	scanf ( "%lld%lld" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		//a[i] = 100000 / i;
	}
	sort ( a + 1 , a + n + 1 );
	for ( i = 1 ; i <= 100000 / (k-1) + 5 ; i++ ) {
		tot[i] = solve ( i );
	}
	for ( i = 1 ; i <= 100000 / (k-1) + 5 ; i++ ) {
		//if ( tot[i] - tot[i+1] != 0 ) printf ( "%lld %lld\n" , i , tot[i] );
		ans = (ans + (tot[i]-tot[i+1]+mod)* i ) % mod;
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}