#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n , m;
priority_queue < int > q[1200000];
int a[1200000] , c[1200000];
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ) {
	c[x] += c[y];
	c[y] = x;
}
void work () {
	int i , u , v;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		if ( find ( u ) != find ( v ) ) Union ( find ( u ) , find ( v ) );
	}
	for ( i = 1 ; i <= n ; i++ ) q[find(i)].push ( a[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d" , q[find(i)].top () );
		q[find(i)].pop ();
		if ( i != n ) printf ( " " );
		else printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}