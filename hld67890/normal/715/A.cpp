#include <stdio.h>
#include <algorithm>
#include <math.h>
#define $ if (0)

using namespace std;

//long long
long long n;
long long abs ( long long x ) {
	if ( x < 0 ) return -x;
	return x;
}
void work () {
	long long k , s;
	scanf ( "%I64d" , &n );
	k = 1; s = 2;
	while ( k <= n ) {
		printf ( "%I64d\n" , (k+1)*(k+1)*k-s/k );
		s = (k+1)*k;
		k++;
	}
}
int main () {
	work ();
	return 0;
}