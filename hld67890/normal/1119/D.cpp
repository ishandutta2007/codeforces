#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
long long n , q;
long long a[maxn] , d[maxn] , s[maxn];
long long find ( long long x ) {
	long long l , r , mid;
	l = 1; r = n - 1;
	if ( d[1] > x ) return 0;
	if ( d[r] <= x ) return r;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( d[mid] <= x ) l = mid;
		else r = mid;
	}
	return l;
}
void work () {
	long long i , l , r , t;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
	}
	sort ( a + 1 , a + 1 + n );
	for ( i = 1 ; i < n ; i++ ) {
		d[i] = a[i+1] - a[i];
	}
	sort ( d + 1 , d + n );
	for ( i = 1 ; i < n ; i++ ) {
		s[i] = s[i-1] + d[i];
	}
	scanf ( "%lld" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%lld%lld" , &l , &r );
		l = r - l + 1;
		t = find ( l );
		printf ( "%lld%c" , s[t] + (n-t) * l , i==q?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}