#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120000;
int n , q , c;
int x[NN] , y[NN] , s[NN];
int ans[20][120][120];
void work () {
	int i , j , k , x1 , y1 , x2 , y2 , t;
	scanf ( "%d%d%d" , &n , &q , &c );
	c++;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d%d" , &x[i] , &y[i] , &s[i] );
	}
	for ( i = 0 ; i < c ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			ans[i][x[j]][y[j]] += (s[j]+i) % c;
		}
		for ( j = 1 ; j <= 100 ; j++ ) {
			for ( k = 1 ; k <= 100 ; k++ ) {
				ans[i][j][k] += ans[i][j-1][k] + ans[i][j][k-1] - ans[i][j-1][k-1];
			}
		}
	}
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d%d%d%d" , &t , &x1 , &y1 , &x2 , &y2 );
		t %= c;
		printf ( "%d\n" , ans[t][x2][y2]-ans[t][x1-1][y2]-ans[t][x2][y1-1]+ans[t][x1-1][y1-1] );
	}
}
int main () {
	work ();
	return 0;
}