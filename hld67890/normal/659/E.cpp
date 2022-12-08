#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node {
	int v , f;
	node *next , *rev;
} pool[1000000] , *g[600000];
int top;
int n , m;
int level[600000];
void add ( int u , int v , int f ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	tmp1 -> v = v; tmp1 -> f = f; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> f = 0; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
bool makelevel () {
	int i , k;
	queue < int > q;
	for ( i = 1 ; i <= 1 + n + m + 1 ; i++ ) level[i] = -1;
	level[1] = 1; q.push ( 1 );
	while ( q.size () != 0 ) {
		k = q.front (); q.pop ();
		for ( node *j = g[k] ; j ; j = j -> next )
			if ( j -> f && level[j -> v] == -1 ) {
				level[j -> v] = level[k] + 1;
				if ( j->v == 1 + n + m + 1 ) return true;
				q.push ( j -> v );
			}
	}
	return false;
}
int find ( int k , int key ) {
	if ( k == 1 + n + m + 1 ) return key;
	int i , s = 0;
	for ( node *j = g[k] ; j ; j = j -> next )
		if ( j -> f && level[j -> v] == level[k] + 1 && s < key ) {
			i = find ( j -> v , min ( key - s , j -> f ) );
			j -> f -= i;
			j -> rev -> f += i;
			s += i;
		}
	if ( s == 0 ) level[k] = -1;
	return s;
}
void dinic () {
	int ans = 0;
	while ( makelevel () == true ) ans += find ( 1 , 999999 );
	printf ( "%d\n" , n - ans );
}
void work () {
	int i , x , y;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &x , &y );
		add ( 1 , 1 + i , 1 );
		add ( 1 + i , 1 + m + x , 1 );
		add ( 1 + i , 1 + m + y , 1 );
	}
	for ( i = 1 ; i <= n ; i++ ) add ( 1 + m + i , 1 + m + n + 1 , 1 );
	dinic ();
}
int main () {
	work ();
	return 0;
}