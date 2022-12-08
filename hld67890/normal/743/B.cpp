#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , k;
void work () {
	long long i;
	scanf ( "%I64d%I64d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) if ( k & (1ll<<(i-1)) ) {
		printf ( "%I64d\n" , i );
		break;
	}
}
int main () {
	work ();
	return 0;
}