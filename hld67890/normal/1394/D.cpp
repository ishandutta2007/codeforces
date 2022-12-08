#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	long long v;
	node *next;
} pool[420000] , *g[220000];
long long top;
long long n;
long long h[220000] , t[220000];
long long in[220000] , out[220000] , deg[220000];
long long vis[220000];
long long dp[3][220000];//0:fa->son  1:son->fa
long long ans;
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
long long get ( long long i , long long from , long long din , long long dout ) {
	long long ret = 0 , now , l;
	static long long a[220000] , cnt;
	din += in[i]; dout += out[i];
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && h[j->v] == h[i] ) {
		if ( dp[0][j->v] > dp[1][j->v] ) {
			dout++;
			ret += dp[0][j->v];
		}
		else {
			din++;
			ret += dp[1][j->v];
		}
	}
	now = ret + min ( din , dout ) * t[i];
	if ( din > dout ) {
		cnt = 0;
		for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && h[j->v] == h[i] ) {
			if ( dp[0][j->v] <= dp[1][j->v] ) {
				a[++cnt] = dp[1][j->v] - dp[0][j->v];
			}
		}
		sort ( a + 1 , a + 1 + cnt );
		l = 1;
		while ( din > dout && l <= cnt ) {
			ret -= a[l++];
			din--;
			dout++;
			now = max ( now , ret + min ( din , dout ) * t[i] );
		}
	}
	else {
		cnt = 0;
		for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && h[j->v] == h[i] ) {
			if ( dp[0][j->v] > dp[1][j->v] ) {
				a[++cnt] = dp[0][j->v] - dp[1][j->v];
			}
		}
		sort ( a + 1 , a + 1 + cnt );
		l = 1;
		while ( din < dout && l <= cnt ) {
			ret -= a[l++];
			din++;
			dout--;
			now = max ( now , ret + min ( din , dout ) * t[i] );
		}
	}
	//printf ( "%lld %lld %lld\n" , i , from , now );
	return now;
}
void dfs ( long long i , long long from ) {
	vis[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && h[i] == h[j->v] ) {
		dfs ( j -> v , i );
	}
	if ( from == -1 ) ans -= get ( i , from , 0 , 0 );
	else {
		dp[0][i] = get ( i , from , 1 , 0 );
		dp[1][i] = get ( i , from , 0 , 1 );
	}
}
void work () {
	long long i , u , v;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &t[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &h[i] );
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%lld%lld" , &u , &v );
		add ( u , v ); add ( v , u );
		deg[u]++; deg[v]++;
		if ( h[u] > h[v] ) {
			in[v]++;
			out[u]++;
		}
		if ( h[v] > h[u] ) {
			in[u]++;
			out[v]++;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		ans += t[i] * deg[i];
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( !vis[i] ) {
			dfs ( i , -1 );
		}
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}