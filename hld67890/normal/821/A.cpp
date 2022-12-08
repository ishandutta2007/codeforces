#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 55;
int n;
int a[NN][NN];
void work () {
	int i , j , k , l , f;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			scanf ( "%d" , &a[i][j] );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( a[i][j] == 1 ) continue;
			f = 0;
			for ( k = 1 ; k <= n ; k++ ) {
				for ( l = 1 ; l <= n ; l++ ) {
					if ( a[i][k] + a[l][j] == a[i][j] ) f = 1;
				}
			}
			if ( f == 0 ) {
				printf ( "No\n" );
				return ;
			}
		}
	}
	printf ( "Yes\n" );
}
int main () {
	work ();
	return 0;
}