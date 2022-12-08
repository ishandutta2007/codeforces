#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int a[510000] , p[510000];
int x[2510000] , y[2510000];
void get ( int u , int v ) {
	m++;
	x[m] = u; y[m] = v;
	swap ( p[a[u]] , p[a[v]] );
	swap ( a[u] , a[v] );
}
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		p[a[i]] = i;
	}
	m = 0;
	for ( i = 2 ; i <= n / 2 ; i++ ) {
		if ( p[i] != i ) {
			if ( p[i] <= n / 2 ) {
				get ( p[i] , n );
				get ( n , i );
			}
			else {
				get ( p[i] , 1 );
				get ( 1 , n );
				get ( n , i );
			}
		}
	}
	for ( i = n / 2 + 1 ; i < n ; i++ ) {
		if ( p[i] != i ) {
			if ( p[i] == 1 ) {
				get ( p[i] , i );
			}
			else {
				get ( p[i] , 1 );
				get ( 1 , i );
			}
		}
	}
	if ( p[1] != 1 ) get ( 1 , n );
	printf ( "%d\n" , m );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d %d\n" , x[i] , y[i] );
}
int main () {
	work ();
	return 0;
}