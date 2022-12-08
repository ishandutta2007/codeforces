#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
struct node {
	int v , f;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int cnt , ans;
int anss[maxn] , topa;
void add ( int u , int v , int f ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> f = f; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		cnt += j -> f;
		dfs ( j -> v , i );
	}
}
void dfs2 ( int i , int from , int rev , int cancel ) {
	if ( ans > cnt - cancel + rev ) {
		ans = cnt - cancel + rev;
		anss[1] = i;
		topa = 1;
	}
	else {
		if ( ans == cnt - cancel + rev ) {
			anss[++topa] = i;
		}
	}
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( j -> f == 0 ) dfs2 ( j -> v , i , rev + 1 , cancel );
		else dfs2 ( j -> v , i , rev , cancel + 1 );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v , 0 );
		add ( v , u , 1 );
	}
	dfs ( 1 , 0 );
	ans = 999999999;
	dfs2 ( 1 , 0 , 0 , 0 );
	printf ( "%d\n" , ans );
	sort ( anss + 1 , anss + 1 + topa );
	for ( i = 1 ; i <= topa ; i++ ) {
		printf ( "%d%c" , anss[i] , i==topa?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}