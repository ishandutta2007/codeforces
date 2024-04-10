#include <iostream>
#include <stdio.h>

using namespace std;

struct tree {
	long long s , m , l , r;
	tree *ll , *rr;
} pool[400010] , *t;
long long top;
long long n , m , a[100001];
void buildtree ( tree *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> s = id -> m = a[l];
		return ;
	}
	id -> ll = &pool[top++];
	id -> rr = &pool[top++];
	long long mid = ( l + r ) / 2;
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
	id -> s = id -> ll -> s + id -> rr -> s;
	id -> m = max ( id -> ll -> m , id -> rr -> m );
}
void change ( tree *id , long long d ) {
	if ( id -> l == id -> r ) {
		id -> s = id -> s % d;
		id -> m = id -> s;
		return ;
	}
	if ( id -> ll -> m >= d ) change ( id -> ll , d );
	if ( id -> rr -> m >= d ) change ( id -> rr , d );
	id -> s = id -> ll -> s + id -> rr -> s;
	id -> m = max ( id -> ll -> m , id -> rr -> m );
}
void change1 ( tree *id , long long l , long long r , long long d ) {
	if ( id -> l == l && id -> r == r ) {
		change ( id , d );
		return ;
	}
	long long mid = ( id -> l + id -> r ) / 2;
	if ( r <= mid )
		change1 ( id -> ll , l , r , d );
	else {
		if ( l > mid )
			change1 ( id -> rr , l , r , d );
		else {
			change1 ( id -> ll , l , mid , d );
			change1 ( id -> rr , mid + 1 , r , d );
		}
	}
	id -> s = id -> ll -> s + id -> rr -> s;
	id -> m = max ( id -> ll -> m , id -> rr -> m );
}
void change2 ( tree *id , long long l , long long c ) {
	if ( id -> l == id -> r ) { 
		id -> s = id -> m = c;
		return ;
	}
	long long mid = ( id -> l + id -> r ) / 2;
	if ( l <= mid ) change2 ( id -> ll , l , c );
	else change2 ( id -> rr , l , c );
	id -> s = id -> ll -> s + id -> rr -> s;
	id -> m = max ( id -> ll -> m , id -> rr -> m );
}
long long query ( tree *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) return id -> s;
	long long mid = ( id -> l + id -> r ) / 2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else
			return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
void work () {
	long long i , type , b , c , d , del;
	scanf ( "%I64d%I64d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
	t = &pool[top++];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &type , &b , &c );
		if ( type == 1 )
			printf ( "%I64d\n" , query ( t , b , c ) );
		if ( type == 2 ) {
			scanf ( "%I64d" , &d );
			change1 ( t , b , c , d );
		}
		if ( type == 3 )
			change2 ( t , b , c );
	}
}
int main () {
	work ();
	return 0;
}