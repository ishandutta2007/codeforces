#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[1200][1200];
void work () {
	int i , j , k , l , cnt;
	scanf ( "%d" , &n );
	cnt = 0;
	for ( i = 1 ; i <= n ; i += 4 ) {
		for ( j = 1 ; j <= n ; j += 4 ) {
			for ( k = 1 ; k <= 4 ; k++ ) {
				for ( l = 1 ; l <= 4 ; l++ ) {
					a[i+k-1][j+l-1] = cnt + (k-1)*4+l-1;
				}
			}
			cnt += 16;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			printf ( "%d " , a[i][j] );
		}
		printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}