#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int p[1001];
bool check ( int i , int j ) {
	while ( !(i % j) ) i = i / j;
	return (i==1);
}
void work () {
	int i , j , ans = 0;
	scanf ( "%d" , &n );
	p[0] = p[1] = 1;
	for ( i = 2 ; i <= n ; i++ )
		if ( !p[i] ) for ( j = i + i ; j <= n ; j += i ) p[j] = 1;
	for ( i = 2 ; i <= n ; i++ ) {
		for ( j = 2 ; j <= n ; j++ )
			if ( !p[j] && check ( i , j ) ) { ans++; break; }
	}
	printf ( "%d\n" , ans );
	for ( i = 2 ; i <= n ; i++ ) {
		for ( j = 2 ; j <= n ; j++ )
			if ( !p[j] && check ( i , j ) ) {
				printf ( "%d " , i );
				break;
			}
	}
}
int main () {
	work ();
	return 0;
}