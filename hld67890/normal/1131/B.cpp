#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[12000] , b[12000];
int ans;
int solve ( int x , int xx , int y , int yy ) {
	if ( x > y ) {
		swap ( x , y );
		swap ( xx , yy );
	}
	if ( xx <= y ) {
		if ( xx == y ) {
			if ( x < xx ) return 1;
			else return 0;
		}
		else return 0;
	}
	if ( y < xx && xx <= yy ) {
		if ( x == y ) return xx - x;
		else return xx - y + 1;
	}
	if ( x == y ) return yy - y;
	else return yy - y + 1;
}
void work () {
	int i;
	scanf ( "%d" , &n );
	ans = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &a[i] , &b[i] );
		ans += solve ( a[i-1] , a[i] , b[i-1] , b[i] );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}