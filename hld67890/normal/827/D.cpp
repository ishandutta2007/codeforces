#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 210000;
struct edge {
	int u , v , c , i;
} e[NN];
struct tree {
	int v , c;
	tree *next;
} poolt[NN*2] , *g[NN];
struct node {
	int l , r , minn;
	node *ll , *rr;
} pooln[NN*2] , *t;
int topt , topn;
int n , m;
int c[NN] , dep[NN];
int siz[NN] , fa[NN] , son[NN] , top[NN] , w[NN] , index;
int go[20][NN] , gomax[20][NN];
int ans[NN];
bool cmp ( edge x1 , edge x2 ) {
	return x1.c < x2.c;
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
	c[x] = y;
}
void add ( int u , int v , int c ) {
	tree *tmp = &poolt[++topt];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	for ( tree *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dep[j->v] = dep[i] + 1;
		fa[j->v] = i;
		go[0][j->v] = i;
		gomax[0][j->v] = j -> c;
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
int getlca ( int u , int v ) {
	int i , ret;
	ret = 0;
	if ( dep[u] < dep[v] ) swap ( u , v );
	for ( i = 17 ; i >= 0 ; i-- ) if ( dep[go[i][u]] >= dep[v] ) {
		ret = max ( ret , gomax[i][u] );
		u = go[i][u];
	}
	for ( i = 17 ; i >= 0 ; i-- ) if ( go[i][u] != go[i][v] ) {
		ret = max ( ret , max ( gomax[i][u] , gomax[i][v] ) );
		u = go[i][u]; v = go[i][v];
	}
	if ( u != v ) {
		ret = max ( ret , max ( gomax[0][u] , gomax[0][v] ) );
	}
	return ret;
}
void pushdown ( node *id ) {
	if ( id -> minn != 2147483647 ) {
		id -> ll -> minn = min ( id -> ll -> minn , id -> minn );
		id -> rr -> minn = min ( id -> rr -> minn , id -> minn );
		id -> minn = 2147483647;
	}
}
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r; id -> minn = 2147483647;
	if ( l == r ) {
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pooln[++topn]; id -> rr = &pooln[++topn];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
}
void change ( node *id , int l , int r , int x ) {
	if ( id -> l == l && id -> r == r ) {
		id -> minn = min ( id -> minn , x );
		return ;
	}
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , x );
	else {
		if ( l > mid ) change ( id -> rr , l , r , x );
		else {
			change ( id -> ll , l , mid , x );
			change ( id -> rr , mid + 1 , r , x );
		}
	}
}
int query ( node *id , int l ) {
	if ( id -> l == id -> r ) return id -> minn;
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( l <= mid ) return query ( id -> ll , l );
	else return query ( id -> rr , l );
}
void changetree ( int u , int v , int x ) {
	while ( top[u] != top[v] ) {
		if ( dep[top[u]] < dep[top[v]] ) swap ( u , v );
		change ( t , w[top[u]] , w[u] , x );
		u = fa[top[u]];
	}
	if ( u == v ) return ;
	if ( dep[u] < dep[v] ) swap ( u , v );
	change ( t , w[son[v]] , w[u] , x );
}
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d%d" , &e[i].u , &e[i].v , &e[i].c );
		e[i].i = i;
	}
	sort ( e + 1 , e + m + 1 , cmp );
	for ( i = 1 ; i <= n ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= m ; i++ ) {
		//printf ( "%d %d %d %d\n" , e[i].u , e[i].v , find ( e[i].u ) , find ( e[i].v ));
		if ( find ( e[i].u ) != find ( e[i].v ) ) {
			Union ( find ( e[i].u ) , find ( e[i].v ) );
			add ( e[i].u , e[i].v , e[i].c );
			add ( e[i].v , e[i].u , e[i].c );
			e[i].c = 2147483647;
		}
	}
	dep[1] = 1;
	dfs1 ( 1 , -1 );
	top[1] = 1;
	dfs2 ( 1 , -1 );
	t = &pooln[++topn];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= 17 ; i++ ) for ( j = 1 ; j <= n ; j++ ) {
		go[i][j] = go[i-1][go[i-1][j]];
		gomax[i][j] = max ( gomax[i-1][j] , gomax[i-1][go[i-1][j]] );
	}
	for ( i = 1 ; i <= m ; i++ ) {
		if ( e[i].c != 2147483647 ) {
			ans[e[i].i] = getlca ( e[i].u , e[i].v ) - 1;
			changetree ( e[i].u , e[i].v , e[i].c );
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		if ( e[i].c == 2147483647 ) {
			if ( dep[e[i].u] > dep[e[i].v] ) ans[e[i].i] = query ( t , w[e[i].u] ) - 1;
			else ans[e[i].i] = query ( t , w[e[i].v] ) - 1;
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		if ( ans[i] == 2147483646 ) printf ( "-1" );
		else printf ( "%d" , ans[i] );
		printf ( "%c" , i==m?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}