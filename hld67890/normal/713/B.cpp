#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
void work () {
	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4;
	int l , r , mid;
	int c;
	scanf ( "%d" , &n );
	l = 1; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , 1 , n , mid );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( c > 0 ) r = mid;
		else l = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , 1 , n , l );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( c > 0 ) y2 = l;
	else y2 = r;
	
	l = 1; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , 1 , mid , y2 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( c > 0 ) r = mid;
		else l = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , 1 , l , y2 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( c > 0 ) x2 = l;
	else x2 = r;
	
	l = 1; r = y2;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , mid , x2 , y2 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( c > 0 ) l = mid;
		else r = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , r , x2 , y2 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( c > 0 ) y1 = r;
	else y1 = l;
	
	l = 1; r = x2;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , mid , y1 , x2 , y2 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( c > 0 ) l = mid;
		else r = mid;
	}
	printf ( "? %d %d %d %d\n" , r , y1 , x2 , y2 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( c > 0 ) x1 = r;
	else x1 = l;
	
	//printf ( "! %d %d %d %d %d %d %d %d" , x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 );
	l = 1; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , 1 , n , mid );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( x1 >= 1 && n >= x2 && y1 >= 1 && mid >= y2 ) c--;
		if ( c > 0 ) r = mid;
		else l = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , 1 , n , l );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( x1 >= 1 && n >= x2 && y1 >= 1 && l >= y2 ) c--;
	if ( c > 0 ) y4 = l;
	else y4 = r;
	
	l = 1; r = n;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , 1 , mid , y4 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( x1 >= 1 && mid >= x2 && y1 >= 1 && y4 >= y2 ) c--;
		if ( c > 0 ) r = mid;
		else l = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , 1 , l , y4 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( x1 >= 1 && l >= x2 && y1 >= 1 && y4 >= y2 ) c--;
	if ( c > 0 ) x4 = l;
	else x4 = r;
	
	l = 1; r = y4;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , 1 , mid , x4 , y4 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( x1 >= 1 && x4 >= x2 && y1 >= mid && y4 >= y2 ) c--;
		if ( c > 0 ) l = mid;
		else r = mid;
	}
	printf ( "? %d %d %d %d\n" , 1 , r , x4 , y4 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( x1 >= 1 && x4 >= x2 && y1 >= r && y4 >= y2 ) c--;
	if ( c > 0 ) y3 = r;
	else y3 = l;
	
	//printf ( "! %d %d %d %d %d %d %d %d" , x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 );
	l = 1; r = x4;
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		printf ( "? %d %d %d %d\n" , mid , y3 , x4 , y4 );
		fflush(stdout);
		scanf ( "%d" , &c );
		if ( x1 >= mid && x4 >= x2 && y1 >= y3 && y4 >= y2 ) c--;
		if ( c > 0 ) l = mid;
		else r = mid;
	}
	printf ( "? %d %d %d %d\n" , r , y3 , x4 , y4 );
	fflush(stdout);
	scanf ( "%d" , &c );
	if ( x1 >= r && x4 >= x2 && y1 >= y3 && y4 >= y2 ) c--;
	if ( c > 0 ) x3 = r;
	else x3 = l;
	printf ( "! %d %d %d %d %d %d %d %d" , x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}