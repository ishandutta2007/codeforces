#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
int n;
int row[maxn] , col[maxn];
int r[5] , rr , c[5] , cc;
int ansx[5] , ansy[5] , ans;
void tryit ( int x , int y ) {
	int ret;
	printf ( "? %d %d %d %d\n" , x , y , x , y );
	fflush(stdout);
	scanf ( "%d" , &ret );
	if ( ret % 2 == 1 ) {
		ans++;
		ansx[ans] = x;
		ansy[ans] = y;
	}
}
int get ( int x1 , int y1 , int x2 , int y2 ) {
	int ret;
	printf ( "? %d %d %d %d\n" , x1 , y1 , x2 , y2 );
	fflush(stdout);
	scanf ( "%d" , &ret );
	return ret;
}
void work () {
	int i , j , le , ri , mid;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "? %d %d %d %d\n" , i , 1 , i , n );
		fflush(stdout);
		scanf ( "%d" , &row[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "? %d %d %d %d\n" , 1 , i , n , i );
		fflush(stdout);
		scanf ( "%d" , &col[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( row[i] % 2 == 1 ) r[++rr] = i;
		if ( col[i] % 2 == 1 ) c[++cc] = i;
	}
	if ( rr == 2 && cc == 2 ) {
		tryit ( r[1] , c[1] );
		tryit ( r[1] , c[2] );
		tryit ( r[2] , c[1] );
		tryit ( r[2] , c[2] );
	}
	else {
		if ( rr == 2 ) {
			le = 1; ri = n;
			while ( le < ri - 1 ) {
				mid = (le + ri)/2;
				if ( get ( r[1] , le , r[1] , mid ) % 2 == 1 ) ri = mid;
				else le = mid;
			}
			tryit ( r[1] , le );
			tryit ( r[1] , ri );
			tryit ( r[2] , le );
			tryit ( r[2] , ri );
		}
		else {
			le = 1; ri = n;
			while ( le < ri - 1 ) {
				mid = (le+ri)/2;
				if ( get ( le , c[1] , mid , c[1] ) % 2 == 1 ) ri = mid;
				else le = mid;
			}
			tryit ( le , c[1] );
			tryit ( ri , c[1] );
			tryit ( le , c[2] );
			tryit ( ri , c[2] );
		}
	}
	printf ( "! %d %d %d %d\n" , ansx[1] , ansy[1] , ansx[2] , ansy[2] );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}