#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 120;
int n;
char z[maxn][maxn];
int ord[maxn] , l[maxn];
int v[maxn][maxn] , sum[maxn];
int taboo[maxn];
int check ( int x , int y ) {
	int i , j;
	if ( l[x] > l[y] ) return 0;
	for ( i = 1 ; i <= l[y] - l[x] + 1 ; i++ ) {
		for ( j = 1 ; j <= l[x] ; j++ ) {
			if ( z[x][j] != z[y][i+j-1] ) break;
		}
		if ( j == l[x] + 1 ) return 1;
	}
	return 0;
}
void work () {
	int i , j , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z[i] + 1 );
		l[i] = strlen ( z[i] + 1 );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			sum[i] += check ( i , j );
		}
	}
	//for ( k = 1 ; k <= n ; k++ ) printf ( "%d\n" , sum[k] );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( sum[j] >= n - i + 1 && !taboo[j] ) {
				ord[i] = j;
				taboo[j] = 1;
				break;
			}
		}
		//printf ( "%d %d\n" , i , j );
		if ( j == n + 1 ) {
			printf ( "NO\n" );
			return ;
		}
	}
	printf ( "YES\n" );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%s\n" , z[ord[i]] + 1 );
}
int main () {
	work ();
	return 0;
}