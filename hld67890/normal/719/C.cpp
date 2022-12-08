#include <stdio.h>
#include <algorithm>
#define $ if(0)

using namespace std;

int n , t;
char z[220000];
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &t );
	scanf ( "%s" , z + 1 );
	for ( i = 1 ; i <= n ; i++ ) if ( z[i] == '.' ) break;
	j = i;
	for ( i++ ; i <= n ; i++ ) {
		if ( z[i] > '4' ) break;
	}
	if ( i == n + 1 ) {
		printf ( "%s\n" , z + 1 );
		return ;
	}
	for ( i-- , t-- ; i > j && t > 0 && z[i] >= '4' ; i-- , t-- ) ;
	$ printf ( "%d\n" , i );
	z[0] = '0';
	if ( z[i] == '.' ) {
		i--;
		z[i]++;
		j = i;
		for ( ; z[i] > '9' ; i-- ) z[i] = '0', z[i-1]++;
		if ( z[0] != '0' ) i = 0;
		else i = 1;
		for ( i ; i <= j ; i++ ) printf ( "%c" , z[i] );
		printf ( "\n" );
	}
	else {
		z[i]++;
		j = i;
		for ( ; z[i] > '9' || z[i] == '.' ; i-- ) {
			if ( z[i] == '.' ) continue;
			z[i] = '0', z[i-1]++;
		}
		if ( z[0] != '0' ) i = 0;
		else i = 1;
		for ( i ; i <= j ; i++ ) printf ( "%c" , z[i] );
		printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}