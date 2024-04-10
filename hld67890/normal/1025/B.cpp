#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 170000;
long long n;
long long a[maxn] , b[maxn];
long long ans;
long long gcd ( long long x , long long y ) {
	long long t;
	if ( x < y ) swap ( x , y );
	while ( y ) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d" , &a[i] , &b[i] );
		if ( i == 1 ) {
			ans = a[i] * b[i] / gcd(a[i],b[i]);
		}
		else {
			ans = gcd ( ans , a[i] * b[i] / gcd(a[i],b[i]) );
		}
	}
	if ( ans == 1 ) {
		printf ( "-1\n" );
		return ;
	}
	if ( gcd ( ans , a[1] ) == 1 ) ans = gcd ( ans , b[1] );
	else ans = gcd ( ans , a[1] );
	for ( i = 2 ; i <= 1000000 ; i++ ) {
		if ( ans % i == 0 ) {
			printf ( "%I64d\n" , i );
			return ;
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}