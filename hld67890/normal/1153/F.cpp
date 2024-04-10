#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long mod = 998244353;
const long long maxn = 2100;
long long n , L , k;
long long prob[maxn*2];
long long pow2[maxn*2] , rev2[maxn*2];
long long C[maxn*2][maxn*2] , fact[maxn*2];
long long g[maxn*2];
long long tmp , ans;
long long get ( long long x ) {
	return g[x];
}
long long poww ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		//printf ( "%lld %lld\n" , x , s );
		if ( x % 2 ) s = (s*f) % mod;
		f = (f*f) % mod; x = x / 2;
	}
	return s;
}
long long inv ( long long x ) {
	return poww ( x , mod - 2 );
}
void work () {
	long long i , j , l , r;
	scanf ( "%lld%lld%lld" , &n , &k , &L );
	pow2[0] = 1; rev2[0] = 1;
	fact[0] = 1;
	for ( i = 1 ; i <= n * 2 + 2 ; i++ ) {
		pow2[i] = (pow2[i-1]*2) % mod;
		rev2[i] = inv ( pow2[i] );
		fact[i] = (fact[i-1]*i)%mod;
	}
	C[0][0] = 1;
	for ( i = 1 ; i <= n * 2 + 2 ; i++ ) {
		C[i][0] = 1;
		for ( j = 1 ; j <= i ; j++ ) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	g[0] = 1;
	for ( i = 2 ; i <= n * 2 + 2 ; i += 2 ) {
		g[i] = (g[i-2] * (i-1)) % mod;
	}
	for ( i = 1 ; i <= n * 2 ; i++ ) {
		prob[i] = 0;
		for ( j = k ; j <= n * 2 ; j++ ) {
			l = i; r = 2 * n - i;
			if ( l < j || r < j || (l - j) % 2 != 0 ) continue;
			tmp = 0;
			tmp = (C[l][j] * C[r][j]) % mod;
			tmp = (tmp * fact[j]) % mod;
			tmp = ( tmp * get ( l - j ) ) % mod;
			tmp = ( tmp * get ( r - j ) ) % mod;
			//printf ( "%lld %lld\n" , j , inv(1) );
			prob[i] = (prob[i] + tmp) % mod;
			ans = (ans + tmp) % mod;
		}
	}
	ans = (ans * inv(n*2+1)) % mod;
	ans = ( ans * inv(get(n*2))) % mod;
	ans = (ans * L) % mod;
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}