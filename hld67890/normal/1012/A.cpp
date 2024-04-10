#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
long long n;
long long a[maxn*2];
long long ans;
void work () {
	long long i;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n * 2 ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	sort ( a + 1 , a + 2 * n + 1 );
	ans = (a[n]-a[1]) * (a[n*2]-a[n+1]);
	for ( i = 2 ; i <= n ; i++ ) {
		ans = min ( ans , (a[n*2]-a[1]) * (a[i+n-1]-a[i]) );
	}
	printf ( "%I64d" , ans );
}
int main () {
	work ();
	return 0;
}