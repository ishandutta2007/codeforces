#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int v , c;
	node *next;
} pool[12000] , *g[12000];
int top;
int n;
int tot;
int son[3][12000];
int ansu[12000] , ansv[12000] , ansc[12000];
int root;
int w[12000];
int d[1200];
void add ( int u , int v , int c ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void addans ( int u , int v , int c ) {
	tot++;
	ansu[tot] = u;
	ansv[tot] = v;
	ansc[tot] = c;
}
void dfs ( int i , int from ) {
	if ( d[i] == 1 ) {
		son[0][i] = 1;
		son[1][i] = i;
	}
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		if ( son[0][j->v] >= 1 && son[0][i] < 2 ) {
			son[++son[0][i]][i] = son[1][j->v];
		}
		w[i] += w[j->v];
		j -> c -= w[j->v];
		if ( j -> c != 0 ) {
			if ( son[0][j->v] == 1 ) {
				addans ( root , son[1][j->v] , j -> c );
				w[i] += j -> c;
				j -> c = 0;
			}
			else {
				addans ( root , son[1][j->v] , j -> c / 2 );
				addans ( root , son[2][j->v] , j -> c / 2 );
				addans ( son[1][j->v] , son[2][j->v] , -(j->c/2) );
				w[i] += j -> c;
				j -> c = 0;
			}
		}
	}
}
void work () {
	int i , u , v , c;
	scanf ( "%d" , &n );
	for ( i = 1  ; i < n ; i++ ) {
		scanf ( "%d%d%d" , &u , &v , &c );
		add ( u , v , c );
		add ( v , u , c );
		d[u]++; d[v]++;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( d[i] == 2 ) {
			printf ( "NO\n" );
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( d[i] == 1 ) {
			root = i;
			dfs ( i , -1 );
			break;
		}
	}
	printf ( "YES\n" );
	printf ( "%d\n" , tot );
	for ( i = 1 ; i <= tot ; i++ ) {
		printf ( "%d %d %d\n" , ansu[i] , ansv[i] , ansc[i] );
	}
}
int main () {
	work ();
	return 0;
}