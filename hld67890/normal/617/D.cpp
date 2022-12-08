#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int x1 , y1 , x2 , y2 , x3 , y3;
	scanf ( "%d%d" , &x1 , &y1 );
	scanf ( "%d%d" , &x2 , &y2 );
	scanf ( "%d%d" , &x3 , &y3 );
	if ( x1 > x2 ) swap(x1,x2),swap(y1,y2);
	if ( x1 > x3 ) swap(x1,x3),swap(y1,y3);
	if ( x2 > x3 ) swap(x2,x3),swap(y2,y3);
	if ( x2 == x1 ) {
		if ( x3 == x1 ) {
			printf ( "1\n" );
		}
		else {
			if ( y3 <= min ( y1 , y2 ) || y3 >= max ( y1 , y2 ) ) printf ( "2\n" );
			else printf ( "3\n" );
		}
	}
	else {
		if ( y1 == y2 ) {
			if ( x3 == x2 ) {
				printf ( "2\n" );
			}
			else {
				if ( y1 == y3 ) printf ( "1\n" );
				else printf ( "2\n" );
			}
		}
		else {
			if ( x3 == x2 ) {
				if ( (y2 < y1 && y3>y1) || (y2>y1 & y3 < y1 ) ) printf ( "3\n" );
				else printf ( "2\n" );
			}
			else {
				if ( y2 == y3 ) printf ( "2\n" );
				else printf ( "3\n" );
			}
		}
	}
	return 0;
}