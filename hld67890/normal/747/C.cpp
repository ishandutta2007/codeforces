#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxq = 120000;
const int maxn = 120;
int n , q;
int t[maxq] , k[maxq] , d[maxq];
int busy[maxn];
void work () {
	int i , j , sum , ans;
	scanf ( "%d%d" , &n , &q );
	for ( i = 1 ; i <= q ; i++ ) scanf ( "%d%d%d" , &t[i] , &k[i] , &d[i] );
	for ( i = 1 ; i <= q ; i++ ) {
		sum = 0; ans = 0;
		for ( j = 1 ; j <= n ; j++ ) if ( busy[j] <= t[i] ) sum++;
		if ( sum >= k[i] ) {
			for ( j = 1; j <= n ; j++ ) if ( busy[j] <= t[i] && k[i] ) {
				busy[j] = t[i] + d[i];
				ans += j;
				k[i]--;
			}
			printf ( "%d\n" , ans );
		}
		else {
			printf ( "-1\n" );
		}
	}
}
int main () {
	work ();
	return 0;
}