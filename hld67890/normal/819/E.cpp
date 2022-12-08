#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int k;
int v[100000][6];
void work () {
	int i , j;
	scanf ( "%d" , &n );
	while ( n > 4 ) {
		for ( i = 1 ; i <= n - 4 ; i += 2 ) {
			v[++k][0] = 4;
			v[k][1] = n;
			v[k][2] = i;
			v[k][3] = n - 1;
			v[k][4] = i + 1;
			v[++k][0] = 4;
			v[k][1] = n;
			v[k][2] = i;
			v[k][3] = n - 1;
			v[k][4] = i + 1;
		}
		if ( n % 2 == 1 ) {
			v[++k][0] = 3;
			v[k][1] = n;
			v[k][2] = n - 2;
			v[k][3] = n - 1;
			v[++k][0] = 3;
			v[k][1] = n;
			v[k][2] = n - 2;
			v[k][3] = n - 1;
		}
		else {
			v[++k][0] = 3;
			v[k][1] = n;
			v[k][2] = n-1;
			v[k][3] = n-2;
			v[++k][0] = 3;
			v[k][1] = n;
			v[k][2] = n-1;
			v[k][3] = n-3;
			v[++k][0] = 4;
			v[k][1] = n;
			v[k][2] = n - 3;
			v[k][3] = n - 1;
			v[k][4] = n - 2;
		}
		n -= 2;
	}
	if ( n == 4 ) {
		v[++k][0] = 4;
		v[k][1] = 1;
		v[k][2] = 2;
		v[k][3] = 3;
		v[k][4] = 4;
		v[++k][0] = 4;
		v[k][1] = 1;
		v[k][2] = 3;
		v[k][3] = 2;
		v[k][4] = 4;
		v[++k][0] = 4;
		v[k][1] = 1;
		v[k][2] = 2;
		v[k][3] = 4;
		v[k][4] = 3;
	}
	else {
		v[++k][0] = 3;
		v[k][1] = 1;
		v[k][2] = 2;
		v[k][3] = 3;
		v[++k][0] = 3;
		v[k][1] = 1;
		v[k][2] = 2;
		v[k][3] = 3;
	}
	printf ( "%d\n" , k );
	for ( i = 1 ; i <= k ; i++ ) {
		printf ( "%d" , v[i][0] );
		for ( j = 1 ; j <= v[i][0] ; j++ ) {
			printf ( " %d" , v[i][j] );
		}
		printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}