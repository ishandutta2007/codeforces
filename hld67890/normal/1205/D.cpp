#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1200;
struct so {
	int i , s;
};
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int siz[maxn];
int c[maxn];
int tota;
bool operator < ( so x1 , so x2 ) {
	return x1.s > x2.s;
}
priority_queue < so > q;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs1 ( j -> v , i );
		siz[i] += siz[j->v];
	}
}
int dfs2 ( int i , int from ) {
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( siz[j->v] * 2 > siz[1] ) return dfs2 ( j -> v , i );
	}
	return i;
}
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ) {
	x = find ( x ); y = find ( y );
	if ( x != y ) c[x] = y;
}
void solvea ( int i , int from ) {
	int s = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		printf ( "%d %d %d\n" , i , j -> v , s );
		solvea ( j -> v , i );
		s += siz[j->v];
	}
}
void solveb ( int i , int from ) {
	int s = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		printf ( "%d %d %d\n" , i , j -> v , s * (tota+1) );
		solveb ( j -> v , i );
		s += siz[j->v];
	}
}
void work () {
	int i , root , u , v , ra , rb , nowa , nowb;
	so t1 , t2;
	scanf ( "%d" , &n );
	if ( n == 1 ) return ;
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v );
		add ( v , u );
	}
	dfs1 ( 1 , -1 );
	root = dfs2 ( 1 , -1 );
	dfs1 ( root , -1 );
	for ( node *j = g[root] ; j ; j = j -> next ) {
		c[j->v] = -1;
		t1.i = j -> v; t1.s = siz[j->v];
		q.push ( t1 );
	}
	while ( q.size () >= 3 ) {
		t1 = q.top (); q.pop ();
		t2 = q.top (); q.pop ();
		Union ( t1.i , t2.i );
		t1.s += t2.s;
		q.push ( t1 );
	}
	t1 = q.top (); q.pop ();
	nowa = 1; tota = t1.s; ra = find (t1.i);
	t1 = q.top (); q.pop ();
	nowb = 1; rb = find (t1.i);
	for ( node *j = g[root] ; j ; j = j -> next ) {
		if ( find ( j -> v ) == ra ) {
			printf ( "%d %d %d\n" , root , j -> v , nowa );
			solvea ( j -> v , root );
			nowa += siz[j->v];
		}
		else {
			printf ( "%d %d %d\n" , root , j -> v , nowb * (tota+1) );
			solveb ( j -> v , root );
			nowb += siz[j->v];
		}
	}
}
int main () {
	work ();
	return 0;
}