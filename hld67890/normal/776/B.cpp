#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
int n;
int p[maxn];
void work () {
	int i , j;
	scanf ( "%d" , &n );
	if ( n <= 2 ) {
		printf ( "1\n" );
		for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , 1 , i==n?'\n':' ' );
		return ;
	}
	p[1] = 1;
	for ( i = 2 ; i <= n + 1 ; i++ ) if ( !p[i] ) {
		for ( j = i * 2 ; j <= n + 1 ; j += i ) p[j] = 1;
	}
	printf ( "2\n" );
	for ( i = 2 ; i <= n + 1 ; i++ ) if ( !p[i] ) printf ( "%d%c" , 1 , i==n+1?'\n':' ' );
	else printf ( "%d%c" , 2 , i==n+1?'\n':' ' );
}
int main () {
	work ();
	return 0;
}