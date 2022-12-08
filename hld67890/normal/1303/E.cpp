#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n , m;
char s[10000] , t[12000];
int dp[410][410];
int check ( int l1 , int l2 , char *t1 , char *t2 ) {
	int i , j;
	for ( i = 0 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= l1 ; j++ ) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j <= i ; j++ ) {
			if ( dp[i][j] != -1 ) {
				if ( j != l1 && s[i+1] == t1[j+1] ) {
					dp[i+1][j+1] = max ( dp[i+1][j+1] , dp[i][j] );
				}
				if ( dp[i][j] != l2 && s[i+1] == t2[dp[i][j]+1] ) {
					dp[i+1][j] = max ( dp[i+1][j] , dp[i][j] + 1 );
				}
				dp[i+1][j] = max ( dp[i+1][j] , dp[i][j] );
			}
		}
	}
	if ( dp[n][l1] >= l2 ) return true;
	return false;
}
void work () {
	int i;
	scanf ( "%s%s" , s + 1 , t + 1 );
	n = strlen ( s + 1 );
	m = strlen ( t + 1 );
	for ( i = 0 ; i <= m ; i++ ) {
		if ( check ( i , m - i , t , t + i ) == true ) {
			printf ( "YES\n" );
			return ;
		}
	}
	printf ( "NO\n" );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}