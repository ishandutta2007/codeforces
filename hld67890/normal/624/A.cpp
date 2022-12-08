#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	double a , b , c , d;
	scanf ( "%lf%lf%lf%lf" , &a , &b , &c , &d );
	printf ( "%.6lf\n" , (b-a) / (c+d) );
	return 0;
}