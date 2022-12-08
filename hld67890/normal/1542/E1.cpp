#include <stdio.h>
#include <algorithm>

using namespace std;

const long long del = 140000;
long long n , mod;
long long f[3][340000] , s[340000];
long long cp[510][510] , C[510][510] , fac[510];
long long ans;
void work () {
	long long i , j , k , l , tmp;
	scanf ( "%lld%lld" , &n , &mod );
	C[0][0] = 1;
	fac[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		fac[i] = fac[i-1] * i % mod;
		C[i][0] = 1;
		for ( j = 1 ; j <= i ; j++ ) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	f[1][del] = 1;
	cp[1][0] = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		s[-(n*n/2) - n-1+del] = 0;
		for ( j = -(n*n/2) - n ; j <= n * n / 2 + n ; j++ ) {
			s[j+del] = (s[j-1+del] + f[(i-1)%2][j+del]) % mod;
		}
		for ( j = -(n*n/2) ; j <= n * n / 2 ; j++ ) {
			f[i%2][j+1+del] = (f[i%2][j+del] - (s[j+del]-s[j-i+del]) + (s[j+i+del]-s[j+del])) % mod;
			if ( f[i%2][j+1+del] < 0 ) f[i%2][j+1+del] += mod;
			//printf ( "##%lld %lld %lld\n" , i , j , f[i%2][j+1+del] );
		}
		tmp = 0;
		for ( j = n * n / 2 ; j >= 0 ; j-- ) {
			tmp = (tmp + f[i%2][j+del]) % mod;
			if ( j <= n ) cp[i][j] = tmp;
		}
	}
	ans = 0;
	for ( l = 0 ; l <= n - 2 ; l++ ) {
		for ( k = 1 ; k <= n - l - 1 ; k++ ) {
			ans = (ans + (n-l-k) * cp[n-l-1][k+1] % mod * C[n][l] % mod * fac[l]) % mod;
		}
	}
	printf ( "%lld\n" , ans % mod );
}
int main () {
	work ();
	return 0;
}