#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[1200];
int b[1200][1200];
int check ( int x , int y ) {
	if ( 1 <= y && b[x][y] == 0 ) return 1;
	return 0;
}
void work () {
	int i , j , x , y;
	//n = 23;
	//for ( i = 1 ; i <= n ; i++ ) a[i] = i;
	//random_shuffle ( a + 1 , a + 1 + n );
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		x = y = i;
		for ( j = 1 ; j <= a[i] ; j++ ) {
			//printf ( "%d %d %d %d %d\n" , i , j , x , y , a[i]);
			b[x][y] = a[i];
			if ( check ( x , y - 1 ) ) y--;
			else x++;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= i ; j++ ) {
			printf ( "%d%c" , b[i][j] , i==j?'\n':' ' );
		}
	}
}
int main () {
	work ();
	return 0;
}