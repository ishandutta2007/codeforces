#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 5100000;
const long long mod = 1000000007;
long long l , r , t;
long long p[NN] , prime[NN] , tot;
long long minn[NN];
long long f[NN];
long long ans;
void predo () {
	long long i , j , N;
	N = 5000000;
	for ( i = 2 ; i <= N ; i++ ) {
		if ( !p[i] ) {
			prime[++tot] = i;
			minn[i] = i;
		}
		for ( j = 1 ; j <= tot ; j++ ) {
			if ( i * prime[j] > N ) break;
			p[i*prime[j]] = 1;
			minn[i*prime[j]] = prime[j];
			if ( i % prime[j] == 0 ) break;
		}
	}
}
void work () {
	long long i , j , tmp;
	scanf ( "%I64d%I64d%I64d" , &t , &l , &r );
	for ( i = 1 ; i <= r ; i++ ) f[i] = 99999999999999999ll;
	f[1] = 0;
	for ( i = 1 ; i <= r ; i++ ) {
		j = i;
		while ( j != 1 ) {
			f[i] = min ( f[i] , f[i/minn[j]] + i*(minn[j]-1) / 2 );
			j = j / minn[j];
		}
	}
	/*for ( i = 1 ; i <= r ; i++ ) {
		for ( j = 1 ; j <= i ; j ++ ) {
			if ( i % j != 0 ) continue;
			if ( f[i] == (i/j)*f[j] + (i/j)*(i/j-1)/2 ) {
				printf ( "%I64d %I64d\n" , i , j );
				break;
			}
		}
	}*/
	//for ( i = 4990000 ; i <= r ; i++ ) printf ( "%I64d\n" , f[i] );
	tmp = 1;
	for ( i = l ; i <= r ; i++ ) {
		ans = (ans + tmp*(f[i]%mod)) % mod;
		tmp = (tmp * t) % mod;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	predo ();
	work ();
	return 0;
}