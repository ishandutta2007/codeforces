#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 260000;
const long long maxm = 11000000;
long long n , m;
long long num[maxn];
long long lnum[maxn] , rnum[maxn] , cnt;
long long blockh[maxn] , blockc[maxn];
long long q;
long long h[maxm] , c[maxm];
long long ldown[maxm] , rdown[maxm];
long long st[maxm] , tops , sdp[maxm];
long long st2[maxm] , tops2 , sdp2[maxm];
long long dp[maxm];
void work () {
	long long i , j , id , mul , tmp;
	scanf ( "%I64d%I64d" , &n , &m );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &num[i] );
		lnum[i] = cnt + 1;
		for ( j = 1 ; j <= num[i] ; j++ ) {
			scanf ( "%I64d" , &blockh[cnt+j] );
		}
		for ( j = 1 ; j <= num[i] ; j++ ) {
			scanf ( "%I64d" , &blockc[cnt+j] );
		}
		cnt += num[i];
		rnum[i] = cnt;
	}
	scanf ( "%I64d" , &q );
	cnt = 0;
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%I64d%I64d" , &id , &mul );
		for ( j = lnum[id] ; j <= rnum[id] ; j++ ) {
			h[++cnt] = blockh[j];
			c[cnt] = blockc[j] * mul;
		}
	}
	for ( i = 1 ; i <= m ; i++ ) {
		ldown[i] = i;
		while ( tops && i - st[tops] < h[i] ) {
			ldown[i] = min ( ldown[i] , ldown[st[tops]] );
			tops--;
		}
		st[++tops] = i;
	}
	tops = 0;
	for ( i = m ; i >= 1 ; i-- ) {
		rdown[i] = i;
		while ( tops && st[tops] - i < h[i] ) {
			rdown[i] = max ( rdown[i] , rdown[st[tops]] );
			tops--;
		}
		st[++tops] = i;
	}
	/*for ( i = 1 ; i <= m ; i++ ) {
		printf ( "%I64d " , ldown[i] );
	}
	printf ( "\n" );
	for ( i = 1 ; i <= m ; i++ ) {
		printf ( "%I64d " , rdown[i] );
	}
	printf ( "\n" );*/
	dp[1] = c[1];
	tops = 0; tops2 = 0;
	st[++tops] = 1; sdp[1] = dp[0];
	st2[++tops2] = 1; sdp2[1] = dp[0] + c[1];
	for ( i = 2 ; i <= m ; i++ ) {
		while ( tops && sdp[tops] > dp[i-1] ) tops--;
		st[++tops] = i;
		sdp[tops] = dp[i-1];
		while ( tops && ldown[i] <= st[tops] ) {
			tops--;
		}
		tops++;
		while ( tops2 && rdown[st2[tops2]] < i ) {
			tops2--;
		}
		dp[i] = min ( sdp[tops] + c[i] , tops2?sdp2[tops2]:1223372036854775808ll );
		while ( tops2 && rdown[st2[tops2]] == rdown[i] && sdp2[tops2] >= dp[i-1] + c[i] ) tops2--;
		if ( tops2 == 0 || sdp2[tops2] > dp[i-1] + c[i] ) {
			st2[++tops2] = i;
			sdp2[tops2] = dp[i-1] + c[i];
		}
		/*printf ( "##%I64d\n" , i );
		printf ( "tops %I64d\n" , tops );
		for ( j = 1 ; j <= tops ; j++ ) printf ( "%I64d %I64d\n" , st[j] , sdp[j] );
		printf ( "tops2 %I64d\n" , tops2 );
		for ( j = 1 ; j <= tops2 ; j++ ) printf ( "%I64d %I64d\n" , st2[j] , sdp2[j] );
		printf ( "dp %I64d\n" , dp[i] );*/
	}
	printf ( "%I64d\n" , dp[m] );
}
int main () {
	work ();
	return 0;
}