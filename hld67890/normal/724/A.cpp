#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char z1[120] , z2[120];
int a , b;
void work () {
	scanf ( "%s%s" , z1 + 1 , z2 + 1 );
	if ( strcmp ( z1 + 1 , "monday" ) == 0 ) a = 1;
	if ( strcmp ( z1 + 1 , "tuesday" ) == 0 ) a = 2;
	if ( strcmp ( z1 + 1 , "wednesday" ) == 0 ) a = 3;
	if ( strcmp ( z1 + 1 , "thursday" ) == 0 ) a = 4;
	if ( strcmp ( z1 + 1 , "friday" ) == 0 ) a = 5;
	if ( strcmp ( z1 + 1 , "saturday" ) == 0 ) a = 6;
	if ( strcmp ( z1 + 1 , "sunday" ) == 0 ) a = 0;
	
	if ( strcmp ( z2 + 1 , "monday" ) == 0 ) b = 1;
	if ( strcmp ( z2 + 1 , "tuesday" ) == 0 ) b = 2;
	if ( strcmp ( z2 + 1 , "wednesday" ) == 0 ) b = 3;
	if ( strcmp ( z2 + 1 , "thursday" ) == 0 ) b = 4;
	if ( strcmp ( z2 + 1 , "friday" ) == 0 ) b = 5;
	if ( strcmp ( z2 + 1 , "saturday" ) == 0 ) b = 6;
	if ( strcmp ( z2 + 1 , "sunday" ) == 0 ) b = 0;
	if ( a == b || (a + 2) % 7 == b || (a + 3) % 7 == b ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}