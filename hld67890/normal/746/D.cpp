#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k , a , b;
char z[3];
int s[220000];
void work () {
	int i , j , t;
	scanf ( "%d%d%d%d" , &n , &k , &a , &b );
	z[0] = 'G'; z[1] = 'B';
	if ( a < b ) swap ( z[0] , z[1] ), swap ( a , b );
	t = a / (b+1);
	for ( i = 1 ; i <= b ; i++ ) {
		s[i*2] = 1;
		s[i*2-1] = t;
	}
	s[b*2+1] = t;
	t = a - t * (b+1);
	for ( i = 1 ; i <= b + 1; i++ ) {
		if ( t ) s[i*2-1]++,t--;
	}
	for ( i = 1 ; i <= b * 2 + 1 ; i++ ) if ( s[i] > k ) {
		printf ( "NO\n" );
		return ;
	}
	//for ( i = 1 ; i <= b * 2 + 1 ; i++ ) printf ("%d\n",s[i]);
	for ( i = 1 ; i <= b * 2 + 1 ; i++ ) {
		for ( j = 1 ; j <= s[i] ; j++ ) printf ( "%c" , z[(i%2)^1] );
	}
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}