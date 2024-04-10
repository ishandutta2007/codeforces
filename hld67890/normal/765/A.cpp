#include <stdio.h>
#include <algorithm>

using namespace std;

int n , tot;
char z[10] , s[20];
void work () {
	int i;
	scanf ( "%d" , &n );
	/*scanf ( "%s" , z + 1 );
	tot = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , s + 1 );
		if ( s[6] == z[1] && s[7] == z[2] && s[8] == z[3] ) tot++;
	}*/
	if ( n % 2 == 0 ) printf ( "home\n" );
	else printf ( "contest\n" );
}
int main () {
	work ();
	return 0;
}