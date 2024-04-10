#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 998244353;
struct node {
	int v;
	node *l , *r;
} l[220000] , *g[220000] , *del;
int n , k;
int a[220000] , b[220000];
int ex[210000];
int ans , way;
void work () {
	int i;
	scanf ( "%d%d" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
		l[i].v = a[i];
		if ( i != 1 ) l[i].l = &l[i-1];
		else l[i].l = NULL;
		if ( i != n ) l[i].r = &l[i+1];
		else l[i].r = NULL;
		g[a[i]] = &l[i];
		ex[i] = 0;
	}
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%d" , &b[i] );
		ex[b[i]] = 1;
	}
	ans = 1;
	for ( i = 1 ; i <= k ; i++ ) {
		way = 0;
		del = NULL;
		if ( g[b[i]] -> l ) {
			if ( !ex[g[b[i]]->l->v] ) {
				way++;
				del = g[b[i]] -> l;
			}
		}
		if ( g[b[i]] -> r ) {
			if ( !ex[g[b[i]]->r->v] ) {
				way++;
				del = g[b[i]] -> r;
			}
		}
		ans = (ans*way) % mod;
		if ( del ) {
			if ( del -> l ) del -> l -> r = del -> r;
			if ( del -> r ) del -> r -> l = del -> l;
		}
		ex[b[i]] = 0;
	}
	printf ( "%d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}