#include <iostream>
#include <stdio.h>

using namespace std;

int n , s;
int hashb[100010], hashs[100010];
void work () {
	int i , k , u , v;
	char z[10];
	scanf ( "%d%d" , &n , &s );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s%d%d" , z , &u , &v );
		if ( z[0] == 'B' ) hashb[u] += v;
		else hashs[u] += v;
	}
	k = 0;
	for ( i = 0 ; i <= 100000 ; i++ ) {
		if ( hashs[i] ) {
			k++;
			if ( k == s )break;
		}
	}
	for ( ; i >= 0 ; i-- ) if ( hashs[i] ) printf ( "S %d %d\n" , i , hashs[i] );
	k = 0;
	for ( i = 100000 ; i >= 0 ; i-- ) {
		if ( hashb[i] ) {
			printf ( "B %d %d\n" , i , hashb[i] );
			k++;
			if ( k == s )break;
		}
	}
}
int main () {
	work ();
	return 0;
}