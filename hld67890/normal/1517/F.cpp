#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
const long long inv2 = 499122177;
struct node {
	long long v;
	node *next;
} pool[2100] , *g[2100];
long long top;
long long n;
long long dp[310][3][310] , dep[310];
long long tmp[3][310] , res[3][310];
long long cnt[310] , ans;
void add ( long long u , long long v ) {
	node *tmp = &pool[++top];
	tmp -> v = v; tmp -> next = g[u]; g[u] = tmp;
}
void dfs ( long long i , long long from , long long r ) {
	long long k , l;
	dp[i][0][0] = 1;
	dp[i][1][r] = 1;
	dep[i] = 1;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		dfs ( j -> v , i , r );
		tmp[0][0] = dp[j->v][1][0];
		for ( k = 0 ; k < r ; k++ ) {
			tmp[0][k+1] = dp[j->v][0][k];
		}
		for ( k = 1 ; k <= r ; k++ ) {
			tmp[1][k-1] = dp[j->v][1][k];
		}
		tmp[1][r] = 0;
		for ( k = 0 ; k <= r ; k++ ) {
			res[0][k] = res[1][k] = 0;
		}
		
		for ( k = 0 ; k <= r && k <= dep[i] ; k++ )
			for ( l = 0 ; l <= r && l <= dep[j->v] + 1 ; l++ )
				res[0][max(k,l)] = (res[0][max(k,l)] + dp[i][0][k] * tmp[0][l]) % mod;
		for ( k = max(r-dep[i],0ll) ; k <= r ; k++ )
			for ( l = max(r - dep[j->v] - 1,0ll) ; l <= r ; l++ )
				res[1][max(k,l)] = (res[1][max(k,l)] + dp[i][1][k] * tmp[1][l]) % mod;
		for ( k = max(r-dep[i],0ll) ; k <= r ; k++ )
			for ( l = 0 ; l <= r && l <= dep[j->v] + 1 ; l++ )
				if ( k >= l ) {
					res[1][k] = (res[1][k] + dp[i][1][k] * tmp[0][l]) % mod;
				}
				else {
					res[0][l] = (res[0][l] + dp[i][1][k] * tmp[0][l]) % mod;
				}
		for ( k = 0 ; k <= r && k <= dep[i] ; k++ )
			for ( l = max(r - dep[j->v] - 1,0ll) ; l <= r ; l++ )
				if ( l >= k ) {
					res[1][l] = (res[1][l] + dp[i][0][k] * tmp[1][l]) % mod;
				}
				else {
					res[0][k] = (res[0][k] + dp[i][0][k] * tmp[1][l]) % mod;
				}
		for ( k = 0 ; k <= r ; k++ ) {
			dp[i][0][k] = res[0][k];
			dp[i][1][k] = res[1][k];
		}
		dep[i] = max ( dep[i] , dep[j->v] + 1 );
	}
	//printf ( "dep %lld %lld\n" , i , dep[i] );
}
long long solve ( long long x ) {
	long long i , j , ret;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) {
			dp[i][0][j] = dp[i][1][j] = 0;
		}
		dep[i] = 0;
	}
	dfs ( 1 , -1 , x );
	ret = 0;
	for ( i = 0 ; i <= x ; i++ ) {
		ret = (ret + dp[1][1][i]) % mod;
	}
	//printf ( "x%lld ret%lld\n" , x , ret );
	return ret;
}
void work () {
	long long i , u , v;
	//n = 300;
	scanf ( "%lld" , &n );
	for ( i = 1 ; i < n ; i++ ) {
		//u = i + 1;
		//v = rand () % i + 1;
		scanf ( "%lld%lld" , &u , &v );
		add ( u , v ); add ( v , u );
	}
	for ( i = 0 ; i <= n ; i++ ) {
		cnt[i] = solve ( i );
		if ( i == 0 ) ans = (ans + (cnt[i]-0) * (-1)) % mod;
		else ans = (ans + (cnt[i]-cnt[i-1])*(i-1)) % mod;
	}
	ans = (ans + n) % mod;
	for ( i = 1 ; i <= n ; i++ ) {
		ans = (ans * inv2) % mod;
	}
	printf ( "%lld\n" , (ans+mod)%mod );
}
int main () {
	work ();
	return 0;
}