#include <iostream>
#include <stdio.h>

using namespace std;

int n;
long long a[120000];
long long pow ( long long x , long long y ) {
	long long s = 1 , t = x;
	while ( y ) {
		if ( y % 2 ) s = (s * t) % 1000000007;
		t = (t * t) % 1000000007;
		y >>= 1;
	}
	return s;
}
void work () {
	long long i , flag , s , tmp1 , tmp2;
	flag = 0;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		if ( a[i] % 2 == 0 ) flag = 1;
	}
	s = 2;
	for ( i = 1 ; i <= n ; i++ ) {
		s = pow ( s , a[i] );
	}
	s = s * 500000004;
	s = s % 1000000007;
	if ( flag == 1 ) {
		tmp1 = (s + 1) * 333333336;
		tmp2 = s;
	}
	else {
		tmp1 = (s - 1) * 333333336;
		tmp2 = s;
	}
	tmp1 %= 1000000007;
	tmp2 %= 1000000007;
	printf ( "%I64d/%I64d\n" , tmp1 , tmp2 );
}
int main () {
	work ();
	return 0;
}