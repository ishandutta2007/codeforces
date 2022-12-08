#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
struct node {
	int a , b;
} s[maxn];
int n , m , q;
int c[maxn*2];
int ans;
bool cmp1 ( node x1 , node x2 ) {
	return x1.a < x2.a;
}
bool cmp2 ( node x1 , node x2 ) {
	return x1.b < x2.b;
}
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ) {
	if ( x == y ) return ;
	c[x] += c[y];
	c[y] = x;
}
void work () {
	int i;
	scanf ( "%d%d%d" , &n , &m , &q );
	for ( i = 1 ; i <= n + m ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &s[i].a , &s[i].b );
		Union ( find ( s[i].a ) , find ( s[i].b + n ) );
	}
	sort ( s + 1 , s + 1 + q , cmp1 );
	for ( i = 2 ; i <= q ; i++ ) {
		if ( s[i].a == s[i-1].a ) {
			Union ( find ( s[i].b + n ) , find ( s[i-1].b + n ) );
		}
	}
	sort ( s + 1 , s + 1 + q , cmp2 );
	for ( i = 2 ; i <= q ; i++ ) {
		if ( s[i].b == s[i-1].b ) {
			Union ( find ( s[i].a ) , find ( s[i-1].a ) );
		}
	}
	for ( i = 1 ; i <= n + m ; i++ ) if ( c[i] < 0 ) ans++;
	printf ( "%d\n" , ans - 1 );
}
int main () {
	work ();
	return 0;
}