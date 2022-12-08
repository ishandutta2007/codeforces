#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 820;
int n;
int a[maxn];
int dp[maxn][maxn][3];
int v[maxn][maxn];
int gcd ( int x , int y ) {
	int t;
	if ( x < y ) swap ( x , y );
	while ( y ) {
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}
int check ( int l , int r , int k ) {
	if ( l > r ) return 1;
	return dp[l][r][k];
}
void work () {
	int i , j , k , l , r;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ )
		for ( j = 1 ; j <= n ; j++ )
			if ( gcd ( a[i] , a[j] ) > 1 ) v[i][j] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n - i + 1 ; j++ ) {
			l = j; r = i + j - 1;
			for ( k = l ; k <= r ; k++ ) {
				if ( v[l-1][k] && check ( l , k - 1 , 1 ) && check ( k + 1 , r , 0 ) ) dp[l][r][0] = 1;
				if ( v[k][r+1] && check ( l , k - 1 , 1 ) && check ( k + 1 , r , 0 ) ) dp[l][r][1] = 1;
			}
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( check ( 1 , i - 1 , 1 ) && check ( i +1 , n , 0 ) ) {
			printf ( "Yes\n" );
			return ;
		}
	}
	printf ( "No\n" );
}
int main () {
	work ();
	return 0;
}