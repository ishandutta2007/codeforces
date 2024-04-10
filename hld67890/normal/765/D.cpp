#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 1200000;
int n;
int a[maxn];
int b[maxn] , c[maxn] , m;
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] != i ) {
			if ( a[a[i]] != a[i] ) {
				printf ( "-1\n" );
				return ;
			}
		}
		else {
			c[++m] = i;
			b[i] = m;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] != i ) b[i] = b[a[i]];
	}
	printf ( "%d\n" , m );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , b[i] , i==n?'\n':' ' );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d%c" , c[i] , i==m?'\n':' ' );
}
int main () {
	work ();
	return 0;
}