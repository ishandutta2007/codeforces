#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 220000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int d[maxn] , maxx , maxi;
int col[maxn];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	int s = 0;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		s++;
		while ( s == col[i] || (from != -1 && s == col[from]) ) s++;
		col[j->v] = s;
		dfs ( j -> v , i );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
		d[u]++; d[v]++;
		if ( d[u] > maxx ) {
			maxx = d[u]; maxi = u;
		}
		if ( d[v] > maxx ) {
			maxx = d[v]; maxi = v;
		}
	}
	col[maxi] = 1;
	dfs ( maxi , -1 );
	printf ( "%d\n" , maxx + 1 );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , col[i] , i==n?'\n':' ' );
}
int main () {
	work ();
	return 0;
}