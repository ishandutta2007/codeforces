#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int ans;
void work () {
	int i , j , tmp , last;
	scanf ( "%d%d" , &n , &k );
	tmp = n - k - 1;
	ans = (tmp / k) * 2 + 2;
	if ( tmp % k >= 2 ) ans += 2;
	else ans += (tmp%k);
	last = 1;
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= tmp % k ; i++ ) {
		printf ( "%d %d\n" , 1 , ++last );
		for ( j = 2 ; j <= tmp / k + 2 ; j++ ) {
			printf ( "%d %d\n" , last , last + 1 );
			last++;
		}
	}
	for ( i = 1 ; i <= k-(tmp % k) ; i++ ) {
		printf ( "%d %d\n" , 1 , ++last );
		for ( j = 2 ; j <= tmp / k + 1 ; j++ ) {
			printf ( "%d %d\n" , last , last + 1 );
			last++;
		}
	}
}
int main () {
	work ();
	return 0;
}