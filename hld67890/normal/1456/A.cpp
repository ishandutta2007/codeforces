#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , p , k;
char a[120000];
long long suf[120000];
long long x , y;
long long ans;
void work () {
	long long i;
	scanf ( "%lld%lld%lld" , &n , &p , &k );
	scanf ( "%s" , a + 1 );
	scanf ( "%lld%lld" , &x , &y );
	for ( i = n ; i >= 1 ; i-- ) {
		if ( a[i] == '1' ) {
			suf[i] = i+k>n?0:suf[i+k];
		}
		else {
			suf[i] = (i+k>n?0:suf[i+k]) + x;
		}
	}
	ans = 2147483647777777ll;
	for ( i = p ; i <= n ; i++ ) {
		ans = min ( ans , suf[i] + (i-p) * y );
	}
	printf ( "%lld\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}