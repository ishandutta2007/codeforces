#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
char a[210000];
char b[210000];
int oa[210000] , ob[210000];
int ans;
void add ( int i , int j ) {
	ans++;
	oa[ans] = i;
	ob[ans] = j;
}
void output () {
	int i;
	printf ( "YES\n" );
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= ans ; i++ ) {
		printf ( "%d %d\n" , oa[i] , ob[i] );
	}
}
void work () {
	int i;
	scanf ( "%d" , &n );
	scanf ( "%s" , a + 1 );
	scanf ( "%s" , b + 1 );
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( (a[1]==b[1]) != (a[i]==b[i]) ) {
			printf ( "NO\n" );
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( a[i] == '1' ) {
			add ( i , i );
			if ( i != 1 ) {
				if ( b[1] == '1' ) b[1] = '0';
				else b[1] = '1';
			}
		}
	}
	if ( b[1] == '1' ) {
		add ( 1 , 1 );
		add ( 2 , 2 );
		add ( 1 , 2 );
	}
	output ();
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}