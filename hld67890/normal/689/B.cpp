#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n;
int a[300000] , dis[300000] , f[300000];
queue < int > q;
void work () {
	int i , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		dis[i] = 9999999;
		scanf ( "%d" , &a[i] );
	}
	dis[1] = 0; q.push ( 1 ); f[1] = 1;
	while ( q.size () != 0 ) {
		k = q.front (); q.pop (); f[k] = 0;
		if ( k > 1 )
			if ( dis[k-1] > dis[k] + 1 ) {
				dis[k-1] = dis[k] + 1;
				if ( f[k-1] == 0 ) q.push ( k-1 );
				f[k-1] = 1;
			}
		if ( k < n )
			if ( dis[k+1] > dis[k] + 1 ) {
				dis[k+1] = dis[k] + 1;
				if ( f[k+1] == 0 ) q.push ( k+1 );
				f[k+1] = 1;
			}
		if ( dis[a[k]] > dis[k] + 1 ) {
			dis[a[k]] = dis[k] + 1;
			if ( f[a[k]] == 0 ) q.push ( a[k] );
			f[a[k]] = 1;
		}
	}
	for ( i = 1 ; i < n ; i++ ) printf ( "%d " , dis[i] );
	printf ( "%d\n" , dis[n] );
}
int main () {
	work ();
	return 0;
}