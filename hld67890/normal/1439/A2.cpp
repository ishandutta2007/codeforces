#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
char s[120][120];
int a[120][120];
int c0x[11] , c0y[11] , c1x[11] , c1y[11] , cnt0 , cnt1;
int out[10][12000] , tot;
void output ( int x1 , int y1 , int x2 , int y2 , int x3 , int y3 ) {
	a[x1][y1] ^= 1;
	a[x2][y2] ^= 1;
	a[x3][y3] ^= 1;
	tot++;
	out[1][tot] = x1;
	out[2][tot] = y1;
	out[3][tot] = x2;
	out[4][tot] = y2;
	out[5][tot] = x3;
	out[6][tot] = y3;
}
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , s[i] + 1 );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			a[i][j] = s[i][j] - '0';
		}
	}
	tot = 0;
	for ( i = 1 ; i <= n - 2 ; i++ ) {
		for ( j = 1 ; j <= m - 1 ; j++ ) {
			if ( a[i][j] == 1 ) {
				output ( i , j , i + 1 , j , i + 1 , j + 1 );
			}
		}
		if ( a[i][m] == 1 ) {
			output ( i , m , i + 1 , m - 1 , i + 1 , m );
		}
	}
	for ( j = 1 ; j <= m - 2 ; j++ ) {
		if ( a[n-1][j] == 1 ) {
			output ( n - 1 , j , n - 1 , j + 1 , n , j + 1 );
		}
		if ( a[n][j] == 1 ) {
			output ( n , j , n - 1 , j + 1 , n , j + 1 );
		}
	}
	//printf ( "%d %d %d %d\n" , a[1][1] , a[1][2] , a[2][1] , a[2][2] );
	if ( a[n-1][m-1] + a[n-1][m] + a[n][m-1] + a[n][m] == 4 ) {
		output ( n - 1 , m - 1 , n - 1 , m , n , m - 1 );
	}
	if ( a[n-1][m-1] + a[n-1][m] + a[n][m-1] + a[n][m] == 1 ) {
		if ( a[n-1][m-1] == 0 ) {
			output ( n - 1 , m , n , m - 1 , n , m );
		}
		else {
			output ( n - 1 , m - 1 , n , m - 1 , n , m );
		}
	}
	if ( a[n-1][m-1] + a[n-1][m] + a[n][m-1] + a[n][m] == 2 ) {
		cnt0 = cnt1 = 0;
		for ( i = n - 1 ; i <= n ; i++ ) {
			for ( j = m - 1 ; j <= m ; j++ ) {
				if ( a[i][j] == 0 ) {
					c0x[++cnt0] = i;
					c0y[cnt0] = j;
				}
				else {
					c1x[++cnt1] = i;
					c1y[cnt1] = j;
				}
			}
		}
		output ( c0x[1] , c0y[1] , c0x[2] , c0y[2] , c1x[1] , c1y[1] );
	}
	if ( a[n-1][m-1] + a[n-1][m] + a[n][m-1] + a[n][m] == 3 ) {
		cnt0 = cnt1 = 0;
		for ( i = n - 1 ; i <= n ; i++ ) {
			for ( j = m - 1 ; j <= m ; j++ ) {
				if ( a[i][j] == 0 ) {
					c0x[++cnt0] = i;
					c0y[cnt0] = j;
				}
				else {
					c1x[++cnt1] = i;
					c1y[cnt1] = j;
				}
			}
		}
		output ( c1x[1] , c1y[1] , c1x[2] , c1y[2] , c1x[3] , c1y[3] );
	}
	printf ( "%d\n" , tot );
	for ( i = 1 ; i <= tot ; i++ ) {
		for ( j = 1 ; j <= 6 ; j++ ) {
			printf ( "%d%c" , out[j][i] , j==6?'\n':' ' );
		}
	}
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}