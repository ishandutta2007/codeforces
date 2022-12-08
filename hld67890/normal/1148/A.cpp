#include <stdio.h>
#include <algorithm>

using namespace std;

long long a , b , c , ans , t;
void work () {
	scanf ( "%I64d%I64d%I64d" , &a , &b , &c );
	ans = c * 2;
	t = min ( a , b );
	ans += min ( a , b ) * 2;
	a -= t;
	b -= t;
	if ( a || b ) ans++;
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}