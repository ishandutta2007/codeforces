#include <iostream>
#include <stdio.h>

using namespace std;

int n , k , map[4][120] , dp[4][120] , t[28][5] , s;
char z[120];
void clear () {
	int i , j;
	for ( i = 1 ; i <= 3 ; i++ ) 
	for ( j = 1 ; j <= 100 ; j++ ) map[i][j] = dp[i][j] = 0;
	for ( i = 1 ; i <= 26 ; i++ )
	for ( j = 0 ; j <= 2 ; j++ ) t[i][j] = 0;
}
void work () {
	clear ();
	int i , j , l;
	char tmp;
	scanf ( "%d%d" , &n , &k );
	l = 0;
	for ( i = 1 ; i <= 3 ; i++ ) {
		scanf ( "%s" , z + 1 );
		tmp = 0;
		for ( j = 1 ; j <= n ; j++ ) {
			if ( z[j] == 's' ) s = i, map[i][j] = 0;
			else {
				if ( tmp == z[j] ) map[i][j] = 1;
				else {
					if ( l != 0 && !t[l][2] ) t[l][2] = j - 1;
					if ( z[j] != '.' ) {
						tmp = z[j];
						l++;
						t[l][0] = i;
						t[l][1] = j;
						map[i][j] = 1;
					}
					else tmp = 0;
				}
			}
		}
		if ( tmp ) t[l][2] = n;
	}
	dp[1][1] = dp[2][1] = dp[3][1] = 0; dp[s][1] = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		if ( dp[1][i-1] == 1 && map[1][i] == 0 ) {
			dp[1][i] = 1;
			if ( map[2][i] == 0 ) dp[2][i] = 1;
		}
		if ( dp[2][i-1] == 1 && map[2][i] == 0 ) {
			dp[2][i] = 1;
			if ( map[1][i] == 0 ) dp[1][i] = 1;
			if ( map[3][i] == 0 ) dp[3][i] = 1;
		}
		if ( dp[3][i-1] == 1 && map[3][i] == 0 ) {
			dp[3][i] = 1;
			if ( map[2][i] == 0 ) dp[2][i] = 1;
		}
		for ( j = 1 ; j <= k ; j++ ) {
			if ( t[j][2] >= 1 ) map[t[j][0]][t[j][2]]--,map[t[j][0]][t[j][2]-1]--;
			if ( t[j][1] >= 2 ) map[t[j][0]][t[j][1]-1]++,map[t[j][0]][t[j][1]-2]++;
			if ( t[j][1] == 1 ) map[t[j][0]][t[j][1]-1]++;
			t[j][1]-=2; t[j][2]-=2;
		}
		if ( map[1][i] == 1 ) dp[1][i] = 0;
		if ( map[2][i] == 1 ) dp[2][i] = 0;
		if ( map[3][i] == 1 ) dp[3][i] = 0;
	}
	if ( dp[1][n] == 1 || dp[2][n] == 1 || dp[3][n] == 1 ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	int T;
	scanf ( "%d" , &T );
	while ( T-- )
		work ();
	return 0;
}