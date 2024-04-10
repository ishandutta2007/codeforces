#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
struct node {
	long long v;
	node *next;
} pool[420000] , *g[220000];
long long top;
long long n;
long long a[220000] , s[220000] , siz[220000] , w[220000] , index;
long long maxx[220000];
long long ans;
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from ) {
	w[i] = ++index;
	siz[i] = 1;
	s[i] = a[i];
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		siz[i] += siz[j->v];
		s[i] += s[j->v];
	}
	maxx[w[i]] = s[i];
}
void work () {
	long long i , u , v;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%I64d%I64d" , &u , &v );
		add ( u , v );
		add ( v , u );
	}
	dfs ( 1 , 0 );
	for ( i = n - 1 ; i >= 1 ; i-- ) maxx[i] = max ( maxx[i] , maxx[i+1] );
	ans = -21474836477777777ll;
	for ( i = 1 ; i <= n ; i++ ) {
		if ( w[i] + siz[i] - 1 < n ) {
			//printf ( "%d %d\n" , s[i] , maxx[w[i]+siz[i]] );
			ans = max ( ans , s[i] + maxx[w[i]+siz[i]] );
		}
	}
	if ( ans == -21474836477777777ll ) printf ( "Impossible\n" );
	else printf ( "%I64d\n" , ans );
}
int main () {
	//FILE *fpr = freopen ( "d.in" , "r" , stdin );
	work ();
	return 0;
}