#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
char s[230000] , t[230000];
void work () {
	int i , j , k , f;
	scanf ( "%d%d" , &n , &m );
	scanf ( "%s%s" , s + 1 , t + 1 );
	f = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '*' ) f = 1;
	}
	if ( f == 0 ) {
		if ( n != m ) {
			printf ( "NO\n" );
			return ;
		}
		for ( i = 1 ; i <= n ; i++ ) {
			if ( s[i] != t[i] ) {
				printf ( "NO\n" );
				return ;
			}
		}
		printf ( "YES\n" );
	}
	else {
		for ( i = 1 ; i <= n ; i++ ) {
			if ( s[i] == '*' ) break;
			if ( s[i] != t[i] ) {
				printf ( "NO\n" );
				return ;
			}
		}
		i--;
		for ( j = n , k = m ; j >= 1 ; j-- , k-- ) {
			if ( s[j] == '*' ) break;
			if ( s[j] != t[k] ) {
				printf ( "NO\n" );
				return ;
			}
		}
		k++;
		if ( k <= i ) {
			printf ( "NO\n" );
			return ;
		}
		printf ( "YES\n" );
	}
}
int main () {
	work ();
	return 0;
}