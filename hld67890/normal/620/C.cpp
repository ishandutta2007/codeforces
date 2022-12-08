#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int n , a[500000] , x[500000] , y[500000] , cnt;
map < int , int > b;
int main () {
	int i , j , k = 1 , c;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( b[a[i]] ) {
			for ( j = k ; j <= i ; j++ ) b[a[j]] = 0;
			x[++cnt] = k;
			y[cnt] = i;
			k = i + 1;
		}
		else b[a[i]] = 1;
	}
	y[cnt] = n;
	if ( cnt ) printf ( "%d\n" , cnt );
	else printf ( "-1" );
	for ( i = 1 ; i <= cnt ; i++ ) printf ( "%d %d\n" , x[i] , y[i] );
	return 0;
}