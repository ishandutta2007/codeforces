#include <stdio.h>
#include <algorithm>

using namespace std;

int n , a , b;
char z[120000];
void work () {
	scanf ( "%d%d%d" , &n , &a , &b );
	scanf ( "%s" , z + 1 );
	if ( z[a] == z[b] ) printf ( "0\n" );
	else printf ( "1\n" );
}
int main () {
	work ();
	return 0;
}