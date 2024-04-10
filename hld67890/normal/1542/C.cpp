#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
long long n;
long long ans;
void work () {
	long long i , lcm;
	scanf ( "%lld" , &n );
	lcm = 1;
	ans = n;
	for ( i = 1 ; i <= 50 ; i++ ) {
		lcm = lcm / __gcd ( lcm , i ) * i;
		ans += n / lcm;
		ans %= mod;
		if ( lcm > n ) break;
	}
	printf ( "%lld\n" , ans % mod );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}