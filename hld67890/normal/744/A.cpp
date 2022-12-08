#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *next;
} pool[220000] , *g[1200];
int top;
int n , m , k;
int c[1200];
int col[1200] , index , sum;
int sumc[1200];
int ans;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from , int color ) {
	col[i] = color;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && col[j->v] == 0 ) {
		dfs ( j -> v , i , color );
	}
}
void work () {
	int i , u , v , maxi;
	scanf ( "%d%d%d" , &n , &m , &k );
	for ( i = 1 ; i <= k ; i++ ) scanf ( "%d" , &c[i] );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	index = 0;
	for ( i = 1 ; i <= k ; i++ ) {
		dfs ( c[i] , 0 , ++index );
	}
	sum = 0;
	for ( i = 1 ; i <= n ; i++ )
		if ( col[i] == 0 ) sum++;
		else sumc[col[i]]++;
	maxi = 1;
	for ( i = 2 ; i <= index ; i++ ) if ( sumc[i] > sumc[maxi] ) maxi = i;
	sumc[maxi] += sum;
	for ( i = 1 ; i <= index ; i++ ) {
		ans += sumc[i] * (sumc[i]-1) / 2;
	}
	ans -= m;
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}