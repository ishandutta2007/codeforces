#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
long long n;
char z[220000];
long long s0 , s1;
long long now , cnt;
long long ans;
void work () {
	long long i;
	scanf ( "%lld" , &n );
	scanf ( "%s" , z + 1 );
	s0 = s1 = 0;
	now = -1; cnt = 0;
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == '0' ) {
			s0++;
		}
		else {
			s1++;
		}
		if ( now != z[i] ) {
			cnt = 1;
			ans = max ( ans , 1ll );
			now = z[i];
		}
		else {
			cnt++;
			ans = max ( ans , cnt * cnt );
		}
	}
	ans = max ( ans , s0 * s1 );
	printf ( "%lld\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}