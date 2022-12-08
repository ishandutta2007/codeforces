#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , m , a , b;
void work () {
	long long x;
	scanf ( "%I64d%I64d%I64d%I64d" , &n , &m , &a , &b );
	if ( n % m == 0 ) {
		printf ( "0\n" );
	}
	else {
		x = n / m;
		printf ( "%I64d\n" , min ( (n-x*m) * b , ((x+1)*m-n) * a ) );
	}
}
int main () {
	work ();
	return 0;
}