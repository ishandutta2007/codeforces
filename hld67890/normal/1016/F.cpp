#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 310000;
struct node {
	long long v , c;
	node *next;
} pool[maxn*2] , *g[maxn];
long long top;
long long n , m;
long long fa[maxn] , siz[maxn];
long long imp[maxn];
long long dis[maxn] , far[maxn] , rdis[maxn] , rfar[maxn];
long long f1;
long long ans , flag;
void add ( long long u , long long v , long long c ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> c = c; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( long long i , long long from ) {
	siz[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		fa[j->v] = i;
		dfs1 ( j -> v , i );
		siz[i] += siz[j->v];
	}
}
void dfs2 ( long long i , long long from ) {
	node *son = NULL;
	far[i] = dis[i];
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( imp[j->v] ) son = j;
		else {
			dis[j->v] = dis[i] + j -> c;
			dfs2 ( j -> v , i );
			far[i] = max ( far[i] , far[j->v] );
		}
	}
	if ( son ) {
		dis[son->v] = dis[i] + son -> c;
		if ( siz[i] - siz[son->v] > 2 ) {
			flag = 1;
		}
		dfs2 ( son -> v , i );
	}
}
void dfs3 ( long long i , long long from ) {
	node *son = NULL;
	rfar[i] = rdis[i];
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		if ( imp[j->v] ) son = j;
		else {
			rdis[j->v] = rdis[i] + j -> c;
			dfs3 ( j -> v , i );
			rfar[i] = max ( rfar[i] , rfar[j->v] );
		}
	}
	if ( son ) {
		rdis[son->v] = rdis[i] + son -> c;
		dfs3 ( son -> v , i );
	}
}
void work () {
	long long i , u , v , c;
	scanf ( "%I64d%I64d" , &n , &m );
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%I64d%I64d%I64d" , &u , &v , &c );
		add ( u , v , c ); add ( v , u , c );
	}
	dfs1 ( 1 , 0 );
	i = n;
	while ( i != 1 ) {
		imp[i] = 1;
		i = fa[i];
	}
	imp[1] = 1;
	dfs2 ( 1 , 0 );
	dfs3 ( n , 0 );
	if ( siz[n] >= 3 ) flag = 1;
	ans = 0;
	f1 = -214748364777777777ll;
	//for ( i = 1 ; i <= n ; i++ ) {
	//	printf ( "%I64d %I64d %I64d\n" , i , far[i] , rfar[i] );
	//}
	i = n;
	while ( i != 1 ) {
		if ( !(rfar[i] == rdis[i] && far[fa[i]] == dis[fa[i]]) ) f1 = max ( f1 , rfar[i] );
		ans = max ( ans , f1 + far[fa[i]] );
		//printf ( "%I64d %I64d %I64d\n" , i , f1 , far[fa[i]] );
		f1 = max ( f1 , rfar[i] );
		i = fa[i];
	}
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d" , &c );
		if ( flag == 0 ) printf ( "%I64d\n" , min ( dis[n] , ans + c ) );
		else printf ( "%I64d\n" , dis[n] );
	}
}
int main () {
	work ();
	return 0;
}