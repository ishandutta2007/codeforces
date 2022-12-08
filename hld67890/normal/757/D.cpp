#include <stdio.h>
#include <algorithm>

using namespace std;

//int
const int maxn = 101;
const int mod = 1000000007;
int  n;
char z[maxn];
int  a[maxn];
int  getnum[maxn][maxn];
int dp[maxn][(1<<20)+5];
int  ans;
void work () {
	int i , j , k , tmp , t;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	for ( i = 1 ; i <= n ; i++ ) a[i] = z[i] - '0';
	for ( i = 1 ; i <= n ; i++ ) {
		tmp = 0;
		for ( j = i ; j <= n ; j++ ) {
			tmp = tmp * 2 + a[j];
			if ( tmp > 20 ) break;
			getnum[i][j] = tmp;
			//printf ( "%I64d %I64d %I64d\n" , i , j , getnum[i][j] );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		dp[i][0]++;
		for ( j = 0 ; j <= (1<<20) - 1 ; j++ ) {
			if ( dp[i][j] == 0 ) {
				continue;
			}
			for ( k = i ; k <= n ; k++ ) {
				t = getnum[i][k];
				if ( t > 20 ) break;
				if ( t == 0 ) continue;
				dp[k+1][j|(1<<(t-1))] = (dp[k+1][j|(1<<(t-1))] + dp[i][j]);
				if ( dp[k+1][j|(1<<(t-1))] >= mod ) dp[k+1][j|(1<<(t-1))] -= mod;
				//if ( j <= 5 ) printf ( "%d %d %d %d %d\n" , i , j , k , j|(1<<(getnum[k][i]-1)) , getnum[k][i] );
			}
		}
	}
	//for ( i = 1 ; i <= n ; i++ ,printf("\n")) for ( j = 0 ; j <= (1<<3) - 1 ; j++ ) printf ( "%d " , dp[i][j] );
	for ( i = 0 ; i <= n + 1 ; i++ ) {
		for ( j = 1 ; j <= (1<<20) - 1 ; j = j * 2 + 1 ) ans = (ans + dp[i][j]) % mod;
		//printf ( "%d\n" , ans );
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}