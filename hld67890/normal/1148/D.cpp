#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int a , b , i;
} s[310000] , t[310000];
int n , n1 , n2;
bool cmp1 ( node x1 , node x2 ) {
	return x1.b > x2.b;
}
bool cmp2 ( node x1 , node x2 ) {
	return x1.b < x2.b;
}
void work () {
	int i , x , y;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &x , &y );
		if ( x < y ) {
			n1++;
			s[n1].a = x;
			s[n1].b = y;
			s[n1].i = i;
		}
		else {
			n2++;
			t[n2].a = x;
			t[n2].b = y;
			t[n2].i = i;
		}
	}
	sort ( s + 1 , s + 1 + n1 , cmp1 );
	sort ( t + 1 , t + 1 + n2 , cmp2 );
	if ( n1 >= n2 ) {
		printf ( "%d\n" , n1 );
		for ( i = 1 ; i <= n1 ; i++ ) {
			printf ( "%d%c" , s[i].i , i==n1?'\n':' ' );
		}
	}
	else {
		printf ( "%d\n" , n2 );
		for ( i = 1 ; i <= n2 ; i++ ) {
			printf ( "%d%c" , t[i].i , i==n2?'\n':' ' );
		}
	}
}
int main () {
	work ();
	return 0;
}