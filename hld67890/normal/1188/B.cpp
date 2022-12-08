#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

//long long
long long n , p , k;
map < long long , long long > m;
long long ans;
void work () {
	long long i , a;
	scanf ( "%lld%lld%lld" , &n , &p , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a );
		a = ( ((a*a)%p)*((a*a)%p) - (a*k)%p + p ) % p;
		ans += m[a];
		m[a]++;
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}