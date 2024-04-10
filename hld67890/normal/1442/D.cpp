#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long long n , k;
long long t[3200] , tot[3100] , num[3100][3100];
long long dp[3100][3100];
long long ans;
void solve ( long long l , long long r , vector <long long> v ) {
	long long i , j , mid = (l+r)/2;
	vector < long long > v1 , v2;
	if ( l == r ) {
		for ( i = 0 ; i <= k ; i++ ) {
			dp[l][i] = v[i];
		}
		return ;
	}
	v1 = v2 = v;
	for ( i = l ; i <= mid ; i++ ) {
		for ( j = 3000 ; j >= t[i] ; j-- ) {
			v1[j] = max ( v1[j] , v1[j-t[i]] + tot[i] );
		}
	}
	for ( i = mid + 1 ; i <= r ; i++ ) {
		for ( j = 3000 ; j >= t[i] ; j-- ) {
			v2[j] = max ( v2[j] , v2[j-t[i]] + tot[i] );
		}
	}
	solve ( l , mid , v2 );
	solve ( mid + 1 , r , v1 );
}
void work () {
	long long i , j , x , tmp;
	vector < long long > v;
	scanf ( "%lld%lld" , &n , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &t[i] );
		for ( j = 1 ; j <= t[i] ; j++ ) {
			scanf ( "%lld" , &x );
			if ( j <= 3000 ) {
				num[i][j] = x;
				tot[i] += x;
			}
		}
		t[i] = min ( t[i] , 3000ll );
	}
	v.resize ( 3001 );
	solve ( 1 , n , v );
	ans = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		tmp = 0;
		for ( j = 0 ; j <= k && j <= t[i] ; j++ ) {
			ans = max ( ans , tmp + dp[i][k-j] );
			tmp += num[i][j+1];
		}
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}