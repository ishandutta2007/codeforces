#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120;
int n , m;
int l[NN] , a[NN] , use[NN];
void work () {
	int i , j , f , tmp;
	scanf ( "%d%d" , &n , &m );
	f = 1;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &l[i] );
		if ( i != 1 ) {
			tmp = (l[i]-l[i-1]+n-1) % n + 1;
			if ( a[l[i-1]] != 0 && a[l[i-1]] != tmp ) {
				f = 0;
			}
			a[l[i-1]] = tmp;
			use[tmp] = 1;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] == 0 ) {
			for ( j = 1 ; j <= n ; j++ ) {
				if ( !use[j] ) break;
			}
			use[j] = 1;
			a[i] = j;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = i + 1 ; j <= n ; j++ ) {
		if ( a[i] == a[j] ) f = 0;
	}
	if ( f == 0 ) {
		printf ( "-1\n" );
		return ;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] == 0 ) printf ( "1" );
		else printf ( "%d" , a[i] );
		if ( i == n ) printf ( "\n" );
		else printf ( " " );
	}
}
int main () {
	work ();
	return 0;
}