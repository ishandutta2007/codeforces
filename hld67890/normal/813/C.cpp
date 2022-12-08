#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 220000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n , x;
int dep[maxn] , maxdep[maxn] , fa[maxn];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	maxdep[i] = dep[i];
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dep[j->v] = dep[i] + 1;
		fa[j->v] = i;
		dfs ( j -> v , i );
		maxdep[i] = max ( maxdep[i] , maxdep[j->v] );
	}
}
void work () {
	int i , u , v , t;
	scanf ( "%d%d" , &n , &x );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dep[1] = 1;
	dfs ( 1 , -1 );
	t = (dep[x] - 2) / 2;
	for ( i = 1 ; i <= t ; i++ ) {
		x = fa[x];
	}
	printf ( "%d\n" , (maxdep[x]-1) * 2 );
}
int main () {
	work ();
	return 0;
}