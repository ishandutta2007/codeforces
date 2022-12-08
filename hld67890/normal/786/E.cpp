#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 22000;
struct flow {
	int v , f , id;
	flow *next , *rev;
} poolf[maxn*80] , *gf[maxn*10];
struct graph {
	int v , id;
	graph *next;
} poolg[maxn*2] , *gr[maxn*2];
struct segtree {
	int l , r , id;
	segtree *ll , *rr;
} pools[maxn*2] , *t;
int topf , topg , tops;
int n , m;
int S , T;
int num[maxn];
int dep[maxn] , siz[maxn] , son[maxn] , top[maxn] , fa[maxn] , w[maxn] , d[maxn] , index;
int segid;
int level[maxn*10];
int ins[maxn*10];
int ans , ans1 , ans2 , out1[maxn] , out2[maxn];
void addg ( int u , int v , int id ) {
	graph *tmp = &poolg[++topg];
	tmp -> v = v; tmp -> id = id; tmp -> next = gr[u]; gr[u] = tmp;
}
void addf ( int u , int v , int f , int id ) {
	flow *tmp1 = &poolf[++topf] , *tmp2 = &poolf[++topf];
	tmp1 -> v = v; tmp1 -> f = f; tmp1 -> id = id; tmp1 -> next = gf[u]; gf[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> id = id; tmp2 -> next = gf[v]; gf[v] = tmp2; tmp2 -> rev = tmp1;
}
void dfs1 ( int i , int from ) {
	siz[i] = 1;
	for ( graph *j = gr[i] ; j ; j = j -> next ) if ( !dep[j->v] ) {
		dep[j->v] = dep[i] + 1;
		fa[j->v] = i;
		num[j->v] = j -> id;
		dfs1 ( j -> v , i );
		if ( siz[j->v] > siz[son[i]] ) son[i] = j -> v;
		siz[i] += siz[j->v];
	}
}
void dfs2 ( int i , int from ) {
	w[i] = ++index; d[index] = num[i];
	if ( son[i] ) {
		top[son[i]] = top[i];
		dfs2 ( son[i] , i );
	}
	for ( graph *j = gr[i] ; j ; j = j -> next ) if ( j -> v != from && j -> v != son[i] ) {
		top[j->v] = j -> v;
		dfs2 ( j -> v , i );
	}
}
void buildtree ( segtree *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		if ( l != 1 ) addf ( id -> id , 1 + m + n * 2 - 1 + 1 , 1 , -d[l] );
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pools[++tops]; id -> rr = &pools[++tops];
	id -> ll -> id = ++segid; id -> rr -> id = ++segid;
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	addf ( id -> id , id -> ll -> id , 9999999 , 0 );
	addf ( id -> id , id -> rr -> id , 9999999 , 0 );
}
void addinseg ( segtree *id , int l , int r , int i ) {
	if ( id -> l == l && id -> r == r ) {
		addf ( 1 + i , id -> id , 9999999 , 0 );
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) addinseg ( id -> ll , l , r , i );
	else {
		if ( l > mid ) addinseg ( id -> rr , l , r , i );
		else {
			addinseg ( id -> ll , l , mid , i );
			addinseg ( id -> rr , mid + 1 , r , i );
		}
	}
}
void addchain ( int u , int v , int i ) {
	while ( top[u] != top[v] ) {
		if ( dep[u] < dep[v] ) swap ( u , v );
		addinseg ( t , w[top[u]] , w[u] , i );
		u = fa[top[u]];
	}
	if ( u == v ) return ;
	if ( dep[u] < dep[v] ) swap ( u , v );
	addinseg ( t , w[son[v]] , w[u] , i );
}
bool makelevel () {
	int i , k;
	queue < int > q;
	for ( i = S ; i <= T ; i++ ) level[i] = -1;
	q.push ( S ); level[S] = 1;
	while ( q.size () ) {
		k = q.front (); q.pop ();
		for ( flow *j = gf[k] ; j ; j = j -> next )
			if ( j -> f && level[j->v] == -1 ) {
				level[j->v] = level[k] + 1;
				if ( j -> v == T ) return true;
				q.push ( j -> v );
			}
	}
	return false;
}
int find ( int k , int key ) {
	if ( k == T ) return key;
	int i , s = 0;
	for ( flow *j = gf[k] ; j ; j = j -> next )
		if ( j -> f && level[j->v] == level[k] + 1 && s < key ) {
			i = find ( j -> v , min ( key - s , j -> f ) );
			j -> f -= i;
			j -> rev -> f += i;
			s += i;
		}
	if ( s == 0 ) level[k] = -1;
	return s;
}
void dinic () {
	ans = 0;
	while ( makelevel () == true ) ans += find ( S , 9999999 );
}
void getans ( int i ) {
	ins[i] = 1;
	for ( flow *j = gf[i] ; j ; j = j -> next ) if ( j -> f && !ins[j->v] ) {
		//printf ( "%d %d %d %d\n" , i , j -> v , j -> id , j -> f );
		getans ( j -> v );
	}
}
void work () {
	int i , u , v;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		addg ( u , v , i ); addg ( v , u , i );
	}
	dep[1] = 1;
	dfs1 ( 1 , -1 );
	top[1] = 1;
	dfs2 ( 1 , -1 );
	t = &pools[++tops];
	t -> id = segid = 1 + m + 1;
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		addf ( 1 , 1 + i , 1 , i );
		addchain ( u , v , i );
	}
	S = 1; T = segid + 1;
	dinic ();
	getans ( 1 );
	for ( i = 1 ; i <= T ; i++ ) if ( ins[i] ) {
		//printf ( " %d\n" , i );
		for ( flow *j = gf[i] ; j ; j = j -> next ) if ( j -> f == 0 && !ins[j->v] && j -> id != 0 ) {
			//printf ( "%d %d %d\n" , i , j -> v , j -> id );
			if ( j -> id > 0 ) out1[++ans1] = j -> id;
			else out2[++ans2] = -j -> id;
		}
	}
	printf ( "%d\n" , ans );
	printf ( "%d" , ans1 );
	for ( i = 1 ; i <= ans1 ; i++ ) printf ( " %d" , out1[i] );
	printf ( "\n" );
	printf ( "%d" , ans2 );
	for ( i = 1 ; i <= ans2 ; i++ ) printf ( " %d" , out2[i] );
	printf ( "\n" );
}
int main () {
	work ();
	return 0;
}