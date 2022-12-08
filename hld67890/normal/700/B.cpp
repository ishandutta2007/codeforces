#include <iostream>
#include <stdio.h>

using namespace std;

//long long
struct node {
	long long v;
	node *next;
} pool[500000] , *g[300000];
long long top;
long long n , k;
long long a[300000] , s[300000] , vis[300000] , c[300000] , dep[300000];
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs1 ( long long i ) {
	s[i] = a[i]; vis[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) {
		if ( !vis[j->v] ) {
			dep[j->v] = dep[i] + 1;
			dfs1 ( j -> v );
			s[i] += s[j->v];
		}
	}
}
void dfs2 ( long long i , long long del ) {
	long long sum = a[i] , maxx = 0;
	node *tmp;
	if ( !g[i] ) {
		c[i] = s[i] - del;
		return ;
	}
	for ( node *j = g[i] ; j ; j = j -> next ) {
		if ( dep[j->v] < dep[i] ) continue;
		sum += s[j->v];
		if ( s[j->v] > maxx ) {
			maxx = s[j->v];
			tmp = j;
		}
	}
	sum -= maxx;
	//cout << i << " " << del << " " << sum << " " << maxx <<endl;
	if ( sum + del >= maxx ) {
		c[i] = (sum+maxx-del) / 2;
		return ;
	}
	else {
		c[i] = sum;
		dfs2 ( tmp -> v , del + sum );
	}
}
void work () {
	long long i , u , v , ans;
	scanf ( "%I64d%I64d" , &n , &k );
	for ( i = 1 ; i <= 2 * k ; i++ ) {
		scanf ( "%I64d" , &u );
		a[u] = 1;
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%I64d%I64d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dep[1] = 0;
	dfs1 ( 1 );
	dfs2 ( 1 , 0 );
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		//cout << a[i] << " " << c[i] << " " << s[i] << endl;
		ans += a[i] * dep[i];
		ans -= c[i] * dep[i] * 2;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}