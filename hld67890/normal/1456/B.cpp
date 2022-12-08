#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120000] , b[120000] , l[120000];
int cnt[12000];
int len ( int x ) {
	int ret = 0;
	while ( x ) {
		ret++;
		x = x / 2;
	}
	return ret;
}
void work () {
	int i , j , k , flag , ans , t1 , t2 , x1 , x2;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		b[i] = a[i];
		l[i] = len ( a[i] );
		cnt[l[i]]++;
	}
	flag = 0;
	for ( i = 1 ; i <= 50 ; i++ ) {
		if ( cnt[i] >= 3 ) {
			printf ( "1\n" );
			return ;
		}
		if ( cnt[i] == 2 ) {
			flag = 1;
		}
	}
	if ( flag == 0 ) {
		printf ( "-1\n" );
		return ;
	}
	ans = 999999;
	for ( i = 1 ; i < n ; i++ ) {
		t1 = 0;
		x1 = 0;
		for ( j = i ; j >= 1 ; j-- ) {
			t1++; x1 ^= a[j];
			t2 = x2 = 0;
			for ( k = i + 1 ; k <= n ; k++ ) {
				t2++;
				x2 ^= a[k];
				if ( x1 > x2 ) {
					//printf ( "%d %d %d %d %d\n" , i , j , k , t1 , t2 );
					ans = min ( ans , t1 + t2 - 2 );
					break;
				}
			}
		}
	}
	if ( ans == 999999 ) ans = -1;
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}