#include <stdio.h>
#include <algorithm>

using namespace std;

int a , b , c , d;
int ans[120000] , cnt;
void out ( int x ) {
	ans[++cnt] = x;
}
void output () {
	int i;
	for ( i = 1 ; i <= cnt ; i++ ) {
		printf ( "%d " , ans[i] );
	}
	printf ( "\n" );
}
void work () {
	int i;
	scanf ( "%d%d%d%d" , &a , &b , &c , &d );
	if ( b - a == -1 && c == 0 && d == 0 ) {
		for ( i = 1 ; i <= b ; i++ ) {
			out ( 0 );
			out ( 1 );
		}
		out ( 0 );
		printf ( "YES\n" );
		output ();
		return ;
	}
	if ( c - d == -1 && a == 0 && b == 0 ) {
		for ( i = 1 ; i <= c ; i++ ) {
			out ( 3 );
			out ( 2 );
		}
		out ( 3 );
		printf ( "YES\n" );
		output ();
		return ;
	}
	if ( b - a < 0 || c - d < 0 ) {
		printf ( "NO\n" );
		return ;
	}
	b = b - a;
	c = c - d;
	if ( abs (b - c) <= 1 ) {
		printf ( "YES\n" );
		if ( b > c ) out ( 1 );
		for ( i = 1 ; i <= a ; i++ ) {
			out ( 0 );
			out ( 1 );
		}
		for ( i = 1 ; i <= min ( b , c ) ; i++ ) {
			out ( 2 );
			out ( 1 );
		}
		for ( i = 1 ; i <= d ; i++ ) {
			out ( 2 );
			out ( 3 );
		}
		if ( c > b ) out ( 2 );
		output ();
	}
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}