#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[300000] , c[300000];
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
	int i , root = 0 , ans = 0;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( a[i] == i ) root = i;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( find ( a[i] ) != find ( i ) ) Union ( find ( a[i] ) , find ( i ) );
		else {
			if ( i == root ) continue;
			ans++;
			if ( root ) a[i] = root;
			else a[i] = i, root = i;
		}
	}
	printf ( "%d\n" , ans );
	for ( i = 1 ; i < n ; i++ ) printf ( "%d " , a[i] );
	printf ( "%d\n" , a[n] );
}
int main () {
	work ();
	return 0;
}