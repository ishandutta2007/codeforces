#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 160000*2;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int c[maxn];
int f;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
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
void Union ( int x , int y , int i ) {
	c[x] = i;
	c[y] = i;
	add ( i , x );
	add ( i , y );
}
void dfs ( int i , int from ) {
	if ( i <= n ) {
		if ( f ) printf ( " " );
		f = 1;
		printf ( "%d" , i );
	}
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n * 2 ; i++ ) c[i] = -1;
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		Union ( find ( u ) , find ( v ) , i + n );
	}
	f = 0;
	dfs ( n + n - 1 , -1 );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}