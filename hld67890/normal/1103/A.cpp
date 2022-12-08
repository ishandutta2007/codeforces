#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 1200;
int n;
char s[maxn];
int x1[5] = {1,1,1,1} , y1[5] = {1,2,3,4};
int x2[5] = {4,4,3,3} , y2[5] = {1,3,1,3};
int h1 , h2;
void work () {
	int i;
	scanf ( "%s" , s + 1 );
	n = strlen ( s + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '0' ) {
			printf ( "%d %d\n" , x1[h1%4] , y1[h1%4] );
			h1++;
		}
		else {
			printf ( "%d %d\n" , x2[h2%4] , y2[h2%4] );
			h2++;
		}
	}
}
int main () {
	work ();
	return 0;
}