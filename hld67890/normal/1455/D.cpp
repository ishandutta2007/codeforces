#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int x , i;
} s[510];
int n , x;
int a[510];
int dp[510][510][510];
int ans;
bool cmp ( node x1 , node x2 ) {
	return x1.x < x2.x;
}
void work () {
	int i , j , k;
	scanf ( "%d%d" , &n , &x );
	s[n+1].x = x; s[n+1].i = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		s[i].x = a[i];
		s[i].i = i;
	}
	sort ( s + 1 , s + 1 + n + 1 , cmp );
	k = 0;
	for ( i = 1 ; i <= n + 1 ; i++ ) {
		if ( i == 1 || s[i].x != s[i-1].x ) k++;
		if ( s[i].i == 0 ) x = k;
		else a[s[i].i] = k;
	}
	for ( i = 1 ; i <= n ; i++ )
		for ( j = 1 ; j <= n + 1 ; j++ )
			for ( k = 1 ; k <= n + 1 ; k++ ) {
				dp[i][j][k] = 999999;
			}
	dp[1][a[1]][x] = 0;
	if ( a[1] > x ) dp[1][x][a[1]] = 1;
	for ( i = 1 ; i < n ; i++ ) {
		for ( j = 1 ; j <= n + 1 ; j++ ) {
			for ( k = 1 ; k <= n + 1 ; k++ ) {
				if ( dp[i][j][k] != 999999 ) {
					if ( j <= a[i+1] ) {
						dp[i+1][a[i+1]][k] = min ( dp[i+1][a[i+1]][k] , dp[i][j][k] );
					}
					if ( k < a[i+1] && j <= k ) {
						dp[i+1][k][a[i+1]] = min ( dp[i+1][k][a[i+1]] , dp[i][j][k] + 1 );
					}
				}
			}
		}
	}
	ans = 999999;
	for ( j = 1 ; j <= n + 1 ; j++ ) {
		for ( k = 1 ; k <= n + 1 ; k++ ) {
			ans = min ( ans , dp[n][j][k] );
		}
	}
	if ( ans == 999999 ) ans = -1;
	printf ( "%d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}