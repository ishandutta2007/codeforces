#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char z[102000];
int m[100][100];
int d[1200] , f[222];
void clear () {
	int i , j;
	for ( i = 1 ; i <= 26 ; i++ ) {
		for ( j = 1 ; j <= 26 ; j++ ) {
			d[i] = f[i] = 0;
			m[i][j] = 0;
		}
	}
}
void work () {
	int i , u , v , d1 , d2 , s;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	clear ();
	for ( i = 1 ; i < n ; i++ ) {
		u = z[i]-'a'+1;
		v = z[i+1]-'a'+1;
		if ( !m[u][v] ) {
			m[u][v] = m[v][u] = 1;
			d[u]++;
			d[v]++;
		}
	}
	if ( n == 1 ) {
		printf ( "YES\n" );
		for ( i = 1 ; i <= 26 ; i++ ) {
			printf ( "%c" , 'a' + i - 1 );
		}
		printf ( "\n" );
		return ;
	}
	d1 = d2 = s = 0;
	for ( i = 1 ; i <= 26 ; i++ ) {
		//printf ( "%d\n" , d[i] );
		if ( d[i] ) {
			if ( d[i] == 1 ) {
				d1++;
				s = i;
			}
			if ( d[i] == 2 ) d2++;
			if ( d[i] > 2 ) {
				printf ( "NO\n" );
				return ;
			}
		}
	}
	if ( d1 != 2 ) {
		printf ( "NO\n" );
		return ;
	}
	printf ( "YES\n" );
	do {
		printf ( "%c" , 'a' + s - 1 );
		f[s] = 1;
		for ( i = 1 ; i <= 26 ; i++ ) {
			if ( m[s][i] && !f[i] ) {
				s = i;
				break;
			} 
		}
	} while ( d[s] != 1 );
	printf ( "%c" , 'a' + s - 1 );
	f[s] = 1;
	for ( i = 1 ; i <= 26 ; i++ ) {
		if ( !f[i] ) printf ( "%c" , 'a' + i - 1 );
	}
	printf ( "\n" );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}