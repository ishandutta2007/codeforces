#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 510000;
const long long mod = 998244353;
struct node {
	long long v;
	node *next;
} pool[maxn*2] , *g[maxn];
long long top;
long long n;
long long pw[maxn];
long long dp[maxn] , siz[maxn];
long long ans;
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from ) {
	long long tmp = 1;
	siz[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i );
		siz[i] += siz[j->v];
		tmp = ( tmp * ( (dp[j->v]+pw[siz[j->v]-1]) % mod ) ) % mod;
	}
	dp[i] = ( pw[siz[i]-1] - tmp + mod ) % mod;
}
void work () {
	long long i , u , v;
	scanf ( "%I64d" , &n );
	pw[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		pw[i] = (pw[i-1]*2) % mod;
	}
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%I64d%I64d" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	dfs ( 1 , -1 );
	for ( i = 1 ; i <= n ; i++ ) ans = ( ans + dp[i] * pw[n-siz[i]] ) % mod;
	printf ( "%I64d\n" , ( ans * 2 ) % mod );
}
int main () {
	work ();
	return 0;
}