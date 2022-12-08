#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
long long n , s;
long long ans;
long long check ( long long x ) {
	long long i , y , t;
	y = 0; t = x;
	while ( t ) {
		y += t % 10;
		t = t / 10;
	}
	if ( x - y >= s ) return 1;
	return -1;
}
void work () {
	scanf ( "%I64d%I64d" , &n , &s );
	if ( n < s ) {
		printf ( "0\n" );
		return ;
	}
	ans = n - s + 1;
	for ( long long i = s ; i <= s + 180 && i <= n ; i++ ) {
		if ( check ( i ) == -1 ) ans--;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}