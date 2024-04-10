#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int v;
	node *next;
} pool[1000000] , *g[500000];
int top;
int n , m;
int size[500000] , w[550000] , index;
long long sum[2000000];
int lazy[2000000] , a[500000];
long long ans;
void add ( int u , int v ) {
	node *tmp1 = &pool[top++] , *tmp2 = &pool[top++];
	tmp1 -> v = v; tmp1 -> next = g[u]; g[u] = tmp1;
	tmp2 -> v = u; tmp2 -> next = g[v]; g[v] = tmp2;
}
void dfs ( int x ) {
	w[x] = ++index;
	size[x] = 1;
	for ( node *j = g[x] ; j ; j = j -> next ) {
		if ( size[j -> v] == 0 ) {
			dfs ( j -> v );
			size[x] += size[j -> v];
		}
	}
}
void change ( int id , int l , int r , int x , int y , int c ) {
	int i , mid = (l+r)/2;
	if ( l == x && r == y ) {
		sum[id] = (1ll<<c);
		lazy[id] = c;
		return ;
	}
	if ( lazy[id] ) {
		sum[id*2] = sum[id*2+1] = 1ll<<lazy[id];
		lazy[id*2+1] = lazy[id*2] = lazy[id];
		lazy[id] = 0;
	}
	if ( y <= mid ) change ( id * 2 , l , mid , x , y , c );
	else {
		if ( x > mid ) change ( id * 2 + 1 , mid + 1 , r , x , y , c );
		else {
			change ( id * 2 , l , mid , x , mid , c );
			change ( id * 2 + 1 , mid + 1 , r , mid + 1 , y , c );
		}
	}
	sum[id] = sum[id*2]|sum[id*2+1];
}
void query ( int id , int l , int r , int x , int y ) {
	int i , mid = (l+r)/2;
	if ( l == x && r == y ) {
		ans = ans | sum[id];
		return ;
	}
	if ( lazy[id] ) {
		sum[id*2] = sum[id*2+1] = 1ll<<lazy[id];
		lazy[id*2+1] = lazy[id*2] = lazy[id];
		lazy[id] = 0;
	}
	if ( y <= mid ) query ( id * 2 , l , mid , x , y );
	else {
		if ( x > mid ) query ( id * 2 + 1 , mid + 1 , r , x , y );
		else {
			query ( id * 2 , l , mid , x , mid );
			query ( id * 2 + 1 , mid + 1 , r , mid + 1 , y );
		}
	}
	sum[id] = sum[id*2]|sum[id*2+1];
}
void work () {
	int i , j , u , v , k , s;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v );
	}
	dfs ( 1 );
	//for ( i = 1 ; i <= n ; i++ ) cout << w[i] << "  " << size[i] << endl;
	for ( i = 1 ; i <= n ; i++ ) change ( 1 , 1 , n , w[i] , w[i] , a[i] );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &k );
		if ( k == 1 ) {
			scanf ( "%d%d" , &u , &v );
			change ( 1 , 1 , n , w[u] , w[u] + size[u] - 1 , v );
		}
		else {
			scanf ( "%d" , &u );
			ans = 0;
			query ( 1 , 1 , n , w[u] , w[u] + size[u] - 1 );
			s = 0;
			while ( ans ) s += ans % 2, ans = ans / 2;
			printf ( "%d\n" , s );
		}
	}
}
int main () {
	work ();
	return 0;
}