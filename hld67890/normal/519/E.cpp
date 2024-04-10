#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int v;
	node *next;
} pool[310000] , *g[200000];
int top;
int n , m;
int fa[200000] , dis[200000] , sum[200000];
int go[20][110000];
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v;
	tmp -> next = g[u];
	g[u] = tmp;
}
void dfs ( int id , int d , int from ) {
	fa[id] = from; dis[id] = d;
	sum[id] = 1;
	for ( node *j = g[id] ; j ; j = j -> next ) {
		if ( sum[j -> v] == 0 ) {
			dfs ( j -> v , d + 1 , id );
			sum[id] += sum[j -> v];
		}
	}
}
void prepare () {
	int i , j;
	for ( i = 1 ; i <= n ; i++ ) go[0][i] = fa[i];
	for ( i = 1 ; i <= 17 ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			go[i][j] = go[i - 1][go[i - 1][j]];
		}
	}
}
int jump ( int a , int d ) {
	int i = 0;
	while ( d ) {
		if ( d % 2 == 1 ) a = go[i][a];
		i++;
		d >>= 1;
	}
	return a;
}
int lca ( int a , int b ) {
	int t;
	if ( dis[a] < dis[b] ) swap ( a , b );
	a = jump ( a , dis[a] - dis[b] );
	if ( a == b ) return a;
	t = 18;
	while ( t ) {
		if ( go[t - 1][a] != go[t - 1][b] ) {
			a = go[t - 1][a];
			b = go[t - 1][b];
		}
		t--;
	}
	if ( a == b ) return a;
	else return fa[a];
}
void work () {
	int i , u , v , a , b , t , tmp , tmp1 , tmp2 , ans;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v );
		add ( v , u );
	}
	dfs ( 1  , 0 , 0 );
	prepare ();
	scanf ( "%d" , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &a , &b );
		if ( a == b ) { cout << sum[1] << endl; continue; }
		if ( ( dis[a] + dis[b] ) % 2 == 1 ) { printf ( "0\n" ); continue; }
		t = lca ( a , b );
		if ( t == a ) {
			tmp = jump ( b , ( dis[b] - dis[a] ) / 2 - 1 );
			printf ( "%d\n" , sum[fa[tmp]] - sum[tmp] );
		}
		else {
			if ( t == b ) {
				tmp = jump ( a , ( dis[a] - dis[b] ) / 2 - 1 );
				printf ( "%d\n" , sum[fa[tmp]] - sum[tmp] );
			}
			else {
				if ( dis[a] == dis[b] ) {
					tmp1 = jump ( a , ( dis[a] - dis[t] + dis[b] - dis[t] ) / 2 - 1 );
					tmp2 = jump ( b , ( dis[a] - dis[t] + dis[b] - dis[t] ) / 2 - 1 );
					ans = sum[1] - sum[tmp1] - sum[tmp2];
				}
				else {
					if ( dis[a] > dis[b] ) {
						tmp1 = jump ( a , ( dis[a] - dis[t] + dis[b] - dis[t] ) / 2 - 1 );
						ans = sum[fa[tmp1]] - sum[tmp1];
					}
					else {
						tmp2 = jump ( b , ( dis[a] - dis[t] + dis[b] - dis[t] ) / 2 - 1 );
						ans = sum[fa[tmp2]] - sum[tmp2];
					}
				}
				printf ( "%d\n" , ans );
			}
		}
	}
}
int main () {
	work ();
	return 0;
}