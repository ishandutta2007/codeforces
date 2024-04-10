#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const long long maxn = 120000;
const long long maxm = 1200000;
const long long mod = 1000000007;
long long n , m;
long long hash[maxm];
long long exist[maxm];
long long a[maxn*5];
long long fact[maxm];
long long ans;
long long getmod ( long long x ) {
	return x % mod;
}
void work () {
	long long i , j , k , tmp;
	scanf ( "%I64d%I64d" , &n , &m );
	fact[0] = 1;
	for ( i = 1 ; i <= m ; i++ ) fact[i] = (fact[i-1] * i) % mod;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &k );
		for ( j = 1 ; j <= k ; j++ ) {
			scanf ( "%I64d" , &a[j] );
			exist[a[j]]++;
		}
		for ( j = 1 ; j <= k ; j++ ) {
			if ( exist[a[j]] ) {
				tmp = ( getmod(i*i+exist[a[j]]*i+exist[a[j]]*exist[a[j]]) * 
				  getmod(i*i+exist[a[j]]*i+exist[a[j]]*exist[a[j]]) + (i^exist[a[j]]) );
				tmp = tmp * i;
				tmp %= mod;
				tmp = tmp | ( exist[a[j]] * 233 );
				tmp = tmp * ( ( exist[a[j]] ^ ( i * i ) ) + 12345 );
				hash[a[j]] = hash[a[j]] ^ tmp;
				exist[a[j]] = 0;
			}
		}
	}
	sort ( hash + 1 , hash + 1 + m );
	ans = 1;
	k = 0;
	for ( i = 1 ; i <= m ; i++ ) {
		//printf ( "%I64d\n" , hash[i] );
		if ( i == 1 || hash[i] == hash[i-1] ) k++;
		else {
			ans = (ans * fact[k]) % mod;
			k = 1;
		}
	}
	ans = (ans * fact[k]) % mod;
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}