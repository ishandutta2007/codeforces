#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
struct node {
	int l , r , s;
	node *ll , *rr;
} pool[maxn*33] , *t[maxn];
int top;
int n;
int a[maxn];
int b[maxn] , exist[maxn] , next[maxn];
int tot;
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> s = b[l];
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> s = id -> ll -> s + id -> rr -> s;
}
void add ( node *id , node *idd , int x ) {
	//printf ( "%d %d %d\n" , idd -> l , idd -> r , x );
	id -> l = idd -> l; id -> r = idd -> r;
	id -> s = idd -> s + 1;
	if ( id -> l == id -> r ) return ;
	int mid = (id->l+id->r)/2;
	if ( x <= mid ) {
		id -> rr = idd -> rr;
		id -> ll = &pool[++top];
		add ( id -> ll , idd -> ll , x );
	}
	else {
		id -> ll = idd -> ll;
		id -> rr = &pool[++top];
		add ( id -> rr , idd -> rr , x );
	}
}
int query ( node *id , int l , int r ) {
	if ( r <= 0 ) return 0;
	if ( id -> l == l && id -> r == r ) return id -> s;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
int find ( node *id , int k ) {
	if ( id -> l == id -> r ) return id -> l;
	if ( id -> ll -> s >= k ) return find ( id -> ll , k );
	else return find ( id -> rr , k - id -> ll -> s );
}
void work () {
	int i , j , k;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( exist[a[i]] == 0 ) b[i] = 1;
		next[exist[a[i]]] = i;
		exist[a[i]] = i;
	}
	t[1] = &pool[++top];
	b[n+1] = 1;
	buildtree ( t[1] , 1 , n + 1 );
	for ( i = 2 ; i <= n ; i++ ) {
		if ( next[i-1] ) {
			t[i] = &pool[++top];
			add ( t[i] , t[i-1] , next[i-1] );
		}
		else t[i] = t[i-1];
		//printf ( "%d\n" , next[i-1] );
	}
	//printf ( "%d\n" , find ( t[4] , 4 ) );
	for ( i = 1 ; i <= n ; i++ ) {
		tot = 0;
		j = 1;
		while ( j <= n ) {
			//printf ( "%d %d %d\n" , i , j , query ( t[j] , 1 , j - 1 ) );
			k = find ( t[j] , i + query ( t[j] , 1 , j - 1 ) + 1 );
			tot++;
			j = k;
		}
		printf ( "%d%c" , tot , i==n?'\n':' ' );
	}
}
int main () {
	//FILE *fpr = freopen ( "c.in" , "r" , stdin );
	//FILE *fpw = freopen ( "c.out" , "w" , stdout );
	work ();
	return 0;
}