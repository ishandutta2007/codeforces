#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 5100;
const long long mod = 998244353;
const long long base = 29;
int n;
char s[NN];
int isp[NN][NN];
int dp[NN][NN];
long long pre[NN] , pow[NN];
int ans[NN];
long long get ( int l , int r ) {
	return (pre[r]-((pre[l-1]*pow[r-l+1])%mod)+mod)%mod;
}
void work () {
	int i , j , k , f;
	scanf ( "%s" , s + 1 );
	n = strlen ( s + 1 );
	pow[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		pre[i] = ( pre[i-1] * base + (s[i]-'a') ) % mod;
		pow[i] = (pow[i-1] * base) % mod;
	}
	//printf ( "%I64d %I64d %I64d\n" , pre[1] , pre[2] , pre[3] );
	for ( i = 1 ; i <= n ; i++ ) {
		f = 1;
		for ( j = i , k = i ; j >= 1 && k <= n ; j-- , k++ ) {
			if ( s[j] != s[k] ) f = 0;
			isp[j][k] = f;
		}
		f = 1;
		for ( j = i , k = i + 1 ; j >= 1 && k <= n ; j-- , k++ ) {
			if ( s[j] != s[k] ) f = 0;
			isp[j][k] = f;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n - i + 1 ; j++ ) {
			k = j + i - 1;
			if ( j == k ) {
				dp[j][k] = 1;
			}
			else {
				if ( get ( j , j + (k-j+1)/2 - 1 ) == get ( k - (k-j+1)/2 + 1 , k ) ) {
					if ( isp[j][k] == 0 ) dp[j][k] = 0;
					else {
						dp[j][k] = min ( dp[j][j+(k-j+1)/2-1] , dp[k-(k-j+1)/2+1][k] ) + 1;
					}
				}
				else {
					dp[j][k] = isp[j][k];
				}
			}
			//printf ( "%d %d %d %I64d %I64d\n" , j , k , dp[j][k] , get(2,2) , get(3,3) );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = i ; j <= n + 1 ; j++ ) ans[dp[i][j]]++;
	for ( i = n ; i >= 1 ; i-- ) ans[i] += ans[i+1];
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , ans[i] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}