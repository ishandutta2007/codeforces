#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 210000;
struct node {
	int l , r , minn;
	node *ll , *rr;
} pool[maxn*4] , *t;
int top;
int n , q;
int f1 , f2;
int a[maxn];
int first[maxn] , last[maxn];
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> minn = a[l];
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
	id -> minn = min ( id -> ll -> minn , id -> rr -> minn );
}
int query ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> minn;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else {
			return min ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
		}
	}
}
void work () {
	int i;
	scanf ( "%d%d" , &n , &q );
	f1 = f2 = 0;
	for ( i = 1 ; i <= q ; i++ ) {
		first[i] = 99999999;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		if ( a[i] == q ) f1 = 1;
		if ( a[i] == 0 ) f2 = 1;
		first[a[i]] = min ( first[a[i]] , i );
		last[a[i]] = max ( last[a[i]] , i );
	}
	if ( !f1 ) {
		if ( f2 == 0 ) {
			printf ( "NO\n" );
			return ;
		}
		else {
			for ( i = 1 ; i <= n ; i++ ) {
				if ( a[i] == 0 ) {
					a[i] = q;
					break;
				}
			}
		}
	}
	if ( a[1] == 0 ) {
		for ( i = 1 ; i <= n ; i++ ) if ( a[i] != 0 ) break;
		for ( i-- ; i >= 1 ; i-- ) a[i] = a[i+1];
	}
	for ( i = 1 ; i <= n ; i++ ) if ( a[i] == 0 ) a[i] = a[i-1];
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= q ; i++ ) {
		if ( last[i] != 0 ) {
			if ( query ( t , first[i] , last[i] ) < i ) {
				printf ( "NO\n" );
				return ;
			}
		}
	}
	printf ( "YES\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		printf ( "%d%c" , a[i] , i==n?'\n':' ' );
	}
}
int main () {
	work ();
	return 0;
}