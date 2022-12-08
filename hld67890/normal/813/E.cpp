#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 120000;
struct node {
	int l , r , s;
	node *ll , *rr;
} pool[maxn*2+maxn*18] , *t[maxn];
int top;
int n , k , q;
int a[maxn];
int next[maxn] , pre[maxn];
int cnt[maxn] , now[maxn];
int last[maxn];
int lastans , ans;
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) return ;
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
}
void add ( node *id , node *idd , int x ) {
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
	if ( id -> l == l && id -> r == r ) return id -> s;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
void work () {
	int i , l , r;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( last[a[i]] != 0 ) {
			pre[i] = last[a[i]];
			next[pre[i]] = i;
		}
		last[a[i]] = i;
	}
	t[0] = &pool[++top];
	buildtree ( t[0] , 1 , 100000 );
	for ( i = 1 ; i <= n ; i++ ) {
		cnt[a[i]]++;
		if ( cnt[a[i]] == 1 ) now[a[i]] = i;
		if ( cnt[a[i]] > k ) {
			t[i] = &pool[++top];
			add ( t[i] , t[i-1] , now[a[i]] );
			now[a[i]] = next[now[a[i]]];
		}
		else t[i] = t[i-1];
	}
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &l , &r );
		l = ( l + lastans ) % n + 1;
		r = ( r + lastans ) % n + 1;
		if ( l > r ) swap ( l , r );
		ans = r-l+1 - query ( t[r] , l , r );
		printf ( "%d\n" , ans );
		lastans = ans;
	}
}
int main () {
	//FILE *fpr = freopen ( "e.in" , "r" , stdin );
	//FILE *fpw = freopen ( "e.out" , "w" , stdout );
	work ();
	return 0;
}