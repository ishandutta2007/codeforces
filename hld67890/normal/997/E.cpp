#include <stdio.h>
#include <algorithm>
#include <vector>

#define pii pair<long long,long long>
#define fi first
#define se second

using namespace std;

const long long maxn = 130000;
struct node {
	long long l , r;
	long long lazy , value , num , ans , tim;
	node *ll , *rr;
} pool[maxn*2] , *t;
long long top;
long long n , q;
long long a[maxn];
vector < pii > que[maxn];
long long st1[maxn] , st2[maxn] , tops1 , tops2;
long long ans[maxn];
void pushdown ( node *id ) {
	if ( id -> lazy ) {
		id -> ll -> lazy += id -> lazy;
		id -> ll -> value += id -> lazy;
		id -> rr -> lazy += id -> lazy;
		id -> rr -> value += id -> lazy;
		id -> lazy = 0;
	}
	if ( id -> tim ) {
		if ( id -> ll -> value == id -> value ) {
			id -> ll -> tim += id -> tim;
			id -> ll -> ans += id -> tim * id -> ll -> num;
		}
		if ( id -> rr -> value == id -> value ) {
			id -> rr -> tim += id -> tim;
			id -> rr -> ans += id -> tim * id -> rr -> num;
		}
		id -> tim = 0;
	}
}
void update ( node *id ) {
	id -> value = min ( id -> ll -> value , id -> rr -> value );
	id -> ans = id -> ll -> ans + id -> rr -> ans;
	id -> num = 0;
	if ( id -> value == id -> ll -> value ) id -> num += id -> ll -> num;
	if ( id -> value == id -> rr -> value ) id -> num += id -> rr -> num;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	id -> value = l;
	id -> num = 1;
	if ( l == r ) return ;
	long long mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
}
void change ( node *id , long long l , long long r , long long x ) {
	//printf ( "%I64d %I64d %I64d %I64d\n" , id -> l , id -> r , l , r );
	if ( id -> l == l && id -> r == r ) {
		id -> value += x;
		id -> lazy += x;
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
	update ( id );
}
void changetime ( node *id , long long l , long long r , long long x ) {
	if ( id -> l == l && id -> r == r ) {
		id -> tim += x;
		id -> ans += x * id -> num;
		return ;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) changetime ( id -> ll , l , r , x );
	else {
		if ( l > mid ) changetime ( id -> rr , l , r , x );
		else {
			changetime ( id -> ll , l , mid , x );
			changetime ( id -> rr , mid + 1 , r , x );
		}
	}
	update ( id );
}
long long query ( node *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) return id -> ans;
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
	}
}
void work () {
	long long i , j , l , r;
	pii tmp;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	scanf ( "%I64d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%I64d%I64d" , &l , &r );
		tmp.fi = l; tmp.se = i;
		que[r].push_back ( tmp );
	}
	t = &pool[++top];
	buildtree ( t , 1 , n );
	for ( i = 1 ; i <= n ; i++ ) {
		change ( t , 1 , n , -1 );
		//printf ( "%I64d\n" , i );
		while ( tops1 > 0 && a[st1[tops1]] > a[i] ) {
			change ( t , st1[tops1-1] + 1 , st1[tops1] , a[st1[tops1]] - a[i] );
			tops1--;
		}
		st1[++tops1] = i;
		while ( tops2 > 0 && a[st2[tops2]] < a[i] ) {
			change ( t , st2[tops2-1] + 1 , st2[tops2] , a[i] - a[st2[tops2]] );
			tops2--;
		}
		st2[++tops2] = i;
		changetime ( t , 1 , n , 1 );
		for ( j = 0 ; j < que[i].size() ; j++ ) {
			ans[que[i][j].se] = query ( t , que[i][j].fi , i );
		}
	}
	for ( i = 1 ; i <= q ; i++ ) {
		printf ( "%I64d\n" , ans[i] );
	}
}
int main () {
	work ();
	return 0;
}