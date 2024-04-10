#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int U[maxn] , V[maxn];
int col[maxn];
int flag;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from , int c ) {
	if ( col[i] != c ) flag = 0;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) dfs ( j -> v , i , c );
}
bool check ( int x ) {
	flag = 1;
	for ( node *j = g[x] ; j ; j = j -> next ) dfs ( j -> v , x , col[j->v] );
	return flag;
}
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &U[i] , &V[i] );
		add ( U[i] , V[i] ); add ( V[i] , U[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &col[i] );
	for ( i = 1 ; i < n ; i++ ) {
		if ( col[U[i]] != col[V[i]] ) {
			if ( check ( U[i] ) == true ) printf ( "YES\n%d\n" , U[i] );
			else {
				if ( check ( V[i] ) == true ) printf ( "YES\n%d\n" , V[i] );
				else printf ( "NO\n" );
			}
			return ;
		}
	}
	printf ( "YES\n1\n" );
}
int main () {
	work ();
	return 0;
}