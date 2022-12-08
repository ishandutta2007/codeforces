#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

//long long
const long long large = 1000000000000000ll;
struct person {
	long long w , index , from;
};
struct node {
	long long l , r , lazy;
	person t;
	node *ll , *rr;
} pooln[800000] , *t;
struct tree {
	long long v;
	tree *next;
} poolt[300000] , *g[120000];
long long topt , topn;
bool operator < ( person x1 , person x2 ) {
	if ( x1.w == x2.w ) return x1.index < x2.index;
	return x1.w < x2.w;
}
long long n , m , p;
map < person , long long > mapp[120000];
long long dep[120000] , siz[120000] , son[120000] , top[120000] , w[120000] , fa[120000];
long long index;
long long ans[120000];
void output ( node *id ) {
	if ( id -> ll ) output ( id -> ll );
	cout <<"@@@"<< id -> l << " " << id -> r << " " << id -> t.w << " " << id -> t.index << " " << id -> t.from << endl;
	if ( id -> rr ) output ( id -> rr );
}
void add ( long long u , long long v ) {
	tree *tmp = &poolt[++topt];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( long long i ) {
	siz[i] = 1;
	for ( tree *j = g[i] ; j ; j = j -> next )
		if ( !dep[j->v] ) {
			dep[j->v] = dep[i] + 1;
			fa[j->v] = i;
			dfs1 ( j -> v );
			siz[i] += siz[j->v];
		}
}
void dfs2 ( long long i ) {
	w[i] = ++index;
	for ( tree *j = g[i] ; j ; j = j -> next )
		if ( !w[j->v] && siz[j->v] > siz[son[i]] ) son[i] = j -> v;
	if ( son[i] ) {
		top[son[i]] = top[i];
		dfs2 ( son[i] );
	}
	for ( tree *j = g[i] ; j ; j = j -> next )
		if ( !w[j->v] ) {
			top[j->v] = j -> v;
			dfs2 ( j -> v );
		}
}
person better ( person x1 , person x2 ) {
	if ( x1.w == x2.w ) {
		if ( x1.index < x2.index ) return x1;
		return x2;
	}
	if ( x1.w < x2.w ) return x1;
	return x2;
}
void pushup ( node *id ) {
	id -> t = better ( id -> ll -> t , id -> rr -> t );
}
void pushdown ( node *id ) {
	id -> ll -> t.w += id -> lazy;
	id -> rr -> t.w += id -> lazy;
	id -> ll -> lazy += id -> lazy;
	id -> rr -> lazy += id -> lazy;
	id -> lazy = 0;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> t = mapp[l].begin () -> first;
		id -> t.from = l;
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &pooln[++topn]; id -> rr = &pooln[++topn];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	pushup ( id );
}
void change ( node *id , long long l , long long r , long long k ) {
	if ( id -> l == l && id -> r == r ) {
		id -> lazy += k;
		id -> t.w += k;
		return ;
	}
	if ( id -> lazy ) pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , k );
	else {
		if ( l > mid ) change ( id -> rr , l , r , k );
		else {
			change ( id -> ll , l , mid , k );
			change ( id -> rr , mid + 1 , r , k );
		}
	}
	pushup ( id );
}
void del ( node *id , long long x ) {
	if ( id -> l == id -> r ) {
		person tmp;
		tmp = mapp[id->l].begin () -> first;
		mapp[id->l].erase ( tmp );
		id -> t = mapp[id->l].begin() -> first;
		id -> t.from = id -> l; id -> t.w += id -> lazy;
		return ; 
	}
	if ( id -> lazy ) pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( x <= mid ) del ( id -> ll , x );
	else del ( id -> rr , x );
	pushup ( id );
}
person query ( node *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) return id -> t;
	if ( id -> lazy ) pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return better ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
	}
}
person querytree ( long long u , long long v ) {
	person tmp;
	tmp.w = large;
	while ( top[u] != top[v] ) {
		if ( dep[top[u]] < dep[top[v]] ) swap ( u , v );
		tmp = better ( tmp , query ( t , w[top[u]] , w[u] ) );
		u = top[u]; u = fa[u];
	}
	if ( dep[u] < dep[v] ) swap ( u , v );
	tmp = better ( tmp , query ( t , w[v] , w[u] ) );
	return tmp;
}
void work () {
	long long i , j , l , u , v , op , k;
	person tmp;
	scanf ( "%I64d%I64d%I64d" , &n , &m , &p );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%I64d%I64d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dep[1] = 1;
	dfs1 ( 1 );
	top[1] = 1;
	dfs2 ( 1 );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d" , &u );
		tmp.index = i; tmp.w = i;
		mapp[w[u]][tmp] = 1;
		//cout << tmp.w << " %%%%%%% " << w[tmp.w] << endl;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		tmp.w = large; tmp.index = -1;
		mapp[i][tmp] = 1;
	}
	//for ( i = 1 ; i <= n ; i++ ) cout << mapp[i].begin()->first.w<< endl;
	//cout << "@@@" << endl;
	//for ( i = 1 ; i <= n ; i++ ) cout << w[i] << " ";
	//cout << endl;
	t = &pooln[++topn];
	buildtree ( t , 1 , n );
	//output ( t );
	for ( i = 1 ; i <= p ; i++ ) {
		//output ( t );
		scanf ( "%I64d" , &op );
		if ( op == 1 ) {
			scanf ( "%I64d%I64d%I64d" , &u , &v , &k );
			for ( j = 1 ; j <= k ; j++ ) {
				tmp = querytree ( u , v );
				if ( tmp.w == large ) break;
				ans[j] = tmp.index;
				del ( t , tmp.from );
			}
			j--;
			printf ( "%I64d" , j );
			for ( l = 1 ; l <= j ; l++ ) printf ( " %I64d" , ans[l] );
			printf ( "\n" );
		}
		else {
			scanf ( "%I64d%I64d" , &u , &k );
			change ( t , w[u] , w[u] + siz[u] - 1 , k );
		}
	}
}
int main () {
	work ();
	return 0;
}