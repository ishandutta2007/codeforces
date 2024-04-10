#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , k , k1 , k2;
void work () {
	scanf ( "%I64d%I64d" , &n , &k );
	if ( k % 2 == 0 ) {
		k1 = k / 2 - 1;
		k2 = k / 2 + 1;
	}
	else {
		k1 = k / 2;
		k2 = k / 2 + 1;
	}
	printf ( "%I64d\n" , max ( 0ll , min ( k1 , n - k2 + 1 ) ) );
}
int main () {
	work ();
	return 0;
}