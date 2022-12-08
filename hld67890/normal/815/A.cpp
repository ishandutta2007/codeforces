#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 510;
int n , m;
int a[NN][NN];
int tot;
int br[NN] , bc[NN];
void work () {
	int i , j , minn;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= m ; j++ ) scanf ( "%d" , &a[i][j] );
	minn = 1000;
	for ( i = 1 ; i <= m ; i++ ) minn = min ( minn , a[1][i] );
	for ( i = 1 ; i <= minn ; i++ ) {
		br[1]++;
	}
	for ( i = 1 ; i <= m ; i++ ) {
		a[1][i] -= minn;
		for ( j = 1 ; j <= a[1][i] ; j++ ) {
			bc[i]++;
		}
		for ( j = 2 ; j <= n ; j++ ) {
			a[j][i] -= a[1][i];
			if ( a[j][i] < 0 ) {
				printf ( "-1\n" );
				return ;
			}
		}
	}
	for ( i = 2 ; i <= n ; i++ ) {
		for ( j = 2 ; j <= m ; j++ ) if ( a[i][j] != a[i][j-1] ) {
			//printf ( "%d %d %d %d\n" , i , j , a[i][j] , a[i][j-1] );
			printf ( "-1\n" );
			return ;
		}
		for ( j = 1 ; j <= a[i][1] ; j++ ) {
			br[i]++;
		}
	}
	if ( n > m ) {
		minn = 1000;
		for ( i = 1 ; i <= n ; i++ ) {
			minn = min ( minn , br[i] );
		}
		for ( i = 1 ; i <= n ; i++ ) {
			br[i] -= minn;
		}
		for ( i = 1 ; i <= m ; i++ ) {
			bc[i] += minn;
		}
	}
	if ( n < m ) {
		minn = 1000;
		for ( i = 1 ; i <= m ; i++ ) {
			minn = min ( minn , bc[i] );
		}
		for ( i = 1 ; i <= m ; i++ ) {
			bc[i] -= minn;
		}
		for ( i = 1 ; i <= n ; i++ ) {
			br[i] += minn;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) tot += br[i];
	for ( i = 1 ; i <= m ; i++ ) tot += bc[i];
	printf ( "%d\n" , tot );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= br[i] ; j++ ) {
			printf ( "row %d\n" , i );
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		for ( j = 1 ; j <= bc[i] ; j++ ) {
			printf ( "col %d\n" , i );
		}
	}
}
int main () {
	work ();
	return 0;
}