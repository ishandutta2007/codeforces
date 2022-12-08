#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int l , r , mid;
char z[120];
int ans;
void work () {
	int i , now , t;
	scanf ( "%d%d" , &n , &k );
	now = 1;
	for ( i = 1 ; i <= 10 ; i++ ) {
		do {
			t = rand () % n + 1;
		} while ( t == now );
		printf ( "? %d %d\n" , 1 , 1 );
		printf ( "%d\n%d\n" , now , t );
		fflush(stdout);
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'S' ) {
			printf ( "! 1\n" );
			fflush(stdout);
			return ;
		}
	}
	l = r = 0;
	while ( now * 2 <= n ) {
		printf ( "? %d %d\n" , now , now );
		for ( i = 1 ; i <= now ; i++ ) {
			printf ( "%d%c" , i , i==now?'\n':' ' );
		}
		for ( i = 1 ; i <= now ; i++ ) {
			printf ( "%d%c" , now + i , i==now?'\n':' ' );
		}
		fflush(stdout);
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'F' ) {
			l = now + 1;
			r = now * 2;
			break;
		}
		now = now * 2;
	}
	if ( l == 0 ) {
		l = now + 1;
		r = n;
	}
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d\n" , mid - l + 1 , mid - l + 1 );
		for ( i = 1 ; i <= mid - l + 1 ; i++ ) {
			printf ( "%d%c" , i , i==now?'\n':' ' );
		}
		for ( i = l ; i <= mid ; i++ ) {
			printf ( "%d%c" , i , i==now?'\n':' ' );
		}
		fflush(stdout);
		scanf ( "%s" , z + 1 );
		if ( z[1] == 'E' ) {
			l = mid;
		}
		else r = mid;
	}
	printf ( "? 1 1\n" );
	printf ( "1\n%d\n" , l );
	fflush(stdout);
	scanf ( "%s" , z + 1 );
	if ( z[1] == 'E' ) ans = r;
	else ans = l;
	printf ( "! %d\n" , ans );
	fflush(stdout);
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}