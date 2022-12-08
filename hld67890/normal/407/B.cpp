#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
const int maxn = 1200;
int n;
int a[maxn] , dp[maxn];
int f[maxn];
int ans;
void work () {
	int i , j , tmp;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		j = i;
		tmp = 0;
		while ( a[j] != j ) {
			f[j] = 1;
			j = a[j];
			tmp++;
		}
		f[j] = 0; tmp++;
		for ( j++ ; j <= i ; j++ ) {
			if ( !f[j] ) {
				tmp = (tmp + dp[j]) % mod;
			}
			else {
				f[j] = 0;
				tmp = (tmp + 1) % mod;
			}
		}
		tmp++;
		dp[i] = tmp % mod;
		//printf ( "%d\n" , dp[i] );
	}
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) ans = (ans + dp[i]) % mod;
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}