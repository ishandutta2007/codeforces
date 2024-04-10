#include <stdio.h>
#include <algorithm>

using namespace std;

void work () {
	int x1 , y1 , x2 , y2 , x , y;
	scanf ( "%d%d%d%d" , &x1 , &y1 , &x2 , &y2 );
	scanf ( "%d%d" , &x , &y );
	if ( abs(x2-x1) % x != 0 ) {
		printf ( "NO\n" );
		return ;
	}
	y1 += ((x2-x1)/x) * y;
	if ( abs(y2-y1) % y != 0 ) {
		printf ( "NO\n" );
		return ;
	}
	if ( (abs(y2-y1) / y) % 2 == 1 ) {
		printf ( "NO\n" );
		return ;
	}
	printf ( "YES\n" );
}
int main () {
	work ();
	return 0;
}