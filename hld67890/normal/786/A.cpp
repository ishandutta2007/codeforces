#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 7100;
int n;
int k1 , k2;
int a[maxn] , b[maxn];
int d[3][maxn] , in[3][maxn];
int vis[3][maxn];
queue < int > q;
void work () {
	int i , k;
	scanf ( "%d" , &n );
	scanf ( "%d" , &k1 );
	for ( i = 1 ; i <= k1 ; i++ ) scanf ( "%d" , &a[i] );
	scanf ( "%d" , &k2 );
	for ( i = 1 ; i <= k2 ; i++ ) scanf ( "%d" , &b[i] );
	d[1][1] = -1; d[2][1] = -1;
	q.push ( 1 ); q.push ( -1 );
	while ( q.size () ) {
		k = q.front (); q.pop ();
		if ( k > 0 ) {
			if ( vis[1][k] ) continue;
		}
		else if ( vis[2][-k] ) continue;
		if ( k > 0 ) vis[1][k] = 1;
		else vis[2][-k] = 1;
		//printf ( "%d\n" , k );
		//for ( i = 1 ; i <= n ; i++ ) printf ( "%d " , d[1][i] );
		//printf ( "\n" );
		//for ( i = 1 ; i <= n ; i++ ) printf ( "%d " , d[2][i] );
		//printf ( "\n" );
		if ( k > 0 ) {
			if ( d[1][k] == 1 ) {
				for ( i = 1 ; i <= k2 ; i++ ) {
					//printf ( "%d %d\n" , i , (k-b[i]+n-1)%n+1 );
					if ( d[2][(k-b[i]+n-1)%n+1] == 0 )
						in[2][(k-b[i]+n-1)%n+1]++;
					if ( in[2][(k-b[i]+n-1)%n+1] == k2 ) {
						d[2][(k-b[i]+n-1)%n+1] = -1;
						q.push ( - ( (k-b[i]+n-1)%n+1 ) );
					}
				}
			}
			else {
				for ( i = 1 ; i <= k2 ; i++ ) {
					d[2][(k-b[i]+n-1)%n+1] = 1;
					q.push ( - ( (k-b[i]+n-1)%n+1 ) );
				}
			}
		}
		else {
			k = -k;
			if ( d[2][k] == 1 ) {
				for ( i = 1 ; i <= k1 ; i++ ) {
					if ( d[1][(k-a[i]+n-1)%n+1] == 0 )
						in[1][(k-a[i]+n-1)%n+1]++;
					if ( in[1][(k-a[i]+n-1)%n+1] == k1 ) {
						d[1][(k-a[i]+n-1)%n+1] = -1;
						q.push ( ( (k-a[i]+n-1)%n+1 ) );
					}
				}
			}
			else {
				for ( i = 1 ; i <= k1 ; i++ ) {
					//printf ( "##%d %d\n" , k , (k-a[i]+n-1)%n+1 );
					d[1][(k-a[i]+n-1)%n+1] = 1;
					q.push ( ( (k-a[i]+n-1)%n+1 ) );
				}
			}
		}
	}
	for ( i = 2 ; i <= n ; i++ ) {
		if ( d[1][i] == -1 ) printf ( "Lose" );
		if ( d[1][i] == 0 ) printf ( "Loop" );
		if ( d[1][i] == 1 ) printf ( "Win" );
		printf ( "%c" , i==n?'\n':' ' );
	}
	for ( i = 2 ; i <= n ; i++ ) {
		if ( d[2][i] == -1 ) printf ( "Lose" );
		if ( d[2][i] == 0 ) printf ( "Loop" );
		if ( d[2][i] == 1 ) printf ( "Win" );
		printf ( "%c" , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}