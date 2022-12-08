#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[12000];
int odd , even;
void work () {
	int i;
	scanf ( "%d" , &n );
	odd = even = 0;
	for ( i = 1 ; i <= n * 2 ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( a[i] % 2 == 1 ) odd++;
		else even++;
	}
	if ( odd == n ) {
		printf ( "Yes\n" );
	}
	else {
		printf ( "No\n" );
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}