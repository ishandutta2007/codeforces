#include <iostream>
#include <stdio.h>

using namespace std;

long long m;
long long check ( long long x ) {
	long long t , sum = 0;
	for ( t = 2 ; t*t*t <= x ; t++ ) {
		sum += x / (t*t*t);
	}
	return sum;
}
void work () {
	unsigned long long l , r , mid , t;
	scanf ( "%I64d" , &m );
	l = 1; r = 9223372036854775807ll;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		t = check ( mid );
		if ( t >= m ) r = mid;
		if ( t < m ) l = mid;
	}
	if ( check ( l ) == m ) printf ( "%I64d\n" , l );
	else {
		if ( check ( r ) == m ) printf ( "%I64d\n" , r );
		else printf ( "-1\n" );
	}
}
int main () {
	work ();
	return 0;
}