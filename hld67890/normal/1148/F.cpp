#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 420000;
long long n;
long long val[maxn] , mask[maxn];
long long s , t;
long long ans;
long long sgn ( long long x ) {
	if ( x > 0 ) return 1;
	if ( x == 0 ) return 0;
	if ( x < 0 ) return -1;
}
void work () {
	long long i , j;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &val[i] , &mask[i] );
	}
	s = 0;
	for ( j = 1 ; j <= n ; j++ ) {
		s += val[j];
	}
	for ( i = 0 ; i < 62 ; i++ ) {
		t = 0;
		for ( j = 1 ; j <= n ; j++ ) {
			if ( mask[j] < (1ll<<(i+1)) && mask[j] >= (1ll<<i) ) {
				t += val[j];
			}
		}
		if ( sgn ( t ) == sgn ( s ) ) {
			for ( j = 1 ; j <= n ; j++ ) {
				if ( mask[j] & (1ll<<i) ) {
					val[j] *= -1;
				}
			}
			ans |= (1ll<<i);
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}