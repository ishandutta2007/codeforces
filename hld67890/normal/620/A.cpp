#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int a , b , c , d;
	scanf ( "%d%d%d%d" , &a , &b , &c , &d );
	a = a - c; b = b - d;
	if ( a < 0 ) a = -a; 
	if ( b < 0 ) b = -b; 
	if ( a < b ) swap ( a , b );
	printf ( "%d\n" , a );
	return 0;
}