#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 510000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n , m , k;
int dep[maxn] , fa[maxn];
int vis[maxn];
int leaf[maxn];
int r[maxn][5];
int ans[maxn];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int from ) {
	vis[i] = 1;
	int s = 0;
	for ( node *j = g[i] ; j ; j = j -> next ) {
		if ( vis[j->v] ) {
			if ( s <= 2 ) r[i][++s] = j -> v;
		}
		else {
			if ( j -> v != from ) {
				dep[j->v] = dep[i] + 1;
				fa[j->v] = i;
				leaf[i] = -1;
				dfs ( j -> v , i );
			}
		}
	}
	if ( leaf[i] == 0 ) {
		if ( dep[r[i][1]] > dep[r[i][2]] ) swap ( r[i][1] , r[i][2] );
		if ( dep[r[i][1]] > dep[r[i][3]] ) swap ( r[i][1] , r[i][3] );
		if ( dep[r[i][2]] > dep[r[i][3]] ) swap ( r[i][2] , r[i][3] );
	}
}
void output ( int i , int a , int b ) {
	int cnt = 0;
	ans[++cnt] = i;
	while ( a != b ) {
		ans[++cnt] = b;
		b = fa[b];
	}
	ans[++cnt] = a;
	printf ( "%d\n" , cnt );
	for ( i = 1 ; i <= cnt ; i++ ) printf ( "%d%c" , ans[i] , i==cnt?'\n':' ' );
}
void work () {
	int i , u , v , cnt;
	scanf ( "%d%d%d" , &n , &m , &k );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dep[1] = 1;
	dfs ( 1 , -1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( dep[i] >= (n - 1) / k + 1 ) {
			printf ( "PATH\n" );
			printf ( "%d\n" , dep[i] );
			while ( i != 1 ) {
				printf ( "%d " , i );
				i = fa[i];
			}
			printf ( "%d\n" , i );
			return ;
		}
	}
	cnt = 0;
	printf ( "CYCLES\n" );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( leaf[i] != -1 ) {
			if ( cnt >= k ) break;
			cnt++;
			if ( (dep[r[i][2]] - dep[r[i][1]]) % 3 != 1 ) {
				output ( i , r[i][1] , r[i][2] );
			}
			else {
				if ( (dep[r[i][3]] - dep[r[i][2]]) % 3 != 1 ) {
					output ( i , r[i][2] , r[i][3] );
				}
				else {
					output ( i , r[i][1] , r[i][3] );
				}
			}
		}
	}
}
int main () {
	work ();
	return 0;
}