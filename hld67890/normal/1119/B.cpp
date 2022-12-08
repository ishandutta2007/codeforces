#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 1200;
long long n , h;
long long a[maxn] , b[maxn];
long long check ( long long x ) {
	long long i , sum;
	for ( i = 1 ; i <= x ; i++ ) b[i] = a[i];
	sort ( b + 1 , b + x + 1 );
	sum = 0;
	for ( i = x ; i >= 1 ; i -= 2 ) {
		sum += b[i];
	}
	if ( sum <= h ) return 1;
	return 0;
}
void work () {
	long long i , l , r , mid;
	scanf ( "%lld%lld" , &n , &h );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%lld" , &a[i] );
	l = 1; r = n + 1;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) == 1 ) l = mid;
		else r = mid;
	}
	printf ( "%lld\n" , l );
}
int main () {
	work ();
	return 0;
}