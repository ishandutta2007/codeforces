#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s;
int a[12000];
void work () {
	int i;
	scanf ( "%d" , &s );
	n = 1;
	a[1] = -1;
	while ( s >= 999999 ) {
		a[++n] = 1000000;
		s -= 999999;
	}
	a[++n] = s + 2;
	printf ( "%d\n" , n );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , a[i] , i==n?'\n':' ' );
}
int main () {
	work ();
	return 0;
}