#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int v;
	node *next;
} pool[210000] , *g[23000];
int top;
int n;
int d[12000];
queue < int > q;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void work () {
	int i , u , v , x;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
		d[u]++; d[v]++;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( d[i] == 1 ) q.push ( i ), d[i] = 0;
	}
	while ( q.size () >= 2 ) {
		u = q.front (); q.pop();
		v = q.front (); q.pop();
		printf ( "? %d %d\n" , u , v );
		fflush(stdout);
		scanf ( "%d" , &x );
		if ( x == u || x == v ) {
			printf ( "! %d\n" , x );
			fflush(stdout);
			return ;
		}
		for ( node *j = g[u] ; j ; j = j -> next ) {
			d[j->v]--;
			if ( d[j->v] == 1 ) {
				q.push ( j -> v );
				d[j->v] = 0; 
			}
		}
		for ( node *j = g[v] ; j ; j = j -> next ) {
			d[j->v]--;
			if ( d[j->v] == 1 ) {
				q.push ( j -> v );
				d[j->v] = 0; 
			}
		}
	}
	printf ( "! %d\n" , q.front () );
	fflush(stdout);
}
int main () {
	work ();
	return 0;
}