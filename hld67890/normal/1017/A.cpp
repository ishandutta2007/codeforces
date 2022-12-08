#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200;
struct node {
	int s , i;
} s[maxn];
int n;
bool cmp ( node x1 , node x2 ) {
	if ( x1.s == x2.s ) return x1.i < x2.i;
	return x1.s > x2.s;
}
void work () {
	int i , a , b , c , d;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d%d%d" , &a , &b , &c , &d );
		s[i].s = a + b + c + d;
		s[i].i = i;
	}
	sort ( s + 1 , s + 1 + n , cmp );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( s[i].i == 1 ) printf ( "%d\n" , i );
	}
}
int main () {
	work ();
	return 0;
}