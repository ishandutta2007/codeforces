#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 5100;
long long n , k , x;
long long a[maxn];
long long dp[maxn][maxn];
long long q[maxn] , first , last;
long long ans;
void work () {
	long long i , j;
	scanf ( "%I64d%I64d%I64d" , &n , &k , &x );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	dp[0][0] = 0;
	for ( i = 1 ; i <= n ; i++ ) dp[0][i] = -21474836477777777ll;
	for ( i = 1 ; i <= x ; i++ ) {
		first = last = 1;
		q[1] = 0;
		for ( j = 1 ; j <= n ; j++ ) {
			while ( first <= last && j - q[first] > k ) first++;
			//printf ( "%I64d %I64d %I64d\n" , i , j , q[first] );
			if ( first <= last )
				dp[i][j] = dp[i-1][q[first]] + a[j];
			while ( first <= last && dp[i-1][j] >= dp[i-1][q[last]] ) last--;
			q[++last] = j;
		}
	}
	//for ( i = 1 ; i <= x ; i++ ) for ( j = 1 ; j <= n ; j++ ) printf ( "%I64d %I64d %I64d\n" , i , j , dp[i][j] );
	ans = -1;
	for ( i = n - k + 1 ; i <= n ; i++ ) ans = max ( ans , dp[x][i] );
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}