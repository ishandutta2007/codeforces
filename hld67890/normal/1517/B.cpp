#include <stdio.h>
#include <algorithm>

using namespace std;

struct so {
	int x , i , j;
} s[12000];
int n , m , tot;
int a[120][120];
int now[120];
int b[120][120];
bool cmp ( so x1 , so x2 ) {
	return x1.x < x2.x;
}
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &m );
	tot = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			scanf ( "%d" , &a[i][j] );
			tot++;
			s[tot].i = i;
			s[tot].j = j;
			s[tot].x = a[i][j];
			b[i][j] = 0;
		}
		now[i] = 0;
	}
	sort ( s + 1 , s + 1 + tot , cmp );
	for ( i = 1 ; i <= m ; i++ ) {
		b[s[i].i][i] = s[i].x;
	}
	for ( i = m + 1 ; i <= tot ; i++ ) {
		now[s[i].i]++;
		while ( b[s[i].i][now[s[i].i]] != 0 ) now[s[i].i]++;
		b[s[i].i][now[s[i].i]] = s[i].x;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			printf ( "%d%c" , b[i][j] , j==m?'\n':' ' );
		}
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}