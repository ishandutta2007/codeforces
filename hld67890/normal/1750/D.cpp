#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
long long n , m;
long long a[210000];
long long fac[2100] , cnt;
long long ans;
void getfac () {
	long long i , t;
	cnt = 0;
	t = a[1];
	for ( i = 2 ; i * i <= a[1] ; i++ ) {
		if ( t % i == 0 ) {
			fac[++cnt] = i;
			while ( t % i == 0 ) t = t / i;
		}
	}
	if ( t != 1 ) {
		fac[++cnt] = t;
	}
}
void work () {
	long long i , j , k , t , mask;
	long long now , flag , val;
	scanf ( "%lld%lld" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
	}
	for ( i = 2 ; i <= n ; i++ ) {
		if ( a[i-1] % a[i] != 0 ) {
			printf ( "0\n" );
			return ;
		}
	}
	getfac ();
	ans = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		t = a[i-1] / a[i];
		mask = 0;
		for ( j = 1 ; j <= cnt ; j++ ) {
			//printf ( "%lld\n" , fac[j] );
			if ( t % fac[j] == 0 ) mask |= (1<<(j-1));
		}
		//printf ( "%lld %lld\n" , mask , now );
		now = m / a[i];
		for ( k = mask ; k != 0 ; k = (k-1) & mask ) {
			if ( __builtin_popcount ( k ) % 2 == 0 ) flag = 1;
			else flag = -1;
			val = 1;
			for ( j = 1 ; j <= cnt ; j++ ) {
				if ( k & (1<<(j-1)) ) val = val * fac[j];
			}
			now += flag * m / (a[i] * val);
		}
		now %= mod;
		if ( now < 0 ) now += mod;
		ans = ans * now % mod;
	}
	printf ( "%lld\n" , ans % mod );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) {
		work ();
	}
	return 0;
}