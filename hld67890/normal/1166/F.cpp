#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 120000;
int n , m , color , q;
map < pair<int,int> , int > ma;
map < int , int > vis[maxn];
int c[maxn];
char op[100];
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
	x = find ( x ); y = find ( y );
	if ( x == y ) return ;
	if ( vis[-c[x]].size () > vis[-c[y]].size() ) {
		for ( auto it = vis[-c[y]].begin() ;  it != vis[-c[y]].end () ; it++ )
			if ( it -> second == 1 ) vis[-c[x]][it->first] = 1;
		c[y] = x;
	}
	else {
		for ( auto it = vis[-c[x]].begin() ;  it != vis[-c[x]].end () ; it++ )
			if ( it -> second == 1 ) vis[-c[y]][it->first] = 1;
		c[x] = y;
	}
}
void add ( int u , int v , int z ) {
	//printf ( "@%d %d %d\n" , u , v, z );
	if ( ma[make_pair(u,z)] == 0 ) {
		ma[make_pair(u,z)] = v;
	}
	else {
		Union ( ma[make_pair(u,z)] , v );
	}
	vis[-c[find(u)]][v] = 1;
	if ( ma[make_pair(v,z)] == 0 ) {
		ma[make_pair(v,z)] = u;
	}
	else {
		Union ( ma[make_pair(v,z)] , u );
	}
	//printf ( "!%d %d\n" , ma[make_pair(u,z)] , ma[make_pair(v,z)] );
	vis[-c[find(v)]][u] = 1;
}
void work () {
	int i , u , v , z;
	scanf ( "%d%d%d%d" , &n , &m , &color , &q );
	for ( i = 1 ; i <= n ; i++ ) {
		c[i] = -i;
		vis[i][i] = 1;
	}
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d%d" , &u , &v , &z );
		add ( u , v , z );
	}
	//printf ( "@@%d %d\n" , vis[2][4] );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s" , op + 1 );
		if ( op[1] == '?' ) {
			scanf ( "%d%d" , &u , &v );
			if ( vis[-c[find(u)]][v] == 1 ) printf ( "Yes\n" );
			else printf ( "No\n" );
		}
		else {
			scanf ( "%d%d%d" , &u , &v , &z );
			add ( u , v , z );
		}
	}
}
int main () {
	work ();
	return 0;
}