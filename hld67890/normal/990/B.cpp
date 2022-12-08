#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
int n , k; 
int a[maxn] , left;
void work () {
	int i , x;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	left = n;
	x = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		if ( a[i] > a[i-1] && a[i] <= a[i-1] + k ) {
			left -= x;
			x = 1;
		}
		else {
			if ( a[i] == a[i-1] ) x++;
			else x = 1;
		}
		//printf ( "%d %d %d\n" , i , left , x );
	}
	printf ( "%d\n" , left );
}
int main () {
	work ();
	return 0;
}