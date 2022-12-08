#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 120000;
struct heap {
	priority_queue < int , vector<int> , greater <int> > p , q;
	void push ( int x ) {
		p.push ( x ); 
	}
	void pop ( int x ) {
		q.push ( x );
	}
	int top () {
		while ( q.size () && p.top () == q.top () ) {
			p.pop (); q.pop ();
		}
		return p.top ();
	}
} h[maxn*2];
struct node {
	int v;
	node *next;
} pooln[maxn*4] , *g[maxn*2];
struct newgraph {
	int v;
	newgraph *next;
} poolg[maxn*4] , *ng[maxn*2];
struct tree {
	int l , r , minn;
	tree *ll , *rr;
} poolt[maxn*4] , *t;
int topn , topt , topng;
int n , m , q;
int a[maxn];
char z[20];

int dfn[maxn*2] , low[maxn*2] , indext;
int st[maxn*2] , tops;
int cut[maxn];
int block[maxn*2] , topb;
int lb[maxn*2] , rb[maxn*2] , totb;
int color[maxn*2];

int dep[maxn*2] , fa[maxn*2] , siz[maxn*2] , top[maxn*2] , w[maxn*2] , d[maxn*2] , son[maxn*2] , indexh;

void add ( int u , int v ) {
	node *tmp = &pooln[++topn];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void tarjan ( int i , int from ) {
	int s = 0;
	dfn[i] = low[i] = ++indext;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( dfn[j->v] ) {
			low[i] = min ( low[i] , dfn[j->v] );
		}
		else {
			s++;
			st[++tops] = j -> v;
			tarjan ( j -> v , i );
			low[i] = min ( low[i] , low[j->v] );
			if ( low[j->v] >= dfn[i] ) {
				if ( from != -1 || s >= 2 ) {
					cut[i] = 1;
				}
				lb[++totb] = topb + 1;
				while ( st[tops] != j -> v ) {
					block[++topb] = st[tops];
					color[st[tops]] = totb;
					tops--;
				}
				block[++topb] = j -> v;
				color[j->v] = totb;
				block[++topb] = i;
				color[i] = totb;
				rb[totb] = topb;
				tops--;
			}
		}
	}
}

void addng ( int u , int v ) {
	newgraph *tmp = &poolg[++topng];
	tmp -> v = v; tmp -> next = ng[u]; ng[u] = tmp;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	//printf ( "%d  %d\n" , i , from );
	for ( newgraph *j = ng[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dep[j->v] = dep[i] + 1;
		fa[j->v] = i;
		dfs1 ( j -> v , i );
		siz[i] += siz[j->v];
		if ( siz[j->v] > siz[son[i]] ) son[i] = j -> v;
	}
}
void dfs2 ( int i , int from ) {
	w[i] = ++indexh;
	d[indexh] = i;
	if ( son[i] ) {
		top[son[i]] = top[i];
		dfs2 ( son[i] , i );
	}
	for ( newgraph *j = ng[i] ; j ; j = j -> next ) if ( j -> v != from && j -> v != son[i] ) {
		top[j->v] = j -> v;
		dfs2 ( j -> v , i );
	}
}
void buildtree ( tree *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> minn = h[d[l]].top ();
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &poolt[++topt]; id -> rr = &poolt[++topt];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> minn = min ( id -> ll -> minn , id -> rr -> minn );
}
void change ( tree *id , int x , int y ) {
	if ( id -> l == id -> r ) {
		id -> minn = y;
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) change ( id -> ll , x , y );
	else change ( id -> rr , x , y );
	id -> minn = min ( id -> ll -> minn , id -> rr -> minn );
}
int query ( tree *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> minn;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return min ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
	}
}
int querytree ( int u , int v ) {
	int ret = 2147483647;
	//if ( a[26776] == 1090433 ) printf ( "%d %d\n" , u , v );
	while ( top[u] != top[v] ) {
		if ( dep[top[u]] < dep[top[v]] ) swap ( u , v );
		ret = min ( ret , query ( t , w[top[u]] , w[u] ) );
		u = fa[top[u]];
	}
	if ( dep[u] < dep[v] ) swap ( u , v );
	ret = min ( ret , query ( t , w[v] , w[u] ) );
	//printf ( "#%d\n" , v );
	if ( fa[v] && v <= totb ) ret = min ( ret , query ( t , w[fa[v]] , w[fa[v]] ) );
	//the top bcc's father.
	//if ( a[26776] == 1090433 ) printf ( "%d %d\n" , v , ret );
	return ret;
}
void work () {
	int i , j , u , v , last , x , y , tmpx , tmpy;
	scanf ( "%d%d%d" , &n , &m , &q );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	tarjan ( 1 , -1 );
	//for ( i = 1 ; i <= totb ; i++ ) {
	//	for ( j = lb[i] ; j <= rb[i] ; j++ ) printf ( "%d " , block[j] );
	//	printf ( "\n" );
	//}
	//for ( i = 1 ; i <= n ; i++ ) printf ( "%d\n" , cut[i] );
	last = totb;
	for ( i = 1 ; i <= n ; i++ ) if ( cut[i] ) {
		cut[i] += last;
		last = cut[i];
	}
	for ( i = 1 ; i <= totb ; i++ ) {
		h[i].push ( 2147483647 );
		for ( j = lb[i] ; j <= rb[i] ; j++ ) {
			if ( cut[block[j]] ) {
				addng ( i , cut[block[j]] );
				addng ( cut[block[j]] , i );
			}
			else {
				//printf ( "   %d %d\n" , i , a[block[j]] );
				h[i].push ( a[block[j]] ); 
			}
		}
	}
	dep[1] = 0;
	dfs1 ( 1 , -1 );
	top[1] = 1;
	dfs2 ( 1 , -1 );
	//printf ( "##\n" );
	for ( i = 1 ; i <= n ; i++ ) if ( cut[i] ) {
		h[cut[i]].push ( a[i] );
		if ( fa[cut[i]] ) {
			//printf ( "@@%d\n" , i );
			h[fa[cut[i]]].push ( a[i] );
		}
	}
	t = &poolt[++topt];
	buildtree ( t , 1 , last );
	//if ( a[26776] == 1090433 ) printf ( "%d\n" , query ( t , w[32118] , w[32118] ) );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s%d%d" , z + 1 , &x , &y );
		if ( z[1] == 'A' ) {
			if ( x == y ) {
				printf ( "%d\n" , a[x] );
				continue;
			}
			if ( cut[x] ) tmpx = cut[x];
			else tmpx = color[x];
			if ( cut[y] ) tmpy = cut[y];
			else tmpy = color[y];
			printf ( "%d\n" , querytree ( tmpx , tmpy ) );
		}
		else {
			if ( cut[x] ) {
				tmpx = cut[x];
				if ( fa[tmpx] ) {
					//magic
					h[fa[tmpx]].pop ( a[x] );
					h[fa[tmpx]].push ( y );
					change ( t , w[fa[tmpx]] , h[fa[tmpx]].top () );
				}
			}
			else tmpx = color[x];
			h[tmpx].pop ( a[x] );
			a[x] = y;
			h[tmpx].push ( y );
			//printf ( "%d %d\n" , tmpx , h[tmpx].top() );
			change ( t , w[tmpx] , h[tmpx].top () );
		}
	}
}
int main () {
	work ();
	return 0;
}