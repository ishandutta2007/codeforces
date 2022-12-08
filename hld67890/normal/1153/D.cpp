#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 310000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n;
int kind[maxn];
int fa[maxn];
int dp[maxn] , siz[maxn];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i ) {
	node *best = NULL;
	int sum = 0 , son = 0;
	for ( node *j = g[i] ; j ; j = j -> next ) {
		son++;
		dfs ( j -> v );
		siz[i] += siz[j->v];
		if ( best == NULL ) best = j;
		if ( kind[i] == 0 ) {
			sum += siz[j->v] - dp[j->v];
		}
		else {
			if ( siz[j->v] - dp[j->v] < siz[best->v] - dp[best->v] ) best = j;
		}
	}
	if ( !g[i] ) {
		dp[i] = 1;
		siz[i] = 1;
	}
	else {
		if ( kind[i] == 0 ) {
			dp[i] = siz[i] - sum - son + 1;
		}
		else {
			dp[i] = siz[i] - (siz[best->v]-dp[best->v]);
		}
	}
}
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &kind[i] );
	for ( i = 2 ; i <= n ; i++ ) {
		scanf ( "%d" , &fa[i] );
		add ( fa[i] , i );
	}
	dfs ( 1 );
	printf ( "%d\n" , dp[1] );
}
int main () {
	work ();
	return 0;
}