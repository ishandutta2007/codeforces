#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int v;
	node *next;
} pool[200000] , *g[200000];
int top;
int n;
int siz[200000];
double ans[200000];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i ) {
	siz[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( !siz[j->v] ) {
		dfs1 ( j -> v );
		siz[i] += siz[j->v];
	}
}
void dfs2 ( int i ) {
	double s = 0;
	for ( node *j = g[i] ; j ; j = j -> next ) s += siz[j->v];
	for ( node *j = g[i] ; j ; j = j -> next ) {
		ans[j->v] = 1 + ans[i] + (s-siz[j->v]) / 2;
		dfs2 ( j -> v );
	}
}
void work () {
	int i , v;
	scanf ( "%d" , &n );
	for ( i = 2 ; i <= n ; i++ ) {
		scanf ( "%d" , &v );
		add ( v , i );
	}
	dfs1 ( 1 );
	ans[1] = 1;
	dfs2 ( 1 );
	for ( i = 1 ; i < n ; i++ ) printf ( "%.1lf " , ans[i] );
	printf ( "%.1lf\n" , ans[n] );
}
int main () {
	work ();
	return 0;
}