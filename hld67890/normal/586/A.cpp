#include <iostream>
#include <stdio.h>

using namespace std;

int n , ans;
int f[110];
void work () {
	int i , a , b;
	scanf ( "%d" , &n );
	a = b = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a );
		if ( a == 0 && b == 0 ) f[i] = f[i-1] = 1;
		b = a;
	}
	if ( !b ) f[n] = 1;
	for ( i = 1 ; i <= n ; i++ ) ans += 1 - f[i];
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}