#include <stdio.h>
#include <algorithm>

using namespace std;

long long a , b , c , d;
long long ans;
void work () {
	long long i;
	scanf ( "%lld%lld%lld%lld" , &a , &b , &c , &d );
	if ( b >= a ) {
		printf ( "%lld\n" , b );
		return ;
	}
	a -= b;
	ans = b;
	if ( c <= d ) {
		printf ( "-1\n" );
		return ;
	}
	d = c - d;
	i = (a-1) / d + 1;
	ans += c * i;
	printf ( "%lld\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}