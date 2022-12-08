#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 53;
const long long mod = 1000000007;
long long n;
long long d[maxn];
long long dp[3][maxn][maxn][maxn][maxn];
long long now;
void check ( long long &x ) {
	if ( x >= mod ) x -= mod;
}
void work () {
	long long i , j , k , l , o;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &d[i] );
	if ( d[1] == 2 ) {
		if ( d[2] == 2 ) dp[2%2][1][0][1][0] = 1;
		else dp[2%2][1][0][0][1] = 1;
	}
	else {
		if ( d[2] == 2 ) dp[2%2][0][1][1][0] = 1;
		else dp[2%2][0][1][0][1] = 1;
	}
	for ( i = 2 ; i < n ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) for ( k = 0 ; k <= n ; k++ ) {
			if ( j + k * 2 > n ) break;
			for ( l = 0 ; l <= n ; l++ ) for ( o = 0 ; o <= n ; o++ ) {
				if ( l + o * 2 > n ) break;
				dp[(i+1)%2][j][k][l][o] = 0;
			}
		}
		if ( d[i+1] == 2 ) {
			for ( j = 0 ; j <= i ; j++ ) for ( k = 0 ; k <= i ; k++ ) {
				if ( j + k * 2 > n ) break;
				for ( l = 0 ; l <= i ; l++ ) for ( o = 0 ; o <= i ; o++ ) {
					if ( l + o * 2 > n ) break;
					now = dp[i%2][j][k][l][o];
					if ( j >= 1 ) {
						dp[(i+1)%2][j-1][k][l+1][o] += (now * j) % mod;
						check ( dp[(i+1)%2][j-1][k][l+1][o] );
					}
					if ( j >= 1 && l >= 1 ) {
						dp[(i+1)%2][j-1][k][l-1][o] += (now * ((j*l)%mod)) % mod;
						check ( dp[(i+1)%2][j-1][k][l-1][o] );
					}
					if ( j >= 1 && o >= 1 ) {
						dp[(i+1)%2][j-1][k][l+1][o-1] += (now * ((j*o)%mod)) % mod;
						check ( dp[(i+1)%2][j-1][k][l+1][o-1] );
					}
					if ( k >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l+1][o] += (now * k) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l+1][o] );
					}
					if ( k >= 1 && l >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l-1][o] += (now * ((k*l)%mod)) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l-1][o] );
					}
					if ( k >= 1 && o >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l+1][o-1] += (now * ((k*o)%mod)) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l+1][o-1] );
					}
				}
			}
		}	
		else {		
			for ( j = 0 ; j <= i ; j++ ) for ( k = 0 ; k <= i ; k++ ) {
				if ( j + k * 2 > n ) break;
				for ( l = 0 ; l <= i ; l++ ) for ( o = 0 ; o <= i ; o++ ) {
					if ( l + o * 2 > n ) break;
					now = dp[i%2][j][k][l][o];
					if ( j >= 1 ) {
						dp[(i+1)%2][j-1][k][l][o+1] += (now * j) % mod;
						check ( dp[(i+1)%2][j-1][k][l][o+1] );
					}
					if ( j >= 1 && l >= 1 ) {
						dp[(i+1)%2][j-1][k][l][o] += (now * ((j*l)%mod)) % mod;
						check ( dp[(i+1)%2][j-1][k][l][o] );
					}
					//if ( i == 2 && j == 1 && k == 0 && l == 0 && o == 1 ) printf ( " %I64d %I64d %I64d %I64d %I64d %I64d\n" , (i+1)%2,j-1,k,l+2,o-1 , j*o );
					if ( j >= 1 && o >= 1 ) {
						dp[(i+1)%2][j-1][k][l+2][o-1] += (now * ((j*o)%mod)) % mod;
						check ( dp[(i+1)%2][j-1][k][l+2][o-1] );
						//if ( i == 2 && j == 1 )printf ( " %I64d %I64d %I64d %I64d %I64d %I64d\n" , (i+1)%2,j-1,k,l+2,o-1 , dp[3%2][0][0][2][0] );
					}
					if ( j >= 1 && l >= 2 ) {
						dp[(i+1)%2][j-1][k][l-2][o] += (now * ((j*((l*(l-1)/2)%mod))%mod) ) % mod;
						check ( dp[(i+1)%2][j-1][k][l-2][o] );
					}
					if ( j >= 1 && l >= 1 && o >= 1 ) {
						dp[(i+1)%2][j-1][k][l][o-1] += (now * ((j*((l*o)%mod))%mod) ) % mod;
						check ( dp[(i+1)%2][j-1][k][l][o-1] );
					}
					if ( j >= 1 && o >= 2 ) {
						dp[(i+1)%2][j-1][k][l+2][o-2] += (now * ((j*((o*(o-1)/2)%mod))%mod) ) % mod;
						check ( dp[(i+1)%2][j-1][k][l+2][o-2] );
					}
					
					if ( k >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l][o+1] += (now * k) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l][o+1] );
					}
					if ( k >= 1 && l >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l][o] += (now * ((k*l)%mod)) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l][o] );
					}
					if ( k >= 1 && o >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l+2][o-1] += (now * ((k*o)%mod)) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l+2][o-1] );
					}
					if ( k >= 1 && l >= 2 ) {
						dp[(i+1)%2][j+1][k-1][l-2][o] += (now * ((k*((l*(l-1)/2)%mod))%mod) ) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l-2][o] );
					}
					if ( k >= 1 && l >= 1 && o >= 1 ) {
						dp[(i+1)%2][j+1][k-1][l][o-1] += (now * ((k*((l*o)%mod))%mod) ) % mod;
						check ( dp[(i+1)%2][j+1][k-1][l][o-1] );
					}
					if ( k >= 1 && o >= 2 ) {
						dp[(i+1)%2][j+1][k-1][l+2][o-2] += (now * ((k*((o*(o-1)/2)%mod))%mod) ) % mod;	
						check ( dp[(i+1)%2][j+1][k-1][l+2][o-2] );
					}
				}
				//printf ( "%I64d %I64d %I64d %I64d %I64d %I64d\n" , i , j , k , l , o , dp[i%2][j][k][l][o] );
			}
		//printf ( "###%I64d\n" , dp[3%2][0][0][2][0] );
		}
		for ( j = 0 ; j <= n ; j++ ) for ( k = 0 ; k <= n ; k++ ) {
			if ( j + k * 2 > n ) continue;
			if ( j == 0 && k == 0 ) continue;
			dp[(i+1)%2][j][k][0][0] += dp[(i+1)%2][0][0][j][k];
		}
	}
	printf ( "%I64d\n" , dp[n%2][0][0][0][0] );
}
int main () {
	work ();
	return 0;
}