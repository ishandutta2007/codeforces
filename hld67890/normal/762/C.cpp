#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 120000;
int l1 , l2;
char z1[maxn] , z2[maxn];
int a[maxn] , b[maxn];
void work () {
	int i , j , maxi , maxj;
	scanf ( "%s%s" , z1 + 1 , z2 + 1 );
	l1 = strlen ( z1 + 1 ); l2 = strlen ( z2 + 1 );
	j = 1;
	for ( i = 1 ; i <= l2 ; i++ ) a[i] = 9999999;
	for ( i = 1 ; i <= l1 ; i++ ) {
		if ( z1[i] == z2[j] ) {
			a[j++] = i;
		}
	}
	j = l2;
	for ( i = l1 ; i >= 1 ; i-- ) {
		if ( z1[i] == z2[j] ) {
			b[j--] = i;
		}
	}
	b[l2 + 1] = 999999999; a[0] = 0;
	//for ( i = 1 ; i <= l2 ; i++ ) printf ( "%d " , a[i] );
	//printf ( "\n" );
	//for ( i = 1 ; i <= l2 ; i++ ) printf ( "%d " , b[i] );
	//printf ( "\n" );
	j = 1;
	maxi = maxj = -1;
	for ( i = 0 ; i <= l2 ; i++ ) {
		if ( j < i ) j++;
		while ( j <= l2 && a[i] >= b[j] ) j++;
		if ( a[i] != 9999999 ) {
			if ( maxi == -1 || j - i < maxj - maxi ) {
				maxj = j; maxi = i;
			}
		}
	}
	if ( maxi == 0 && maxj == l2 + 1 ) {
		printf ( "-\n" );
		return ;
	}
	//printf ( "%d %d\n" , maxi , maxj );
	if ( maxi == maxj ) maxj++;
	for ( i = 1 ; i <= maxi ; i++ ) printf ( "%c" , z2[i] );
	for ( i = maxj ; i <= l2 ; i++ ) printf ( "%c" , z2[i] );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}