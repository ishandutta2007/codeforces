#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const double pi = acos (-1);
int n;
double x , y , deg;
void work () {
	int i;
	scanf ( "%d" , &n );
	n = n / 2;
	n--;
	x = y = 0.0;
	deg = pi / 2.0;
	for ( i = 1 ; i <= n ; i++ ) {
		deg -= (pi/2.0/(n+1));
		//printf ( "%lf\n" , deg );
		x += cos(deg);
		y += sin(deg);
	}
	//printf ( "%lf %lf\n" , x , y );
	printf ( "%.9lf\n" , 1.0 + x + y );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}