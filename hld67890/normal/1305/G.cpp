#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[310000] , b[310000] , c[320000];
int flag;
long long ans;
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] >= 0 ; i = c[i] ) ;
	while ( c[x] >= 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ) {
	c[x] = y;
}
void work () {
	int i , j , t;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		ans -= a[i];
		b[a[i]]++;
	}
	for ( i = 0 ; i <= 280000 ; i++ ) {
		c[i] = -1;
	}
	for ( i = (1<<18) - 1 ; i >= 1 ; i-- ) {
		for ( j = i ; j > 0 ; j = (j-1) & i ) {
			if ( b[i^j] && b[j] && find ( i - j ) != find ( j ) ) {
				ans += (long long)i * (b[i^j] + b[j] - 1);
				b[i^j] = b[j] = 1;
				//printf ( "%d %d\n" , i , j );
				Union ( find ( i ^ j ) , find ( j ) );
			}
		}
		if ( b[i] && find ( 280000 ) != find ( i ) ) {
			ans += (long long)i * b[i];
			Union ( find ( 280000 ) , find ( i ) );
		}
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}