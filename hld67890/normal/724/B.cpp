#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[30][30] , b[50][50];
int f;
int solve () {
	int i , j , first , last;
	f = 1;
	for ( i = 1 ; i <= 30 ; i++ ) for ( j = 1 ; j <= 30 ; j++ ) b[i][j] = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		first = last = 0;
		for ( j = 1 ; j <= m ; j++ ) if ( j != a[i][j] ) {
			if ( !first ) first = j;
			else {
				if ( !last ) last = j;
				else f = 0;
			}
		}
	}
	return f;
}
void work () {
	int i , j , k , flag;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= m ; j++ ) scanf ( "%d" , &a[i][j] );
	flag = 0;
	for ( i = 1 ; i <= m ; i++ ) for ( j = 1 ; j <= m ; j++ ) {
		for ( k = 1 ; k <= n ; k++ ) swap ( a[k][i] , a[k][j] );
		if ( solve () == 1 ) flag = 1;
		for ( k = 1 ; k <= n ; k++ ) swap ( a[k][i] , a[k][j] );
	}
	if ( flag == 1 ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}