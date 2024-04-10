#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *next;
} pool[220000] , *g[12000];
int top;
int n , m , n1 , n2 , n3;
int col[5100] , blk[5100] , cnt;
int c1[5100] , c2[5100];
int blkcol[5100];
int dp[5100][5100];
bool flag;
char ans[5200];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( int i , int color , int from ) {
	blk[i] = cnt;
	col[i] = color;
	if ( color == 1 ) c1[cnt]++;
	else c2[cnt]++;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( col[j->v] == col[i] ) {
			flag = false;
			return ;
		}
		else {
			if ( !col[j->v] ) {
				dfs ( j -> v , 3 - color , i );
			}
		}
	}
}
void work () {
	int i , j , u , v;
	scanf ( "%d%d" , &n , &m );
	scanf ( "%d%d%d" , &n1 , &n2 , &n3 );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	flag = true;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( !col[i] ) {
			cnt++;
			dfs ( i , 1 , -1 );
		}
	}
	if ( flag == false ) {
		printf ( "NO\n" );
		return ;
	}
	dp[0][0] = 1;
	for ( i = 1 ; i <= cnt ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) {
			if ( dp[i-1][j] ) {
				dp[i][j+c1[i]] = 1;
				dp[i][j+c2[i]] = 2;
			}
		}
	}
	if ( dp[cnt][n2] != 0 ) {
		i = cnt; j = n2;
		while ( j ) {
			if ( dp[i][j] == 1 ) {
				j -= c1[i];
				blkcol[i] = 1;
			}
			else {
				j -= c2[i];
				blkcol[i] = 2;
			}
			i--;
		}
		printf ( "YES\n" );
		for ( i = 1 ; i <= n ; i++ ) {
			if ( blkcol[blk[i]] == col[i] ) {
				ans[i] = '2';
			}
			else ans[i] = '1';
		}
		for ( i = 1 ; n1 && i <= n ; i++ ) {
			if ( ans[i] == '1' ) n1--;
		}
		for ( i ; i <= n ; i++ ) {
			if ( ans[i] == '1' ) ans[i] = '3';
		}
		printf ( "%s\n" , ans + 1 );
	}
	else {
		printf ( "NO\n" );
	}
}
int main () {
	work ();
	return 0;
}