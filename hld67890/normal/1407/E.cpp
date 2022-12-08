#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
	int v , c;
	node *next;
} pool[510000] , *g[510000];
int top;
int n , m;
int dis[3][510000];
int col[510000] , vis[510000];
int ans;
void add ( int u , int v , int c ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void work () {
	int i , k , u , v , w;
	queue < int > q;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d%d" , &u , &v , &w );
		add ( v , u , w );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		dis[0][i] = dis[1][i] = 999999;
	}
	dis[0][n] = dis[1][n] = 0;
	q.push ( n );
	while ( q.size () ) {
		k = q.front (); q.pop ();
		vis[k] = 1;
		//printf ( "%d %d %d\n" , k , dis[0][k] , dis[1][k] );
		for ( node *j = g[k] ; j ; j = j -> next ) {
			if ( dis[j->c][j->v] == 999999 ) {
				dis[j->c][j->v] = dis[col[k]][k] + 1;
				if ( dis[1-j->c][j->v] != 999999 ) {
					q.push ( j -> v );
					if ( dis[0][j->v] < dis[1][j->v] ) col[j->v] = 1;
					else col[j->v] = 0;
				}
			}
		}
	}
	if ( dis[0][1] == 999999 || dis[1][1] == 999999 ) ans = -1;
	else ans = dis[col[1]][1];
	for ( i = 1 ; i <= n ; i++ ) {
		if ( !vis[i] ) {
			if ( dis[0][i] < dis[1][i] ) col[i] = 1;
			else col[i] = 0;
		}
	}
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d" , col[i] );
	}
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}