#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const double pi = acos(-1);
int main () {
	double d , h , v , e;
	scanf ( "%lf%lf%lf%lf" , &d , &h , &v , &e );
	if ( pi * d * d * e / 4.0 >= v ) {
		printf ( "NO\n" );
	}
	else {
		printf ( "YES\n" );
		printf ( "%.10lf\n" , (h * pi * d * d / 4.0) / (v-(pi * d * d * e / 4.0)) );
	}
	return 0;
}