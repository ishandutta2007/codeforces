#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
int n , a , b;
int mark;
int m[maxn][maxn];
void work () {
	int i , j;
	scanf ( "%d%d%d" , &n , &a , &b );
	if ( a > b ) {
		swap ( a , b );
		mark = 1;
	}
	if ( a >= 2 ) {
		printf ( "NO\n" );
		return ;
	}
	if ( n == 3 ) {
		if ( b == 1 ) {
			printf ( "NO\n" );
			return ;
		}
		if ( b == 2 ) {
			m[1][3] = m[2][3] = m[3][1] = m[3][2] = 1;
		}
		if ( b == 3 ) {
			m[1][2] = m[1][3] = m[2][1] = m[2][3] = m[3][1] = m[3][2] = 1;
		}
	}
	else {
		if ( b == 1 ) {
			if ( n == 2 ) {
				printf ( "NO\n" );
				return ;
			}
			else {
				for ( i = 1 ; i < n ; i++ ) {
					m[i][i+1] = 1;
					m[i+1][i] = 1;
				}
			}
		}
		else {
			if ( b == n - 2 ) {
				for ( i = 1 ; i <= n ; i++ ) {
					for ( j = 1 ; j <= n ; j++ ) {
						if ( i != j ) m[i][j] = 1;
					}
				}
				m[1][2] = m[2][1] = m[3][4] = m[4][3] = 0;
			}
			else
			{
				if ( b == n - 1 ) b--;
				for ( i = 1 ; i < n ; i++ ) {
					m[i][i+1] = 1;
					m[i+1][i] = 1;
				}
				for ( i = 1 ; i <= b - 1 ; i++ ) {
					for ( j = i + 1 ; j <= b - 1 ; j++ ) {
						m[i][j] = m[j][i] = 1;
					}
				}
				for ( i = 1 ; i <= b - 1 ; i++ ) {
					for ( j = b ; j <= n ; j++ ) {
						m[i][j] = m[j][i] = 1;
					}
				}
			}
		}
	}
	if ( mark ) {
		for ( i = 1 ; i <= n ; i++ ) {
			for ( j = 1 ; j <= n ; j++ ) {
				if ( i != j ) m[i][j] = 1 ^ m[i][j];
			}
		}
	}
	printf ( "YES\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) printf ( "%d" , m[i][j] );
		printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}