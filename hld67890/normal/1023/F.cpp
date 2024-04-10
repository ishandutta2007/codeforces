#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 510000;
struct node {
	int v , f;
	node *next;
} pool[maxn*4] , *g[maxn];
int top;
int n , m , k;
int fu[maxn] , fv[maxn] , fw[maxn];
int gu[maxn] , gv[maxn];
int c1[maxn] , c2[maxn];
int fa[maxn] , dep[maxn] , key[maxn];
long long ans , cnt;
void add ( int u , int v , int f ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> f = f; tmp -> next = g[u]; g[u] = tmp;
}
int find1 ( int x ) {
	int i , t;
	for ( i = x ; c1[i] > 0 ; i = c1[i] ) ;
	while ( c1[x] > 0 ) {
		t = c1[x];
		c1[x] = i;
		x = t;
	}
	return i;
}
void Union1 ( int x , int y ) {
	c1[x] = y;
}
int find2 ( int x ) {
	int i , t;
	for ( i = x ; c2[i] > 0 ; i = c2[i] ) ;
	while ( c2[x] > 0 ) {
		t = c2[x];
		c2[x] = i;
		x = t;
	}
	return i;
}
void Union2 ( int x , int y ) {
	c2[x] = y;
}
void dfs ( int i , int from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dep[j->v] = dep[i] + 1;
		fa[j->v] = i;
		key[j->v] = j -> f;
		dfs ( j -> v , i );
	}
}
void work () {
	int i , x , y;
	scanf ( "%d%d%d" , &n , &k , &m );
	for ( i = 1 ; i <= n ; i++ ) c1[i] = -1;
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%d%d" , &gu[i] , &gv[i] );
		Union1 ( find1 ( gu[i] ) , find1 ( gv[i] ) );
		add ( gu[i] , gv[i] , 1 );
		add ( gv[i] , gu[i] , 1 );
	}
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d%d" , &fu[i] , &fv[i] , &fw[i] );
		if ( find1 ( fu[i] ) != find1 ( fv[i] ) ) {
			Union1 ( find1 ( fu[i] ) , find1 ( fv[i] ) );
			add ( fu[i] , fv[i] , 0 );
			add ( fv[i] , fu[i] , 0 );
		}
	}
	dep[1] = 1;
	dfs ( 1 , -1 );
	for ( i = 1 ; i <= n ; i++ ) c2[i] = -1;
	for( i = 1 ; i <= m ; i++ ) {
		fu[i] = find2 ( fu[i] );
		fv[i] = find2 ( fv[i] );
		while ( fu[i] != fv[i] ) {
			if ( dep[fu[i]] < dep[fv[i]] ) swap ( fu[i] , fv[i] );
			if ( key[fu[i]] == 1 ) {
				ans += (long long)fw[i];
				cnt++;
			}
			Union2 ( fu[i] , find2 ( fa[fu[i]] ) );
			fu[i] = find2 ( fa[fu[i]] );
		}
	}
	if ( cnt == k ) printf ( "%I64d\n" , ans );
	else printf ( "-1\n" );
}
int main () {
	work ();
	return 0;
}