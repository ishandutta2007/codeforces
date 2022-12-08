#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 1200000;
long long n , m , k;
long long v[maxn] , a[maxn];
long long last[maxn];
long long ans , now;
void work () {
	long long i , j , s;
	scanf ( "%I64d%I64d%I64d" , &n , &m , &k );
	for ( i = 1 ; i <= m ; i++ ) {
		scanf ( "%I64d" , &s );
		v[s] = 1;
	}
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		if ( !v[i] ) last[i] = i;
		else last[i] = last[i-1];
		//printf ( "%I64d\n" , last[i] );
	}
	ans = -1;
	if ( v[0] ) {
		printf ( "-1\n" );
		return ;
	}
	for ( i = 1 ; i <= k ; i++ ) {
		now = a[i];
		for ( j = i ; j < n ; ) {
			//printf ( "%I64d %I64d %I64d\n" , i , j , now );
			if ( last[j] + i > j ) {
				now += a[i];
				j = last[j] + i;
			}
			else {
				break;
			}
		}
		if ( j >= n ) {
			if ( ans == -1 ) ans = now;
			else ans = min ( ans , now );
		}
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}