#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 210000;
struct info {
	long long s , pos , use;
};
struct node {
	long long l , r , lazy;
	info t;
	node *ll , *rr;
} pool[maxn*2] , *t;
long long top;
long long n;
long long a[maxn];
long long ans[maxn];
void pushdown ( node *id ) {
	if ( id -> lazy ) {
		id -> ll -> lazy += id -> lazy;
		id -> ll -> t.s += id -> lazy;
		id -> rr -> lazy += id -> lazy;
		id -> rr -> t.s += id -> lazy;
		id -> lazy = 0;
	}
}
info merge ( info x1 , info x2 ) {
	if ( x1.use == 1 && x2.use == 1 ) return x1;
	if ( x1.use == 1 ) return x2;
	if ( x2.use == 1 ) return x1;
	if ( x1.s == x2.s ) {
		if ( x1.pos > x2.pos ) return x1;
		else return x2;
	}
	if ( x1.s < x2.s ) return x1;
	else return x2;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> t.pos = l; id -> t.s = a[l]; id -> t.use = 0;
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void taboo ( node *id , long long l ) {
	if ( id -> l == id -> r ) {
		id -> t.use = 1;
		return ;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( l <= mid ) taboo ( id -> ll , l );
	else taboo ( id -> rr , l );
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void change ( node *id , long long l , long long r , long long x ) {
	if ( id -> l == l && id -> r == r ) {
		id -> lazy += x;
		id -> t.s += x;
		return ;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , x );
	else {
		if ( l > mid ) change ( id -> rr , l , r , x );
		else {
			change ( id -> ll , l , mid , x );
			change ( id -> rr , mid + 1 , r , x );
		}
	}
	id -> t = merge ( id -> ll -> t , id -> rr -> t );
}
void work () {
	long long i , pos;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= n ; i++ ) {
		pos = t -> t.pos;
		taboo ( t , pos );
		if ( pos != n ) change ( t , pos + 1 , n , -i );
		ans[pos] = i;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%I64d%c" , ans[i] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}