#include <stdio.h>
#include <algorithm>

using namespace std;

int n , k;
int p[1220000] , prime[1200000] , tot;
int phi[1200000];
long long ans;
void work () {
	int i , j;
	scanf ( "%d%d" , &n , &k );
	for ( i = 2 ; i <= n ; i++ ) {
		if ( !p[i] ) {
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for ( j = 1 ; j <= tot ; j++ ) {
			if ( i * prime[j] > n ) break;
			p[i*prime[j]] = 1;
			if ( i % prime[j] == 0 ) {
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i*prime[j]] = phi[i] * (prime[j]-1);
		}
		//printf ( "%d %d\n" , i , phi[i] );
	}
	phi[4]++;
	ans = 1;
	if ( k >= 1 ) ans += phi[3];
	if ( k >= 2 ) ans += phi[4];
	if ( n >= 5 ) sort ( phi + 5 , phi + n + 1 );
	for ( i = 5 ; i <= 5 + k - 1 - 2 ; i++ ) {
		//printf ( "%d %d\n" , i , phi[i] );
		ans += phi[i];
	}
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}