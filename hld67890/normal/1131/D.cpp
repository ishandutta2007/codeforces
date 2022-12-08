#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1200;
struct node {
	int v;
	node *next;
} pool[maxn*maxn*2] , *g[maxn*2];
int top;
int n , m;
char z[maxn][maxn];
int c[maxn*2];
int in[maxn*2];
int ans[maxn*2] , vis[maxn*2];
queue < int > q;
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ) {
	if ( x == y ) return ;
	c[x] = y;
}
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
	in[v]++;
}
void work () {
	int i , j , k;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n + m ; i++ ) c[i] = -1;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z[i] + 1 );
		for ( j = 1 ; j <= m ; j++ ) {
			if ( z[i][j] == '=' ) {
				Union ( find ( i ) , find ( n + j ) );
			}
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			if ( z[i][j] == '<' ) {
				add ( find ( i ) , find ( n + j ) );
			}
			if ( z[i][j] == '>' ) {
				add ( find ( n + j ) , find ( i ) );
			}
		}
	}
	for ( i = 1 ; i <= n + m ; i++ ) if ( c[i] < 0 && in[i] == 0 ) {
		q.push ( i );
		ans[i] = 1;
	}
	while ( q.size () ) {
		k = q.front (); q.pop ();
		vis[k] = 1;
		for ( node *j = g[k] ; j ; j = j -> next ) {
			in[j->v]--;
			ans[j->v] = max ( ans[j->v] , ans[k] + 1 );
			if ( in[j->v] == 0 ) {
				q.push ( j -> v );
			}
		}
	}
	for ( i = 1 ; i <= n + m ; i++ ) {
		if ( vis[i] == 0 && c[i] < 0 ) {
			printf ( "No\n" );
			return ;
		}
	}
	printf ( "Yes\n" );
	for ( i = 1 ; i <= n ; i++ ) printf ( "%d%c" , ans[find(i)] , i==n?'\n':' ' );
	for ( i = 1 ; i <= m ; i++ ) printf ( "%d%c" , ans[find(n+i)] , i==m?'\n':' ' );
}
int main () {
	work ();
	return 0;
}