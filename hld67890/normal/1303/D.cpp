#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , m;
long long a[100200];
long long ans;
long long get ( long long x ) {
	long long ret = 0;
	while ( x != 1 ) {
		ret++;
		x = x / 2;
	}
	return ret;
}
void work () {
	long long i , j , k , s;
	scanf ( "%lld%lld" , &n , &m );
	n = -n;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%lld" , &a[i] );
		n += a[i];
	}
	if ( n < 0 ) {
		printf ( "-1\n" );
		return ;
	}
	sort ( a + 1 , a + 1 + m );
	j = 1; s = 0; ans = 0;
	for ( i = 0 ; i <= 62 ; i++ ) {
		while ( j <= m && a[j] <= (1ll<<i) ) {
			s += a[j++];
		}
		//printf ( "%lld %lld\n" , i , j );
		if ( n & (1ll<<i) ) {
			if ( s >= (1ll<<i) ) {
				s -= (1ll<<i);
			}
			else {
				k = get ( a[j++] );
				//printf ( "%lld\n" , k );
				ans += (k-i);
				i = k - 1;
			}
		}
	}
	printf ( "%lld\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}