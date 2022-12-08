#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
char z[120000];
void work () {
	int i , w1 , e1 , w2 , e2;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	w1 = e1 = w2 = e2 = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i % 2 == 1 ) {
			if ( z[i] != 'r' ) w1++;
		}
		else {
			if ( z[i] != 'b' ) e1++;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i % 2 == 1 ) {
			if ( z[i] != 'b' ) w2++;
		}
		else {
			if ( z[i] != 'r' ) e2++;
		}
	}
	printf ( "%d\n" , min ( max ( w1 , e1 ) , max ( w2 , e2 ) ) );
}
int main () {
	work ();
	return 0;
}