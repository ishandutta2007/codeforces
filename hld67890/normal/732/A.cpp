#include <stdio.h>
#include <algorithm>

using namespace std;

int k , r;
void work () {
	int i;
	scanf ( "%d%d" , &k , &r );
	for ( i = 1 ; i <= 9 ; i++ ) {
		if ( (k*i) % 10 == 0 || (k*i) % 10 == r ) break;
	}
	printf ( "%d\n" , i );
}
int main () {
	work ();
	return 0;
}