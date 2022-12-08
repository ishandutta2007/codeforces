#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long x1 , y1 , x2 , y2;
void work () {
	int i , col;
	scanf ( "%d" , &n );
	printf ( "YES\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d%I64d%I64d%I64d" , &x1 , &y1 , &x2 , &y2 );
		col = 1;
		if ( (x1 + 1000000000ll) % 2 == 1 ) col += 2;
		if ( (y1 + 1000000000ll) % 2 == 1 ) col++;
		printf ( "%d\n" , col );
	}
}
int main () {
	work ();
	return 0;
}