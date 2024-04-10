#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 100100;
long long n;
long long a[maxn];
long long summ[maxn] , minuss[maxn];
long long big[maxn][100] , small[maxn][100];
long long cnt[maxn];
long long last[maxn];
long long x[maxn];
long long flag;
void dfs ( long long i , long long lim ) {
	if ( i == n / 2 + 1 ) {
		printf ( "Yes\n" );
		for ( i = 1 ; i <= n / 2 ; i++ ) {
			printf ( "%I64d " , 1ll * small[i][last[i]] * small[i][last[i]] - 1ll * big[i-1][last[i-1]] * big[i-1][last[i-1]] );
			printf ( "%I64d%c" , a[i] , i==(n/2)?'\n':' ' );
		}
		flag = 1;
		return ;
	}
	while ( last[i] && small[i][last[i]] <= lim ) {
		last[i]--;
	}
	if ( last[i] == 0 ) {
		flag = -1;
		return ;
	}
	while ( last[i] ) {
		dfs ( i + 1 , big[i][last[i]] );
		if ( flag == 1 ) return ;
		if ( flag == -1 ) return ;
		last[i]--;
	}
}
void work () {
	long long i , j , f;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n / 2 ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		f = 0;
		for ( j = 1 ; j * j < a[i] ; j++ ) {
			if ( a[i] % j == 0 ) {
				if ( ( (a[i]/j) + j ) % 2 == 0 ) {
					summ[i] = a[i] / j;
					minuss[i] = j;
					big[i][++cnt[i]] = (summ[i]+minuss[i]) / 2;
					small[i][cnt[i]] = (summ[i]-minuss[i]) / 2;
					f = 1;
				}
			}
		}
		if ( f == 0 ) {
			printf ( "No\n" );
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) last[i] = cnt[i];
	flag = 0;
	dfs ( 1 , -1 );
	if ( flag != 1 ) {
		printf ( "No\n" );
	}
}
int main () {
	work ();
	return 0;
}