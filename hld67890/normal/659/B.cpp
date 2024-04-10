#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	char z[20];
	int i , s;
} p[110000];
int n , m;
bool cmp ( node x1 , node x2 ) {
	if ( x1.i == x2.i ) return x1.s > x2.s;
	return x1.i < x2.i;
}
void work () {
	int i , maxx;
	scanf ( "%d%d" , &n  , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%s%d%d" , p[i].z , &p[i].i , &p[i].s );
	sort ( p + 1 , p + 1 + n , cmp );
	p[0].i = -1;
	p[n+1].s = -1;
	for ( i = 1 ; i <= n ; ) {
		maxx = p[i].s;
		if ( p[i+1].s == maxx ) {
			if ( p[i+2].s == maxx && p[i+2].i == p[i].i ) printf ( "?\n" );
			else {
				printf ( "%s %s\n" , p[i].z , p[i+1].z );
			}
		}
		else {
			if ( p[i+1].s == p[i+2].s && p[i+2].i == p[i].i ) printf ( "?\n" );
			else printf ( "%s %s\n" , p[i].z , p[i+1].z );
		}
		maxx = p[i].i;
		while ( p[i].i == maxx ) i++;
	}
}
int main () {
	work ();
	return 0;
}