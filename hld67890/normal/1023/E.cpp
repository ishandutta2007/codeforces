#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
int n;
char s[200];
char ans[maxn*2];
void work () {
	int i , nx , ny;
	scanf ( "%d" , &n );
	nx = ny = n;
	while ( nx + ny != n + 1 ) {
		printf ( "? %d %d %d %d\n" , 1 , 1 , nx , ny - 1 );
		fflush(stdout);
		scanf ( "%s" , s + 1 );
		if ( s[1] == 'Y' ) {
			ny--;
			ans[nx+ny] = 'R';
		}
		else {
			nx--;
			ans[nx+ny] = 'D';
		}
	}
	nx = ny = 1;
	while ( nx + ny != n + 1 ) {
		printf ( "? %d %d %d %d\n" , nx + 1 , ny , n , n );
		fflush(stdout);
		scanf ( "%s" , s + 1 );
		if ( s[1] == 'Y' ) {
			ans[nx+ny] = 'D';
			nx++;
		}
		else {
			ans[nx+ny] = 'R';
			ny++;
		}
	}
	printf ( "! %s\n" , ans + 2 );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}