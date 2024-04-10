#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1200000;
struct node {
	int v;
	node *next;
} pool[maxn] , *g[maxn];
int top;
int n , m;
int taboo[maxn];
int s[maxn] , tops;
int ans[maxn] , topa;
void add ( int u , int v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void work () {
	int i , u , v;
	scanf ( "%d%d" , &n , &m );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%d%d" , &u , &v );
		add ( u , v );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( !taboo[i] ) {
			s[++tops] = i;
			for ( node *j = g[i] ; j ; j = j -> next ) taboo[j->v] = 1;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) taboo[i] = 0;
	for ( i = tops ; i >= 1 ; i-- ) {
		if ( !taboo[s[i]] ) {
			ans[++topa] = s[i];
			for ( node *j = g[s[i]] ; j ; j = j -> next ) taboo[j->v] = 1;
		}
	}
	printf ( "%d\n" , topa );
	for ( i = 1 ; i <= topa ; i++ ) printf ( "%d%c" , ans[i] , i==topa?'\n':' ' );
}
int main () {
	work ();
	return 0;
}