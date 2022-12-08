#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

//long long
const long long maxn = 1200000;
const long long mod = 1000000007;
long long n , k;
long long phi ( long long x ) {
	long long i , ret = x;
	for ( i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			ret = ret / i * (i-1);
			while ( x % i == 0 ) x = x / i;
			//printf ( "%d %d %d\n" , i , mu[i] , (x/i) );
			//printf ( "%d %d %d\n" , x/i , mu[x/i] , (i) );
		}
	}
	if ( x > 1 ) ret = ret / x * (x-1);
	return ret;
}
void work () {
	scanf ( "%I64d%I64d" , &n , &k );
	k = (k+1)/2;
	while ( k-- ) {
		n = phi ( n );
		if ( n == 1 ) break;
	}
	printf ( "%I64d\n" , n % mod );
}
int main () {
	work ();
	return 0;
}