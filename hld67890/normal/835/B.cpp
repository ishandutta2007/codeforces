#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int NN = 120000;
int k , l;
int a[20];
char s[NN];
int ans;
void work () {
	int i , j;
	scanf ( "%d" , &k );
	scanf ( "%s" , s + 1 );
	l = strlen ( s + 1 );
	for ( i = 1 ; i <= l ; i++ ) {
		a[s[i]-'0']++;
		k -= (s[i]-'0');
	}
	for ( i = 0 ; i <= 8 ; i++ ) {
		for ( j = 1 ; j <= a[i] ; j++ ) {
			if ( k <= 0 ) break;
			ans++;
			k -= (9-i);
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}