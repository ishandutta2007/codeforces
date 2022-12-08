#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
struct info {
	int n , e;
	int ans , sum;
};
struct tree {
	int l , r;
	info t;
	int cover;
	tree *ll , *rr;
} poolt[maxn*4] , *t;
struct node {
	int v;
	node *next;
} pooln[maxn*2] , *g[maxn];
int topn , topt;
int n , q;
int fa[maxn] , top[maxn] , siz[maxn] , son[maxn] , w[maxn] , index;
void add ( int u , int v ) {
	node *tmp = &pooln[++topn];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	for ( node *j = g[i]; j ; j = j -> next ) if ( j -> v != from ) {
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
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> v != son[i] ) {
		top[j->v] = j -> v;
		dfs2 ( j -> v , i );
	}
}
void pushdown ( tree *id ) {
	if ( id -> cover ) {
		if ( id -> ll ) {
			id -> ll -> t.n = 0; id -> ll -> t.e = -1;
			id -> ll -> t.ans = 0; id -> ll -> t.sum = -(id->ll->r-id->ll->l+1);
			id -> ll -> cover = 1;
		}
		if ( id -> rr ) {
			id -> rr -> t.n = 0; id -> rr -> t.e = -1;
			id -> rr -> t.ans = 0; id -> rr -> t.sum = -(id->rr->r-id->rr->l+1);
			id -> rr -> cover = 1;
		}
		id -> cover = 0;
	}
}
info merge ( info x1 , info x2 ) {
	info y;
	y.sum = x1.sum + x2.sum;
	y.ans = max ( x2.ans , x2.sum + x1.ans );
	return y;
}
void buildtree ( tree *id , int l , int r ) {
	id -> l = l; id -> r = r;
	id -> t.n = 0; id -> t.e = -1; id -> cover = 0; id -> t.ans = 0; id -> t.sum = -1;
	if ( l == r ) return ;
	int mid = (l+r)/2;
	id -> ll = &poolt[++topt]; id -> rr = &poolt[++topt];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void add_ver ( tree *id , int x ) {
	if ( id -> l == id -> r ) {
		id -> t.n++;
		id -> t.sum++;
		id -> t.ans++;
		return ;
	}
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) add_ver ( id -> ll , x );
	else add_ver ( id -> rr , x );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
info querytree ( tree *id , int l , int r ) {
	//printf ( "%d %d %d %d\n" , id -> l , id -> r , l , r );
	if ( id -> l == l && id -> r == r ) return id -> t;
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return querytree ( id -> ll , l , r );
	else {
		if ( l > mid ) return querytree ( id -> rr , l , r );
		else return merge ( querytree ( id -> ll , l , mid ) , querytree ( id -> rr , mid + 1 , r ) );
	}
}
void cover ( tree *id , int l , int r ) {
	//printf ( "%d %d %d %d\n" , id -> l , id -> r , l , r );
	if ( id -> l == l && id -> r == r ) {
		id -> cover = 1;
		id -> t.n = 0; id -> t.e = -1;
		id -> t.ans = 0; id -> t.sum = -(id->r-id->l+1);
		return ;
	}
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) cover ( id -> ll , l , r );
	else {
		if ( l > mid ) cover ( id -> rr , l , r );
		else {
			cover ( id -> ll , l , mid );
			cover ( id -> rr , mid + 1 , r );
		}
	}
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void change_node ( tree *id , int x , int del ) {
	if ( id -> l == id -> r ) {
		id -> t.e += del;
		id -> t.n = 0;
		id -> t.sum = id -> t.e;
		id -> t.ans = 0;
		return ;
	}
	pushdown ( id );
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) change_node ( id -> ll , x , del );
	else change_node ( id -> rr , x , del );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
int query ( int x ) {
	info tmp;
	tmp.ans = tmp.sum = 0;
	while ( x ) {
		tmp = merge ( querytree ( t , w[top[x]] , w[x] ) , tmp );
		x = fa[top[x]];
	}
	return tmp.ans;
}
void work () {
	int i , op , x , tmp;
	scanf ( "%d%d" , &n , &q );
	for ( i = 2 ; i <= n ; i++ ) {
		scanf ( "%d" , &fa[i] );
		add ( fa[i] , i );
	}
	dfs1 ( 1 , -1 );
	top[1] = 1;
	dfs2 ( 1 , -1 );
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d %d\n" , top[i] , w[i] );
	t = &poolt[++topt];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &op , &x );
		if ( op == 1 ) {
			add_ver ( t , w[x] );
		}
		if ( op == 2 ) {
			tmp = query ( x ) - querytree ( t , w[x] , w[x] ).n;
			//if ( tmp < 0 ) tmp = 0;
			//printf ( "%d\n" , tmp );
			if ( siz[x] != 1 ) cover ( t , w[x] + 1 , w[x] + siz[x] - 1 );
			change_node ( t , w[x] , -tmp );
		}
		if ( op == 3 ) {
			//printf ( "%d\n" , query ( x ) );
			if ( query ( x ) > 0 ) printf ( "black\n" );
			else printf ( "white\n" );
		}
	}
}
int main () {
	//freopen ( "in.in" , "r" , stdin );
	//freopen ( "out.txt" , "w" , stdout );
	work ();
	return 0;
}