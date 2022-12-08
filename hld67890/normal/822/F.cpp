#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120;
struct node {
	int v , i;
	node *next;
} pool[NN*2] , *g[NN];
int top;
int n;
int d[NN];
void add ( int u , int v , int i ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> i = i; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from , double del ) {
	//printf ( "%d %d %.9lf\n" , i , d[i] , del );
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		del += 2.0 / d[i];
		while ( del >= 2.0 ) del -= 2.0;
		printf ( "%d %d %d %d %.9lf\n" , 1 , j -> i , del>=1.0?j->v:i , del>=1.0?i:j->v , del>=1.0?del-1.0:del );
		dfs ( j -> v , i , del + 1.0 );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v , i ); add ( v , u , i );
		d[u]++; d[v]++;
	}
	printf ( "%d\n" , n - 1 );
	dfs ( 1 , -1 , 0 );
}
int main () {
	work ();
	return 0;
}