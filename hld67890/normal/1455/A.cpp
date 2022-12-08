#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char z[129];
void work () {
	scanf ( "%s" , z + 1 );
	printf ( "%d\n" , strlen ( z + 1 ) );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}