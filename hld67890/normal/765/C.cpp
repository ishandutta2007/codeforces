#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int k , a , b;
int s1 , s2;
int f;
void work () {
	scanf ( "%d%d%d" , &k , &a , &b );
	s1 = a / k; s2 = b / k;
	f = 1;
	if ( s1 == s2 && s2 == 0 ) f = 0;
	if ( s1 == 0 && b % k != 0 ) f = 0;
	if ( s2 == 0 && a % k != 0 ) f = 0;
	if ( f == 0 ) printf ( "-1\n" );
	else printf ( "%d\n" , s1 + s2 );
}
int main () {
	work ();
	return 0;
}