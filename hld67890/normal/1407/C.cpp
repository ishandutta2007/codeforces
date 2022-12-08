#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int a[12000];
queue < int > q;
void work () {
	int i , u , v , x , y;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		q.push ( i );
	}
	while ( q.size () > 1 ) {
		u = q.front (); q.pop ();
		v = q.front (); q.pop ();
		printf ( "? %d %d\n" , u , v );
		fflush(stdout);
		scanf ( "%d" , &x );
		printf ( "? %d %d\n" , v , u );
		fflush(stdout);
		scanf ( "%d" , &y );
		if ( x > y ) {
			a[u] = x;
			q.push ( v );
		}
		else {
			a[v] = y;
			q.push ( u );
		}
	}
	a[q.front ()] = n;
	printf ( "!" );
	for ( i = 1 ; i <= n ; i++ ) printf ( " %d" , a[i] );
	printf ( "\n" );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}