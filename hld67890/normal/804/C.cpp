#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 510000;
struct link {
	int c;
	link *next;
} pooll[maxn*2] , *ll[maxn];
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int topl , top;
int n , m;
int s;
map < int , int > fre;
map < int , int >::iterator it;
int maxx , maxi;
int col[maxn];
int stack[maxn] , tops;
void addc ( int i , int x ) {
	link *tmp = &pooll[++topl];
	tmp -> c = x; tmp -> next = ll[i]; ll[i] = tmp;
}
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	for ( link *j = ll[i] ; j ; j = j -> next ) {
		if ( col[j->c] ) fre.erase ( col[j->c] );
	}
	it = fre.begin ();
	tops = 0;
	//printf ( "%d %d\n" , i , it -> first );
	for ( link *j = ll[i] ; j ; j = j -> next ) {
		if ( !col[j->c] ) {
			col[j->c] = it -> first;
			it++;
		}
		else stack[++tops] = col[j -> c];
	}
	for ( int j = 1 ; j <= tops ; j++ ) fre[stack[j]] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
	}
}
void work () {
	int i , j , u , v , a;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &s );
		if ( i == 1 || maxx < s ) {
			maxx = s;
			maxi = i;
		}
		for ( j = 1 ; j <= s ; j++ ) {
			scanf ( "%d" , &a );
			addc ( i , a );
		}
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	for ( i = 1 ; i <= maxx ; i++ ) fre[i] = 1;
	dfs ( maxi , -1 );
	if ( maxx == 0 ) maxx = 1;
	for ( i = 1 ; i <= m ; i++ ) if ( !col[i] ) col[i] = 1;
	printf ( "%d\n" , maxx );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d%c" , col[i] , i==m?'\n':' ' );
}
int main () {
	work ();
	return 0;
}