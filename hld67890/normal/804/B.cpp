#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

//long long
const long long maxn = 1200000;
const long long mod = 1000000007;
long long n;
char z[maxn];
long long ka[maxn] , kb[maxn] , tot;
long long sum , ans;
long long pow ( long long f , long long x ) {
	long long s = 1;
	while ( x ) {
		if ( x % 2 ) s = (s*f) % mod;
		f = (f*f) % mod; x >>= 1;
	}
	return s;
}
void work () {
	long long i , j;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'a' ) break;
	}
	for ( ; ; ) {
		j = i;
		while ( j <= n && z[j+1] == 'a' ) j++;
		if ( j == n ) break;
		ka[++tot] = j - i + 1;
		i = j + 1;
		while ( j <= n && z[j+1] == 'b' ) j++;
		kb[tot] = j - i + 1;
		i = j + 1;
		if ( j == n ) break;
	}
	sum = 0;
	for ( i = 1 ; i <= tot ; i++ ) {
		//printf ( "%I64d %I64d\n" , ka[i] , kb[i] );
		sum += ka[i];
		ans = (ans + kb[i] * ((pow ( 2 , sum ) - 1 + mod) % mod) ) % mod;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	work ();
	return 0;
}