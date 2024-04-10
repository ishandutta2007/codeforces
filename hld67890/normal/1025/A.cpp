#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s[202];
int ans;
char z[120000];
void work () {
	int i;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	for ( i = 1 ; i <= n ; i++ ) s[z[i]-'a'+1]++;
	ans = 0;
	for ( i = 1 ; i <= 26 ; i++ ) if ( s[i] >= 2 ) ans = 1;
	if ( n == 1 || ans == 1 ) {
		printf ( "Yes\n" );
	}
	else {
		printf ( "No\n" );
	}
}
int main () {
	work ();
	return 0;
}