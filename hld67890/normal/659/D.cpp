#include <iostream>
#include <stdio.h>

using namespace std;

struct point {
	double x , y;
} a[1200] , p;
int n;
point get ( int i ) {
	point x;
	x = a[i+1];
	if ( a[i].x > a[i+1].x ) x.x -= 0.1;
	if ( a[i].x < a[i+1].x ) x.x += 0.1;
	if ( a[i].y > a[i+1].y ) x.y -= 0.1;
	if ( a[i].y < a[i+1].y ) x.y += 0.1;
	return x;
}
int check ( point x ) {
	int i , sum = 0;
	x.y += 0.01;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( (a[i].x == a[i+1].x && x.x < a[i].x && x.y >= min ( a[i].y , a[i+1].y ) && x.y <= max ( a[i].y , a[i+1].y ))
			|| (x.y==a[i].y&&x.y==a[i+1].y&&x.x < min ( a[i].x , a[i+1].x )) ) sum++;
	}
	if ( sum % 2 == 1 ) return 1;
	return 0;
}
void work () {
	int i , j , ans = 0;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n + 1 ; i++ ) {
		scanf ( "%lf%lf" , &a[i].x , &a[i].y );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		p = get ( i );
		ans += check ( p );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}