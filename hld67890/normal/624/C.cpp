#include <iostream>
#include <stdio.h>

using namespace std;

int n , m , map[510][510];
int c[510];
int g[510][510] , cnt , col[510];
int vis[510] , flag;
int stack[510] , top;
int coloring , ans[510];
char z[510];
int find ( int x ) {
	int i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] );
	while ( c[x] > 0 ) {
		t = c[x];
		c[x] = i;
		x = t;
	}
	return i;
}
void Union ( int x , int y ){
	if ( x == y ) return ;
	c[x] += c[y];
	c[y] = x;
}
void dfs ( int i , int fa ) {
	stack[++top] = i;
	vis[i] = 1;
	int j , s = 0;
	for ( j = 1 ; j <= cnt ; j++ ) {
		if ( g[i][j] && vis[j] == 0 ) {
			s++;
			dfs ( j , 1 );
		}
	}
	if ( (s > 1 && fa == 1) || (s > 2 && fa == 0) ) flag = 0;
}
void color ( int i ) {
	ans[i] = coloring++;
	//cout << i << " " << ans[i]<<endl;
	int j;
	for ( j = 1 ; j <= cnt ; j++ ) {
		if ( g[i][j] && ans[j] == 0 ) {
			color ( j );
		}
	}
}
void work () {
	int i , j , k , a , b , f , sum= 0;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) map[i][i] = 1, c[i] = -1;
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &a , &b );
		map[a][b] = map[b][a] = 1;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = i + 1 ; j <= n ; j++ ) {
			f = 1;
			for ( k = 1 ; k <= n ; k++ ) if ( map[i][k] != map[j][k] ) {
				f = 0;
				break;
			}
			if ( f == 1 ) Union ( find ( i ) , find ( j ) );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) if ( c[i] < 0 ) col[i] = ++cnt;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( map[i][j] ) {
				if ( find ( i ) != find ( j ) ) g[col[find(i)]][col[find(j)]] = g[col[find(j)]][col[find(i)]] = 1;
			}
		}
	}
	//for  ( i = 1 ; i <= n ; i++ ) cout << col[i] << " ";
	//cout << endl;
	//for ( i = 1 ; i <= n ; i++,cout << endl ) for ( j = 1  ; j <= n ; j++ ) cout <<g[i][j] << " ";
	//cout << endl;
	flag = 1;
	sum = -1;
	for ( i = 1 ; i <= cnt ; i++ ) {
		if ( vis[i] == 0 ) { sum++; dfs ( i , 0 );}
	}
	//cout << cnt << " " << sum << endl;
	if ( cnt + sum > 3 ) {
		printf ( "NO\n" );
		return ;
	}
	if ( flag == 0 ) {
		printf ( "NO\n" );
		return ;
	}
	for ( i = top ; i >= 1 ; i-- ) {
		coloring++;
		if ( ans[stack[i]] == 0 ) color ( stack[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		z[i] = 'a' - 1 + ans[col[find(i)]];
	}
	printf ( "YES\n" );
	printf ( "%s\n" , z + 1 );
	//for  ( i = 1 ; i <= n ; i++ ) cout << ans[i] << " ";
	//cout << endl;
	//for  ( i = 1 ; i <= top ; i++ ) cout << stack[i] << " ";
}
int main () {
	work ();
	return 0;
}