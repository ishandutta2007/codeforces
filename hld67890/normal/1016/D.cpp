#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120;
int n , m;
int a[maxn] , b[maxn];
int c[maxn] , d[maxn] , lc , ld;
int ans[maxn][maxn];
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &b[i] );
	}
	for ( i = 0 ; i <= 30 ; i++ ) {
		//printf ( "%d\n" , i );
		lc = 0;
		for ( j = 1 ; j <= n ; j++ ) if ( a[j] & (1<<i) ) c[++lc] = j;
		ld = 0;
		for ( j = 1 ; j <= m ; j++ ) if ( b[j] & (1<<i) ) d[++ld] = j;
		//for ( j = 1 ; j <= m ; j++ ) printf ( "%d " , b[j] );
		//printf ( "\n%d %d %d\n" , lc , ld );
		if ( lc > ld ) {
			for ( j = 1 ; j <= ld ; j++ ) {
				ans[c[j]][d[j]] ^= (1<<i);
			}
			if ( (lc - ld) % 2 == 1 ) {
				printf ( "NO\n" );
				return ;
			}
			for ( j = ld + 1 ; j <= lc ; j++ ) {
				ans[c[j]][1] ^= (1<<i);
			}
		}
		if ( ld > lc ) {
			for ( j = 1 ; j <= lc ; j++ ) {
				ans[c[j]][d[j]] ^= (1<<i);
			}
			if ( (ld - lc) % 2 == 1 ) {
				printf ( "NO\n" );
				return ;
			}
			for ( j = lc + 1 ; j <= ld ; j++ ) {
				ans[1][d[j]] ^= (1<<i);
			}
		}
		if ( lc == ld ) {
			for ( j = 1 ; j <= lc ; j++ ) {
				ans[c[j]][d[j]] ^= (1<<i);
			}
		}
	}
	printf ( "YES\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			printf ( "%d%c" , ans[i][j] , j==m?'\n':' ' ); 
		}
	}
}
int main () {
	work ();
	return 0;
}