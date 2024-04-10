#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int v;
	node *next;
} pool[320000] , *g[120000];
int top;
int n , m;
int f[120000] , flag;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int c ) {
	f[i] = c;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( !f[j->v] ) dfs ( j -> v , 3-c );
		else {
			if ( f[j->v] == f[i] ) flag = 1;
		}
}
void work () {
	int i , u , v , cnt , last;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	for ( i = 1 ; i <= n ; i++ ) if ( !f[i] ) dfs ( i , 1 );
	if ( flag == 1 ) {
		printf ( "-1\n" );
		return ;
	}
	cnt = 0;
	for ( i = 1 ; i <= n ; i++ ) if ( f[i] == 1 ) cnt++;
	printf ( "%d\n" , cnt );
	last = -1;
	for ( i = 1 ; i <= n ; i++ ) if ( f[i] == 1 ) {
		if ( last != -1 ) printf ( " " );
		printf ( "%d" , i );
		last = 1;
	}
	printf ( "\n" );
	printf ( "%d\n" , n - cnt );
	last = -1;
	for ( i = 1 ; i <= n ; i++ ) if ( f[i] == 2 ) {
		if ( last != -1 ) printf ( " " );
		printf ( "%d" , i );
		last = 1;
	}
}
int main () {
	work ();
	return 0;
}