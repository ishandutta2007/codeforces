#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node {
	int v , c;
	node *next;
} pool[20000] , *g[1200];
int top;
int n , m;
int u[6000] , v[6000];
int mark[1200] , vis[2000];
int dis[1200] , f[1200] , t[1200];
void dfs ( int i ) {
	vis[i] = 1;
	if ( i == n ) {
		mark[i] = 1;
		return ;
	}
	for ( node *j = g[i] ; j ; j = j -> next )
		if ( j -> c > 0 ) {
			if ( !vis[j->v] ) dfs ( j -> v );
			if ( mark[j->v] ) mark[i] = 1;
		}
}
void add ( int u , int v , int c , int i ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void spfa () {
	int i , k;
	queue < int > q;
	for ( i = 1 ; i <= n ; i++ ) dis[i] = 9999999, f[i] = t[i] = 0;
	dis[1] = 0; f[1] = t[1] = 1;
	q.push ( 1 );
	while ( q.size () != 0 ) {
		k = q.front (); q.pop ();
		f[k] = 0; t[k]++;
		if ( t[k] > n ) {
			printf ( "No\n" );
			return ;
		}
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( mark[j->v] && dis[j->v] > dis[k] + j -> c ) {
				dis[j->v] = dis[k] + j -> c;
				if ( !f[j->v] ) q.push ( j -> v );
				f[j->v] = 1;
			}
	}
	printf ( "Yes\n" );
	for ( i = 1 ; i <= m ; i++ ) if ( dis[v[i]] - dis[u[i]] == 1 ) printf ( "1\n" );
	else printf ( "2\n" );
}
void work () {
	int i;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u[i] , &v[i] );
		add ( u[i] , v[i] , 2 , i ); add ( v[i] , u[i] , -1 , i );
	}
	dfs ( 1 );
	spfa ();
}
int main () {
	work ();
	return 0;
}