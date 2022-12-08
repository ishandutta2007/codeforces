#include <stdio.h>
#include <algorithm>

using namespace std;

long long n , m;
long long a[220000];
long long ans;
void work () {
	long long i , j;
	scanf ( "%lld%lld" , &n , &m );
	//n = 200000; m = 1000;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		//a[i] = i;
	}
	sort ( a + 1 , a + 1 + n );
	ans = 1;
	if ( n > m ) {
		printf ( "0\n" );
		return ;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = i + 1 ; j <= n ; j++ ) {
			ans = ans * abs(a[j]-a[i]) % m;
		}
	}
	printf ( "%lld\n" , ans % m );
}
int main () {
	work ();
	return 0;
}