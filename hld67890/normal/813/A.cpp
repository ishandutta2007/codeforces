#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int s;
int ans;
void work () {
	int i , x , l , r;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &x );
		s += x;
	}
	scanf ( "%d" , &m );
	ans = 1000000;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &l , &r );
		if ( r >= s ) {
			ans = min ( ans , max ( l , s ) );
		}
	}
	if ( ans == 1000000 ) printf ( "-1\n" );
	else printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}