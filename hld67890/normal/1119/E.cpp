#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 310000;
long long n;
long long a[maxn];
long long ans , left;
void work () {
	long long i;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		if ( a[i] >= left * 2 ) {
			ans += left;
			a[i] -= left * 2;
			left = 0;
		}
		else {
			ans += a[i] / 2;
			left -= a[i] / 2;
			a[i] %= 2;
			left += a[i];
			a[i] = 0;
		}
		ans += a[i] / 3;
		a[i] %= 3;
		if ( a[i] == 2 ) {
			if ( left ) {
				left--;
				a[i] = 0;
				ans++;
			}
			else left += a[i];
		}
		if ( a[i] == 1 ) left++;
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}