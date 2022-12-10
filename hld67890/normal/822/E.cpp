#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long NN = 120000;
const long long c = 23333;
const long long mod = 998244353;
long long n , m , x;
char z1[NN] , z2[NN];
long long pre[3][NN] , po[NN];
long long dp[NN][34];
long long hashh ( long long kind , long long x , long long l ) {
	long long ret;
	ret = ( pre[kind][x+l-1] - ((pre[kind][x-1]*po[l])%mod) + mod ) % mod;
	return ret;
}
long long check ( long long x , long long y , long long l ) {
	if ( hashh ( 1 , x , l ) == hashh ( 2 , y , l ) ) return 1;
	return 0;
}
long long lcp ( long long x , long long y ) {
	long long l = 0 , r = min ( n-x+1 , m-y+1 ) , mid;
	if ( check ( x , y , l ) == 0 ) return 0;
	if ( check ( x , y , r ) == 1 ) return r;
	//printf ( "%I64d %I64d\n" , l , r );
	while ( l < r - 1 ) {
		mid = (l+r)/2;
		if ( check ( x , y , mid ) == 1 ) l = mid;
		else r = mid;
	}
	if ( check ( x , y , r ) == 1 ) return r;
	else return l;
}
void work () {
	long long i , j , tmp;
	scanf ( "%I64d" , &n );
	scanf ( "%s" , z1 + 1 );
	scanf ( "%I64d" , &m );
	scanf ( "%s" , z2 + 1 );
	scanf ( "%I64d" , &x );
	po[0] = 1;
	for ( i = 1 ; i <= n ; i++ ) {
		po[i] = (po[i-1] * c) % mod;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		pre[1][i] = (pre[1][i-1] * c + (z1[i]-'a')) % mod;
	}
	for ( i = 1 ; i <= m ; i++ ) {
		pre[2][i] = (pre[2][i-1] * c + (z2[i]-'a')) % mod;
	}
	z2[m+1] = '$';
	for ( i = 0 ; i <= n ; i++ ) for ( j = 0 ; j <= 30 ; j++ ) dp[i][j] = -999999;
	dp[0][0] = 0;
	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j <= x ; j++ ) {
			if ( dp[i][j] == -999999 ) continue;
			dp[i+1][j] = max ( dp[i+1][j] , dp[i][j] );
			tmp = lcp ( i + 1 , dp[i][j] + 1 );
			//printf ( "%I64d %I64d %I64d %I64d\n" , i , j , dp[i][j] , tmp );
			dp[i+tmp][j+1] = max ( dp[i+tmp][j+1] , dp[i][j] + tmp );
		}
	}
	for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= x ; j++ ) {
		//printf ( "%I64d %I64d %I64d\n" , i , j , dp[i][j] );
		if ( dp[i][j] == m ) {
			printf ( "YES\n" );
			return ;
		}
	}
	printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}