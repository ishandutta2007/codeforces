#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 3200000;
int le , ri , p;
int flag[120] , prime[120] , top;
int x[maxn] , tot;
int ok[maxn];
int dp[maxn];
int ans;
void dfs ( int s , int f ) {
	if ( f >= 1 ) {
		if ( (long long)s * prime[f] <= (long long)ri ) {
			x[++tot] = s * prime[f];
			dfs ( s * prime[f] , f );
		}
	}
	if ( f < top ) dfs ( s , f + 1 );
}
void work () {
	int i , j , k;
	scanf ( "%d%d%d" , &le , &ri , &p );
	for ( i = 2 ; i <= 100 ; i++ ) {
		if ( !flag[i] ) {
			prime[++top] = i;
		}
		for ( j = 1 ; j <= top ; j++ ) {
			if ( i * prime[j] > 100 ) break;
			flag[i*prime[j]] = 1;
			if ( i % prime[j] == 0 ) break;
		}
	}
	dfs ( 1 , 0 );
	//printf ( "%d\n" , tot );
	sort ( x + 1 , x + 1 + tot );
	x[0] = 1;
	ans = 0;
	for ( j = 1 ; j <= tot ; j++ ) dp[j] = 999;
	for ( i = 2 ; i < p ; i++ ) {
		k = 0;
		for ( j = 1 ; j <= tot ; j++ ) {
			if ( x[j] % i == 0 ) {
				while ( x[k] < x[j] / i ) k++;
				dp[j] = min ( dp[j] , dp[k]+1 );
				if ( dp[j] + i <= p ) ok[j] = 1;
			}
		}
	}
	//for ( j = 1 ; j <= 10 ; j++ ) printf ( "%d %d %d\n" , x[j] , dp[x[j]] , ok[j] );
	for ( j = 1 ; j <= tot ; j++ )
		if ( le <= x[j] ) {
			if ( ok[j] == 1 ) {
				ans++;
				//printf ( "%d\n" , x[j] );
			}
		}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}