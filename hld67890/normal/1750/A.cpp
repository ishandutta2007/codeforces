#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[12000];
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i =1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	if ( a[1] == 1 ) printf ("Yes\n" );
	else printf ( "No\n" );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) {
		work ();
	}
	return 0;
}