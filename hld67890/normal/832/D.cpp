#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120000;
struct tree {
	int v;
	tree *next;
} poolt[NN*2] , *g[NN];
struct node {
	int l , r , s , lazy , cover;
	node *ll , *rr;
} pooln[NN*2] , *t;
int topt , topn;
int n , q;
int siz[NN] , fa[NN] , dep[NN] , son[NN] , top[NN] , w[NN] , index;
int ans;
void add ( int u , int v ) {
	tree *tmp = &poolt[++topt];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	for ( tree *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		fa[j->v] = i;
		dep[j->v] = dep[i] + 1;
		dfs1 ( j -> v , i );
		siz[i] += siz[j->v];
		if ( siz[j->v] > siz[son[i]] ) son[i] = j -> v;
	}
}
void dfs2 ( int i , int from ) {
	w[i] = ++index;
	if ( son[i] ) {
		top[son[i]] = top[i];
		dfs2 ( son[i] , i );
	}
	for ( tree *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> v != son[i] ) {
		top[j->v] = j -> v;
		dfs2 ( j -> v , i );
	}
}
void pushdown ( node *id ) {
	if ( id -> cover ) {
		id -> ll -> cover = 1;
		id -> ll -> s = 0;
		id -> ll -> lazy = 0;
		id -> rr -> cover = 1;
		id -> rr -> s = 0;
		id -> rr -> lazy = 0;
		id -> cover = 0;
	}
	if ( id -> lazy ) {
		id -> ll -> lazy += id -> lazy;
		id -> ll -> s += id -> lazy * (id->ll->r-id->ll->l+1);
		id -> rr -> lazy += id -> lazy;
		id -> rr -> s += id -> lazy * (id->rr->r-id->rr->l+1);
		id -> lazy = 0;
	}
}
void update ( node *id ) {
	id -> s = id -> ll -> s + id -> rr -> s;
}
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) return ;
	int mid = (l+r)/2;
	id -> ll = &pooln[++topn]; id -> rr = &pooln[++topn];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
}
void change ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) {
		id -> lazy += 1;
		id -> s += (id->r-id->l+1);
		return ;
	}
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r );
	else {
		if ( l > mid ) change ( id -> rr , l , r );
		else {
			change ( id -> ll , l , mid );
			change ( id -> rr , mid + 1 , r );
		}
	}
	update ( id );
}
int query ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> s;
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
void changetree ( int u , int v ) {
	while ( top[u] != top[v] ) {
		if ( dep[top[u]] < dep[top[v]] ) swap ( u , v );
		change ( t , w[top[u]] , w[u] );
		u = fa[top[u]];
	}
	if ( dep[u] < dep[v] ) swap ( u , v );
	change ( t , w[v] , w[u] );
}
int querytree ( int u , int v ) {
	int ret = 0;
	while ( top[u] != top[v] ) {
		if ( dep[top[u]] < dep[top[v]] ) swap ( u , v );
		ret += query ( t , w[top[u]] , w[u] );
		u = fa[top[u]];
	}
	if ( dep[u] < dep[v] ) swap ( u , v );
	ret += query ( t , w[v] , w[u] );
	return ret;
}
void solve ( int s , int v , int f ) {
	changetree ( s , v );
	ans = max ( ans , querytree ( s , f ) );
	t -> cover = 1; t -> s = 0; t -> lazy = 0;
}
void work () {
	int i , v , a , b , c;
	scanf ( "%d%d" , &n , &q );
	for ( i = 2 ; i <= n ; i++ ) {
		scanf ( "%d" , &v );
		add ( i , v ); add ( v , i );
	}
	dep[1] = 1;
	dfs1 ( 1 , -1 );
	top[1] = 1;
	dfs2 ( 1 , -1 );
	t = &pooln[++topn];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d%d" , &a , &b , &c );
		ans = 0;
		solve ( a , b , c );
		solve ( b , c , a );
		solve ( c , b , a );
		printf ( "%d\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}