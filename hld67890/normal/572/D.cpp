#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int dp[5010][5010] , a[300010] , del[300010];
void work () {
	int i , j , l1 , l2 , p1 , p2;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	sort ( a + 1 , a + 1 + n );
	for ( i = 1 ; i <= n ; i++ ) del[i] = a[i] - a[i - 1];
	l1 = n % k; l2 = k - l1;
	p1 = n / k + 1; p2 = n / k;
	for ( i = 0 ; i <= l1 ; i++ ) {
		for ( j = 0 ; j <= l2 ; j++ ) {
			if ( i != 0 || j != 0 )
				dp[i][j] = max ( i!=0?dp[i-1][j]:0  , j!=0?dp[i][j-1]:0 ) + del[i*p1+j*p2+1];
		}
	}
	printf ( "%d\n" , a[n] - a[1] - dp[l1][l2] );
}
int main () {
	work ();
	return 0;
}