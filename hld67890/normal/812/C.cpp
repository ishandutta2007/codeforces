#include <stdio.h>
#include <algorithm>

using namespace std;

const long long NN = 120000;
long long n , s;
long long a[NN] , b[NN];
long long ans;
long long check ( long long x ) {
	long long i;
	for ( i = 1 ; i <= n ; i++ ) {
		b[i] = a[i] + i * x;
	}
	//printf ( "%I64d\n" , x );
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%I64d " , b[i] );
	//printf ( "\n" );
	sort ( b + 1 , b + 1 + n );
	ans = 0;
	for ( i = 1 ; i <= x ; i++ ) {
		ans += b[i];
	}
	if ( ans <= s ) return 1;
	return 0;
}
void work () {
	long long i , l , r , mid;
	scanf ( "%I64d%I64d" , &n , &s );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	l = 0; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( mid ) == 1 ) l = mid;
		else r = mid;
	}
	if ( check ( r ) == 1 ) printf ( "%I64d %I64d\n" , r , ans );
	else {
		check ( l );
		printf ( "%I64d %I64d\n" , l , ans );
	}
}
int main () {
	work ();
	return 0;
}