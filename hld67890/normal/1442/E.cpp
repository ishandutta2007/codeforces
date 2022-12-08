#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *next;
} pool[420000] , *g[210000];
int top;
int n;
int col[220000];
int dp[210000][4];
int ans;
void clear () {
	int i;
	for ( i = 1 ; i <= n ; i++ ) {
		g[i] = NULL;
	}
	for ( i = 1 ; i <= top ; i++ ) {
		pool[i] = pool[0];
	}
	top = 0;
}
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	int mx , mx2 , t , t1 , t2;
	dp[i][1] = dp[i][2] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		dp[i][1] = max ( dp[i][1] , min ( dp[j->v][1] , dp[j->v][2] + 1 ) );
		dp[i][2] = max ( dp[i][2] , min ( dp[j->v][2] , dp[j->v][1] + 1 ) );
	}
	if ( col[i] == 1 ) dp[i][2] = 9999999;
	if ( col[i] == 2 ) dp[i][1] = 9999999;
	t1 = t2 = 9999999;
	if ( col[i] != 2 ) {
		mx = mx2 = 0;
		for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
			t = min ( dp[j->v][1] , dp[j->v][2] + 1 );
			if ( t > mx ) {
				mx2 = mx;
				mx = t;
			}
			else if ( t > mx2 ) mx2 = t;
		}
		t1 = mx + mx2 - (mx2!=0);
	}
	if ( col[i] != 1 ) {
		mx = mx2 = 0;
		for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
			t = min ( dp[j->v][2] , dp[j->v][1] + 1 );
			if ( t > mx ) {
				mx2 = mx;
				mx = t;
			}
			else if ( t > mx2 ) mx2 = t;
		}
		t2 = mx + mx2 - (mx2!=0);
	}
	ans = max ( ans , min ( t1 , t2 ) );
}
void work () {
	int i , u , v;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &col[i] );
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v );
		add ( v , u );
	}
	ans = 0;
	dfs ( 1 , -1 );
	//printf ( "##%d\n" , ans );
	printf ( "%d\n" , ans / 2 + 1 );
	clear ();
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}