#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
int n , m , q;
char s[maxn] , t[maxn];
int pre[maxn];
void work () {
	int i , j , l , r;
	scanf ( "%d%d%d" , &n , &m , &q );
	scanf ( "%s%s" , s + 1 , t + 1 );
	for ( i = 1 ; i <= n - m + 1 ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			if ( s[i+j-1] != t[j] ) break;
		}
		if ( j == m + 1 ) pre[i] = 1;
	}
	for ( i = 1 ; i <= n ; i++ ) pre[i] += pre[i-1];
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &l , &r );
		r = r - m + 1;
		if ( r < l ) printf ( "0\n" );
		else printf ( "%d\n" , pre[r] - pre[l-1] );
	}
}
int main () {
	work ();
	return 0;
}