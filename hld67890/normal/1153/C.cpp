#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
char s[310000];
int l , r , que , tol , sum;
int abss ( int x ) {
	if ( x < 0 ) return -x;
	return x;
}
void work () {
	int i;
	scanf ( "%d" , &n );
	scanf ( "%s" , s + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '(' ) l++;
		if ( s[i] == ')' ) r++;
		if ( s[i] == '?' ) que++;
	}
	if ( n % 2 == 1 || abss ( r - l ) > que ) {
		printf ( ":(\n" );
		return ;
	}
	if ( r > l ) {
		que -= r - l;
		tol += r - l;
	}
	else que -= l - r;
	tol += que / 2;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '?' ) {
			if ( tol ) {
				s[i] = '(';
				tol--;
			}
			else s[i] = ')';
		}
	}
	sum = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i] == '(' ) sum++;
		else sum--;
		if ( i != n ) {
			if ( sum <= 0 ) {
				printf ( ":(\n" );
				return ;
			}
		}
	}
	printf ( "%s" , s + 1 );
}
int main () {
	work ();
	return 0;
}