#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 5100;
int n , m;
int a[maxn];
int dp[maxn][maxn];
int premin[maxn][maxn];
void work () {
	int i , j , tmp;
	scanf ( "%d" , &n );
	for ( i = 0 ; i <= n ; i++ ) for ( j = 0 ; j <= n ; j++ ) dp[i][j] = premin[i][j] = 1000000000;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		dp[i][1] = (a[i]<=a[i-1]?a[i-1]-a[i]+1:0);
		premin[i][1] = min ( premin[i-1][1] , dp[i][1] + (a[i]<=a[i+1]?a[i+1]-a[i]+1:0) );

	}
	m = n / 2;
	if ( n % 2 == 1 ) m++;
	for ( i = 2 ; i <= m ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( j >= 2 ) {
				if ( min ( a[j] , a[j-2] ) <= a[j-1] ) tmp = a[j-1] - min(a[j],a[j-2]) + 1;
				else tmp = 0;
				dp[j][i] = min ( dp[j][i] , dp[j-2][i-1] + tmp );
				//printf ( "##%d %d %d %d\n" , j , i , tmp , dp[j][i] );
			}
			if ( j >= 3 ) {
				dp[j][i] = min ( dp[j][i] , premin[j-3][i-1] + (a[j]<=a[j-1]?a[j-1]-a[j]+1:0) );
			}
			premin[j][i] = min ( premin[j-1][i] , dp[j][i] + (a[j]<=a[j+1]?a[j+1]-a[j]+1:0) );
			//printf ( "%d %d %d %d\n" , j , i , dp[j][i] , premin[j][i] );
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		printf ( "%d%c" , premin[n][i] , i==m?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}