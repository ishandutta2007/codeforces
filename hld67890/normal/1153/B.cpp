#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120;
int n , m , hh;
int a[maxn] , b[maxn] , top[maxn][maxn];
int h[maxn][maxn];
void work () {
	int i , j;
	scanf ( "%d%d%d" , &n , &m , &hh );
	for ( i = 1 ; i <= m ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &b[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			scanf ( "%d" , &top[i][j] );
			h[i][j] = top[i][j];
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( b[i] == 0 ) continue;
		for ( j = 1 ; j <= m ; j++ ) {
			if ( top[i][j] == 1 && a[j] >= b[i] ) h[i][j] = b[i];
		}
	}
	for ( j = 1 ; j <= m ; j++ ) {
		if ( a[j] == 0 ) continue;
		for ( i = 1 ; i <= n ; i++ ) {
			if ( top[i][j] == 1 && b[i] >= a[j] ) h[i][j] = a[j];
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			printf ( "%d%c" , h[i][j] , j==m?'\n':' ' );
		}
	}
}
int main () {
	work ();
	return 0;
}