#include <iostream>
#include <stdio.h>

using namespace std;

int n , m , k , q;
int a[100010] , b[100010];
void work () {
	int i;
	scanf ( "%d%d" , &n , &m );
	scanf ( "%d%d" , &k , &q );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= m ; i++ ) scanf ( "%d" , &b[i] );
	if ( a[k] < b[m-q+1] ) printf ("YES\n");
	else printf ("NO\n");
}
int main () {
	work ();
	return 0;
}