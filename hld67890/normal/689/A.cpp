#include <iostream>
#include <stdio.h>

using namespace std;

int u[12] , d[12] , l[12] , r[12];
int main () {
	int n , i , f1 , f2;
	char z[12];
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	u[1] = u[2] = u[3] = -1;
	d[7] = d[0] = d[9] = -1;
	l[1] = l[4] = l[7] = -1;
	r[3] = r[6] = r[9] = -1;
	l[0] = r[0] = -1;
	f2 = 0;
	f1 = 1;
	for ( i = 1 ; i <= n ; i++ ) if ( u[z[i]-'0'] == -1 ) f1 = 0;
	if ( f1 ) f2 = 1;
	f1 = 1;
	for ( i = 1 ; i <= n ; i++ ) if ( d[z[i]-'0'] == -1 ) f1 = 0;
	if ( f1 ) f2 = 1;
	f1 = 1;
	for ( i = 1 ; i <= n ; i++ ) if ( l[z[i]-'0'] == -1 ) f1 = 0;
	if ( f1 ) f2 = 1;
	f1 = 1;
	for ( i = 1 ; i <= n ; i++ ) if ( r[z[i]-'0'] == -1 ) f1 = 0;
	if ( f1 ) f2 = 1;
	if ( f2 == 1 ) printf ( "NO\n" );
	else printf ( "YES\n" );
	return 0;
}