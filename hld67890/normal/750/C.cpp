#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int maxx , minn;
int f1 , f2;
void work () {
	int i , c , d , s;
	scanf ( "%d" , &n );
	s = 0;
	minn = 99999999; maxx = -99999999;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &c , &d );
		if ( d == 1 ) {
			f1 = 1;
			maxx = max ( maxx , 1900 - s );
		}
		if ( d == 2 ) {
			f2 = 1;
			minn = min ( minn , 1899 - s );
		}
		s += c;
	}
	//printf ( "%d %d\n" , minn , maxx );
	if ( f2 == 0 ) printf ( "Infinity\n" );
	else {
		if ( maxx <= minn ) printf ( "%d\n" , minn + s );
		else printf ( "Impossible\n" );
	}
}
int main () {
	work ();
	return 0;
}