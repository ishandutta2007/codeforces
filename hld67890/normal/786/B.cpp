#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

//long long
//mem
const long long maxn = 120000;
struct node {
	long long v , c;
	node *next;
} pooln[maxn*40] , *g[maxn*8];
struct tree {
	long long l , r , id;
	tree *ll , *rr;
} poolt[maxn*8] , *t1 , *t2;
long long topn , topt;
long long n , q , s;
long long dis[maxn*8] , f[maxn*8];
void add ( long long u , long long v , long long c ) {
	//printf ( "$$%I64d %I64d %I64d\n" , u , v , c );
	node *tmp = &pooln[++topn];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void buildtree1 ( tree *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> id = l;
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &poolt[++topt]; id -> ll -> id = n + topt;
	id -> rr = &poolt[++topt]; id -> rr -> id = n + topt;
	buildtree1 ( id -> ll , l , mid ); buildtree1 ( id -> rr , mid + 1 , r );
	add ( id -> id , id -> ll -> id , 0 ); add ( id -> id , id -> rr -> id , 0 );
}
void buildtree2 ( tree *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> id = l;
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &poolt[++topt]; id -> ll -> id = n + topt;
	id -> rr = &poolt[++topt]; id -> rr -> id = n + topt;
	buildtree2 ( id -> ll , l , mid ); buildtree2 ( id -> rr , mid + 1 , r );
	add ( id -> ll -> id , id -> id , 0 ); add ( id -> rr -> id , id -> id , 0 );
}
void addtree1 ( tree *id , long long l , long long r , long long v , long long c ) {
	if ( id -> l == l && id -> r == r ) {
		add ( v , id -> id , c );
		return ;
	}
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) addtree1 ( id -> ll , l , r , v , c );
	else {
		if ( l > mid ) addtree1 ( id -> rr , l , r , v , c );
		else {
			addtree1 ( id -> ll , l , mid , v , c );
			addtree1 ( id -> rr , mid + 1 , r , v , c );
		}
	}
}
void addtree2 ( tree *id , long long l , long long r , long long v , long long c ) {
	if ( id -> l == l && id -> r == r ) {
		add ( id -> id , v , c );
		return ;
	}
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) addtree2 ( id -> ll , l , r , v , c );
	else {
		if ( l > mid ) addtree2 ( id -> rr , l , r , v , c );
		else {
			addtree2 ( id -> ll , l , mid , v , c );
			addtree2 ( id -> rr , mid + 1 , r , v , c );
		}
	}
}
void spfa () {
	long long i , k;
	queue < long long > q;
	for ( i = 1 ; i <= n + topt ; i++ ) dis[i] = 2147483647777777ll, f[i] = 0;
	dis[s] = 0; f[s] = 1; q.push ( s );
	while ( q.size () ) {
		k = q.front (); q.pop (); f[k] = 0;
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( dis[j->v] > dis[k] + j -> c ) {
				dis[j->v] = dis[k] + j -> c;
				if ( !f[j->v] ) q.push ( j -> v );
				f[j->v] = 1;
			}
	}
}
void work () {
	long long i , u , v , l , r , op , c;
	scanf ( "%I64d%I64d%I64d" , &n , &q , &s );
	t1 = &poolt[++topt]; t1 -> id = n + topt;
	buildtree1 ( t1 , 1 , n );
	t2 = &poolt[++topt]; t2 -> id = n + topt;
	buildtree2 ( t2 , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%I64d" , &op );
		if ( op == 1 ) {
			scanf ( "%I64d%I64d%I64d" , &u , &v , &c );
			add ( u , v , c );
		}
		if ( op == 2 ) {
			scanf ( "%I64d%I64d%I64d%I64d" , &u , &l , &r , &c );
			addtree1 ( t1 , l , r , u , c );
		}
		if ( op == 3 ) {
			scanf ( "%I64d%I64d%I64d%I64d" , &v , &l , &r , &c );
			addtree2 ( t2 , l , r , v , c );
		}
	}
	spfa ();
	for ( i = 1 ; i <= n ; i++ ) if ( dis[i] == 2147483647777777ll ) dis[i] = -1;
	for ( i = 1 ; i <= n ; i++ ) printf ( "%I64d%c" , dis[i] , i==n?'\n':' ' );
}
int main () {
	//FILE *fpr = freopen ( "b.in" , "r" , stdin );
	//FILE *fpw = freopen ( "b.out" , "w" , stdout );
	work ();
	return 0;
}