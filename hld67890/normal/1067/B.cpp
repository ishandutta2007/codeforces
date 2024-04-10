#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 120000;
struct node {
	int v;
	node *next;
} pool[maxn*2] , *g[maxn];
int top;
int n , k;
int taboo[maxn] , tot;
int deg[maxn];
map < int , int > m , tmp;
map < int , int >::iterator it;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void work () {
	int i , u , v , f;
	scanf ( "%d%d" , &n , &k );
	if ( n == 1 ) {
		printf ( "No\n" );
		return ;
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v ); add ( v , u );
		deg[u]++; deg[v]++;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( deg[i] == 1 ) {
			m[i] = 1;
		}
	}
	for ( i = 1 ; tot < n ; i++ ) {
		tmp.clear ();
		for ( it = m.begin () ; it != m.end () ; it++ ) {
			//printf ( "%d " , it -> first );
			taboo[it->first] = 1;
			tot++;
			f = 0;
			for ( node *j = g[it->first] ; j ; j = j -> next ) {
				if ( !taboo[j->v] ) {
					tmp[j->v]++;
					if ( f == 1 ) {
						printf ( "No\n" );
						return ;
					}
					f = 1;
				}
			}
		}
		m.clear ();
		for ( it = tmp.begin () ; it != tmp.end () ; it++ ) {
			if ( it -> second < 3 ) {
				printf ( "No\n" );
				return ;
			}
			m[it->first] = 1;
		}
		//printf ( "\n" );
	}
	//printf ( "%d\n" , i );
	if ( i == k + 2 ) printf ( "Yes\n" );
	else printf ( "No\n" );
}
int main () {
	work ();
	return 0;
}