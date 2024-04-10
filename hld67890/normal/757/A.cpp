#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 120000;
int n;
int num[20];
char z[maxn];
void work () {
	int i , minn;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'B' ) num[1]++;
		if ( z[i] == 'u' ) num[2]++;
		if ( z[i] == 'l' ) num[3]++;
		if ( z[i] == 'b' ) num[4]++;
		if ( z[i] == 'a' ) num[5]++;
		if ( z[i] == 's' ) num[6]++;
		if ( z[i] == 'r' ) num[7]++;
	}
	num[2] /= 2;
	num[5] /= 2;
	minn = 999999;
	for ( i = 1 ; i <= 7 ; i++ ) minn = min ( minn , num[i] );
	printf ( "%d\n" , minn );
}
int main () {
	work ();
	return 0;
}