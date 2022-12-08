#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

long long n , k;
long long a[520000];
priority_queue < long long > q;
long long ans;
void work () {
	long long i , t;
	scanf ( "%lld%lld" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
	}
	sort ( a + 1 , a + 1 + n );
	for ( i = 1 ; i <= k + 1 ; i++ ) {
		q.push ( 0 );
	}
	for ( i = n ; i >= 1 ; i-- ) {
		t = q.top (); q.pop ();
		ans += t;
		t += a[i];
		q.push ( t );
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}