#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120000] , b[120000];
int tot , now[120000];
void work () {
	int i , x;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		b[n-a[i]]++;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( b[i] % i != 0 ) {
			printf ( "Impossible\n" );
			return ;
		}
	}
	printf ( "Possible\n" );
	tot = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( b[n-a[i]] % (n-a[i]) == 0 ) {
			now[n-a[i]] = ++tot;
		}
		b[n-a[i]]--;
		printf ( "%d%c" , now[n-a[i]] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}