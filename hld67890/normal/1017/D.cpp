#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m , q;
int a[20];
int cnt[12000];
int sum[12000];
int ans[11000][120];
char z[122];
void work () {
	int i , j , k , x , t , s;
	scanf ( "%d%d%d" , &n , &m , &q );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%s" , z + 1 );
		s = 0; t = 1;
		for ( j = n ; j >= 1 ; j-- ) {
			if ( z[j] == '1' ) s += t;
			t <<= 1;
		}
		cnt[s]++;
	}
	for ( i = 0 ; i < (1<<n) ; i++ ) {
		s = 0; x = i; t = n;
		while ( x ) {
			if ( x % 2 == 1 ) s += a[t];
			t--; x >>= 1;
		}
		sum[i] = s;
		//printf ( "#%d\n" , cnt[i] );
	}
	for ( i = 0 ; i < (1<<n) ; i++ ) {
		s = 0;
		for ( j = 0 ; j < (1<<n) ; j++ ) {
			if ( sum[(1<<n)-1-(i^j)] <= 100 )
				ans[i][sum[(1<<n)-1-(i^j)]] += cnt[j];
			//printf ( "@%d %d %d %d\n" , i , j , sum[(1<<n)-1-(i^j)] , ans[i][sum[(1<<n)-1-(i^j)]] );
		}
		for ( j = 1 ; j <= 100 ; j++ ) ans[i][j] += ans[i][j-1];
	}
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s%d" , z + 1 , &k );
		s = 0; t = 1;
		for ( j = n ; j >= 1 ; j-- ) {
			if ( z[j] == '1' ) s += t;
			t <<= 1;
		}
		printf ( "%d\n" , ans[s][k] );
	}
}
int main () {
	work ();
	return 0;
}