#include <stdio.h>
#include <algorithm>

using namespace std;

int n , t;
int s[1200] , d[1200];
int ans , anst;
void work () {
	int i;
	scanf ( "%d%d" , &n , &t );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &s[i] , &d[i] );
		while ( s[i] < t ) s[i] += d[i];
	}
	anst = s[1];
	ans = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( anst > s[i] ) {
			anst = s[i];
			ans = i;
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}