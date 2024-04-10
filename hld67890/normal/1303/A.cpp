#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char z[12000];
int ans;
void work () {
	int i , j;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == '1' ) break;
	}
	if ( i == n + 1 ) {
		printf ( "0\n" );
		return ;
	}
	for ( j = n ; j >= 1 ; j-- ) {
		if ( z[j] == '1' ) break;
	}
	ans = 0;
	for ( i ; i <= j ; i++ ) {
		if ( z[i] == '0' ) ans++;
	}
	printf ( "%d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}