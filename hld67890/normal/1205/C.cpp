#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120][120];
void zuoshang ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i - 1 , j - 1 , i , j );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i-1][j-1] = a[i][j]^1^tmp;
}
void shang ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i - 2 , j , i , j );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i-2][j] = a[i][j]^1^tmp;
}
void zuo ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i , j - 2 , i , j );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i][j-2] = a[i][j]^1^tmp;
}
void you ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i , j , i , j + 2 );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i][j+2] = a[i][j]^1^tmp;
}
void xia ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i , j , i + 2 , j );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i+2][j] = a[i][j]^1^tmp;
}
void youxia ( int i , int j ) {
	int tmp;
	printf ( "? %d %d %d %d\n" , i , j , i + 1 , j + 1 );
	fflush(stdout);
	scanf ( "%d" , &tmp );
	a[i+1][j+1] = a[i][j]^1^tmp;
}
void dfs ( int i , int j ) {
	if ( i - 1 > 0 && j - 1 > 0 && a[i-1][j-1] == -1 ) {
		zuoshang ( i , j );
		dfs ( i - 1 , j - 1 );
	}
	if ( i - 2 > 0 && a[i-2][j] == -1 ) {
		shang ( i , j );
		dfs ( i - 2 , j );
	}
	if ( j - 2 > 0 && a[i][j-2] == -1 ) {
		zuo ( i , j );
		dfs ( i , j - 2 );
	}
	if ( i + 2 <= n && a[i+2][j] == -1 ) {
		xia ( i , j );
		dfs ( i + 2 , j );
	}
	if ( j + 2 <= n && a[i][j+2] == -1 ) {
		you ( i , j );
		dfs ( i , j + 2 );
	}
	if ( i + 1 <= n && j + 1 <= n && a[i+1][j+1] == -1 ) {
		youxia ( i , j );
		dfs ( i + 1 , j + 1 );
	}
}
void work () {
	int i , j , x , y , z , tmp;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			a[i][j] = -1;
		}
	}
	a[1][1] = 1; a[n][n] = 0;
	dfs ( 1 , 1 );
	for ( i = 1 ; i <= n ; i += 2 ) {
		if ( a[i][i] != a[i+2][i+2] ) break;
	}
	if ( a[i][i+2] == a[i+1][i+1] ) {
		if ( a[i+1][i+1] == a[i+2][i] ) {
			printf ( "? %d %d %d %d\n" , i , i + 1 , i + 1 , i + 2 );
			fflush(stdout);
			scanf ( "%d" , &x );
			printf ( "? %d %d %d %d\n" , i + 1 , i , i + 1 , i + 2 );
			fflush(stdout);
			scanf ( "%d" , &y );
			printf ( "? %d %d %d %d\n" , i , i + 1 , i + 2 , i + 1 );
			fflush(stdout);
			scanf ( "%d" , &z );
			if ( x != y ) {
				printf ( "? %d %d %d %d\n" , i , i , i + 1 , i + 2 );
				fflush(stdout);
				scanf ( "%d" , &tmp );
				a[i+1][i+2] = a[i][i]^1^tmp;
				a[i][i+1] = a[i+1][i+2]^1^x;
				dfs ( i , i + 1 );
				dfs ( i + 1 , i + 2 );
			}
			else {
				if ( x != z ) {
					printf ( "? %d %d %d %d\n" , i , i + 1 , i + 2 , i + 2 );
					fflush(stdout);
					scanf ( "%d" , &tmp );
					a[i][i+1] = a[i+2][i+2]^1^tmp;
					a[i+1][i+2] = a[i][i+1]^1^x;
					dfs ( i , i + 1 );
					dfs ( i + 1 , i + 2 );
				}
				else {
					if ( (z == 1 && a[i+1][i+1] == 1) || (z==0&&a[i+1][i+1]==0)) {
						printf ( "? %d %d %d %d\n" , i , i , i + 2 , i + 1 );
						fflush(stdout);
						scanf ( "%d" , &tmp );
						a[i+2][i+1] = a[i][i]^1^tmp;
						a[i][i+1] = a[i+2][i+1]^1^z;
						dfs ( i + 2 , i + 1 );
						dfs ( i , i + 1 );
					}
					else {
						printf ( "? %d %d %d %d\n" , i , i + 1 , i + 2 , i + 2 );
						fflush(stdout);
						scanf ( "%d" , &tmp );
						a[i][i+1] = a[i+2][i+2]^1^tmp;
						a[i+2][i+1] = a[i][i+1]^1^z;
						dfs ( i + 2 , i + 1 );
						dfs ( i , i + 1 );
					}
				}
			}
		}
		else {
			printf ( "? %d %d %d %d\n" , i , i , i + 2 , i + 1 );
			fflush(stdout);
			scanf ( "%d" , &x );
			a[i+2][i+1] = a[i][i] ^ x ^ 1;
			dfs ( i + 2 , i + 1 );
		}
	}
	else {
		printf ( "? %d %d %d %d\n" , i , i , i + 1 , i + 2 );
		fflush(stdout);
		scanf ( "%d" , &x );
		a[i+1][i+2] = a[i][i] ^ x ^ 1;
		dfs ( i + 1 , i + 2 );
	}
	printf ( "!\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			printf ( "%d" , a[i][j] );
		}
		printf ( "\n" );
	}
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}