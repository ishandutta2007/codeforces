#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 410000;
struct intree {
	int v;
	intree *next;
} pooli[maxn*2] , *g[maxn];
struct node {
	int siz , ind;
	int rev;
	int ch[3] , fa;
} p[maxn];
struct tree {
	int l , r , s;
	tree *ll , *rr;
} poolt[maxn*2] , *t;
int topt , topi;
int n , q;
int maxx[maxn] , fa[maxn];
int index;
void add ( int u , int v ) {
	intree *tmp = &pooli[++topi];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void buildtree ( tree *id , int l , int r ) {
	id -> l = l; id -> r = r;
	id -> s = 0;
	if ( l == r ) {
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &poolt[++topt]; id -> rr = &poolt[++topt];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
}
void change ( tree *id , int x , int y ) {
	if ( id -> l == id -> r ) {
		id -> s = y;
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) change ( id -> ll , x , y );
	else change ( id -> rr , x , y );
	id -> s = id -> ll -> s + id -> rr -> s;
}
int query ( tree *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> s;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
void cut ( int x , int kind ) {
	int y = p[x].ch[kind];
	p[y].ind = p[x].ind;
	p[x].ind = 0;
	//printf ( "@@%d %d\n" , p[y].ind , p[y].siz );
	change ( t , p[y].ind , p[y].siz );
	p[x].siz -= p[y].siz;
	p[y].fa *= -1;
	p[x].ch[kind] = 0;
}
void down ( int x ) {
	if ( p[x].fa > 0 ) down ( p[x].fa );
	if ( p[x].rev ) {
		p[x].rev = 0;
		if ( p[x].ch[0] ) {
			p[p[x].ch[0]].rev ^= 1;
			swap ( p[p[x].ch[0]].ch[0] , p[p[x].ch[0]].ch[1] );
		}
		if ( p[x].ch[1] ) {
			p[p[x].ch[1]].rev ^= 1;
			swap ( p[p[x].ch[1]].ch[0] , p[p[x].ch[1]].ch[1] );
		}
	}
}
void rotate ( int x , int kind ) {
	int y = p[x].fa;
	if ( p[y].fa > 0 ) p[p[y].fa].ch[y==p[p[y].fa].ch[1]] = x;
	p[x].fa = p[y].fa;
	p[y].ch[kind] = p[x].ch[kind^1];
	if ( p[x].ch[kind^1] ) p[p[x].ch[kind^1]].fa = y;
	p[y].fa = x;
	p[x].ch[kind^1] = y;
	p[y].siz = p[p[y].ch[0]].siz + p[p[y].ch[1]].siz + 1;
	p[x].siz = p[p[x].ch[0]].siz + p[p[x].ch[1]].siz + 1;
	p[x].ind = p[y].ind; p[y].ind = 0;
}
void splay ( int x ) {
	down ( x );
	for ( ; p[x].fa > 0 ; rotate ( x , x == p[p[x].fa].ch[1] ) )
		if ( p[p[x].fa].fa > 0 && (x==p[p[x].fa].ch[1]) == (p[x].fa==p[p[p[x].fa].fa].ch[1]) )
			rotate ( p[x].fa , x==p[p[x].fa].ch[1] );
}
void access ( int x ) {
	index++;
	splay ( x );
	int y = p[x].ch[1];
	if ( y ) {
		cut ( x , 1 );
	}
	else change ( t , p[x].ind , 0 );
	while ( p[x].fa != 0 ) {
		splay ( -p[x].fa );
		if ( p[-p[x].fa].ch[1] ) cut ( -p[x].fa , 1 );
		else change ( t , p[-p[x].fa].ind , 0 );
		p[x].fa *= -1;
		p[p[x].fa].ch[1] = x;
		splay ( x );
	}
	p[x].ind = index;
	change ( t , index , p[x].siz );
}
int when ( int x ) {
	int s1 , s2;
	splay ( x );
	if ( p[x].ind == 1 ) s1 = 0;
	else s1 = query ( t , 1 , p[x].ind - 1 );
	s2 = p[p[x].ch[1]].siz;
	//printf ( "###%d %d %d %d\n" , x , p[x].ind , s1 , s2 );
	return s1 + s2;
}
void dfs ( int i , int from ) {
	maxx[i] = i;
	for ( intree *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		fa[j->v] = i;
		dfs ( j -> v , i );
		maxx[i] = max ( maxx[i] , maxx[j->v] );
	}
	for ( intree *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( maxx[i] == maxx[j->v] ) {
			//printf ( "%d  %d\n" , i , j -> v );
			splay ( j -> v );
			p[i].ch[1] = j -> v;
			p[j->v].fa = i;
			p[i].siz += p[j->v].siz;
		}
	}
}
void work () {
	int i , u , v;
	char op[122];
	scanf ( "%d%d" , &n , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		p[i].siz = 1;
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dfs ( n , -1 );
	t = &poolt[++topt];
	buildtree ( t , 1 , n + q );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( i == maxx[i] ) {
			index++;
			splay ( i );
			p[i].ind = index;
			change ( t , index , p[i].siz );
			//printf ( "!!%d %d %d\n" , index , i , p[i].siz );
		}
		if ( i != n && maxx[i] != maxx[fa[i]] ) {
			splay ( i );
			p[i].fa = -fa[i];
		}
	}
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s" , op + 1 );
		if ( op[1] == 'u' ) {
			scanf ( "%d" , &u );
			access ( u );
			p[u].rev ^= 1;
			swap ( p[u].ch[0] , p[u].ch[1] );
		}
		if ( op[1] == 'w' ) {
			scanf ( "%d" , &u );
			printf ( "%d\n" , when ( u ) + 1 );
		}
		if ( op[1] == 'c' ) {
			scanf ( "%d%d" , &u , &v );
			if ( when ( u ) < when ( v ) ) printf ( "%d\n" , u );
			else printf ( "%d\n" , v );
		}
		/*for ( int j = 1 ; j <= n ; j++ ) {
			printf ( " fa%d l%d r%d s%d\n" , p[j].fa , p[j].ch[0] , p[j].ch[1] , p[j].siz );
		}*/
	}
}
int main () {
	work ();
	return 0;
}