#include <stdio.h>
#include <algorithm>

using namespace std;

int s , v1 , v2 , t1 , t2;
void work () {
	scanf ( "%d%d%d%d%d" , &s , &v1 , &v2 , &t1 , &t2 );
	if ( t1 * 2 + s * v1 == t2 * 2 + s * v2 ) {
		printf ( "Friendship\n" );
	}
	if ( t1 * 2 + s * v1 < t2 * 2 + s * v2 ) {
		printf ( "First\n" );
	}
	if ( t1 * 2 + s * v1 > t2 * 2 + s * v2 ) {
		printf ( "Second\n" );
	}
}
int main () {
	work ();
	return 0;
}