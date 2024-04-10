#include <stdio.h>
#include <algorithm>

using namespace std;

int a , b , n;
void work () {
	scanf ( "%d%d%d" , &a , &b , &n );
	if ( n % 3 == 0 ) printf ( "%d\n" , a );
	else {
		if ( n % 3 == 1 ) printf ( "%d\n" , b );
		else printf ( "%d\n" , a ^ b );
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}