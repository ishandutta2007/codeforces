#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
	char z[1000] , z2[1000];
	scanf ( "%s%s" , z , z2 );
	if ( strcmp ( z , z2 ) == 0 ) printf ( "%s\n" , z );
	else printf ( "1\n" );
}