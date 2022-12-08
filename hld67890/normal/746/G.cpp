#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
struct node {
	int l , r , minn , lazy;
	node *ll , *rr;
} pool[maxn*8] , *root;
int top;
int n , t , k;
int s[maxn*2] , l[maxn*2] , tot;
int u[maxn*2] , v[maxn*2] , index;
int a[maxn];
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	id -> lazy = 0;
	if ( l == r ) {
		id -> minn = a[l];
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> minn = min ( id -> ll -> minn , id -> rr -> minn );
}
void change ( node *id , int l , int r , int x ) {
	if ( id -> l == l && id -> r == r ) {
		id -> minn += x;
		id -> lazy += x;
		return ;
	}
	if ( id -> lazy ) {
		id -> ll -> lazy += id -> lazy; id -> rr -> lazy += id -> lazy;
		id -> ll -> minn += id -> lazy; id -> rr -> minn += id -> lazy;
		id -> lazy = 0;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) change ( id -> ll , l , r , x );
	else {
		if ( l > mid ) change ( id -> rr , l , r , x );
		else {
			change ( id -> ll , l , mid , x );
			change ( id -> rr , mid + 1 , r , x );
		}
	}
	id -> minn = min ( id -> ll -> minn , id -> rr -> minn );
}
int query ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> minn;
	if ( id -> lazy ) {
		id -> ll -> lazy += id -> lazy; id -> rr -> lazy += id -> lazy;
		id -> ll -> minn += id -> lazy; id -> rr -> minn += id -> lazy;
		id -> lazy = 0;
	}
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return min ( query ( id -> ll , l , mid ) , query ( id -> rr , mid + 1 , r ) );
	}
}
int nextsmall ( int i ) {
	int l , r , mid , x;
	l = i; r = t;
	x = query ( root , i , i );
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( query ( root , i , mid ) >= x ) l = mid;
		else r = mid;
	}
	if ( query ( root , i , r ) >= x ) return r;
	return l;
}
void add ( int start , int len ) {
	int i;
	for ( i = 1 ; i <= len ; i++ ) {
		u[++index] = start; v[index] = index;
		start = index;
	}
}
void addchain ( int start , int len ) {
	s[++tot] = start; l[tot] = len;
}
void work () {
	int i , j , left , need , last;
	scanf ( "%d%d%d" , &n , &t , &k );
	for ( i = 1 ; i <= t ; i++ ) {
		scanf ( "%d" , &a[i] );
		a[i]--;
	}
	root = &pool[++top];
	buildtree ( root , 1 , t );
	k--;
	index = 0;
	addchain ( 0 , t );
	for ( i = 1 ; i <= t ; i++ ) {
		left = query ( root , i , i );
		while ( left-- ) {
			j = nextsmall ( i );
			addchain ( i - 1 , j - i + 1);
			change ( root , i , j , -1 );
			k--;
		}
	}
	if ( k < 0 ) {
		printf ( "-1\n" );
	}
	else {
		i = 2;
		while ( k ) {
			if ( l[i] > 1 ) {
				addchain ( s[i] + l[i] - 1 , 1 );
				l[i]--;
				k--;
			}
			if ( l[i] == 1 ) i++;
			if ( i > tot ) {
				printf ( "-1\n" );
				return ;
			}
		}
		printf ( "%d\n" , n );
		for ( i = 1 ; i <= tot ; i++ ) add ( s[i] , l[i] );
		for ( i = 1 ; i <= index ; i++ ) printf ( "%d %d\n" , u[i] + 1 , v[i] + 1 );
	}
}
int main () {
	work ();
	return 0;
}