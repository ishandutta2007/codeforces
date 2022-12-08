#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1100000;
const int mod = 1000000007;
int q , n , r;
int s[maxn][25];
int p[maxn] , prime[maxn];
int lp[maxn];
long long ans;
void work () {
	int i , j , k , last , sum;
	for ( i = 0 ; i <= 1000000 ; i++ )
		for ( j = 0 ; j <= 24 ; j++ ) {
			if ( i == 0 ) s[i][j] = 2;
			else {
				if ( i != 1 ) {
					if ( j != 0 ) {
						s[i][j] = (s[i-1][j] + s[i][j-1]);
						if ( s[i][j] >= mod) s[i][j] -= mod;
					}
					else s[i][j] = 1;
				}
				else s[i][j] = j * 2 + 1;
			}
		}
	s[0][0] = 1;
	//for ( i = 0 ; i <= 5 ; i++,printf ("\n") ) for ( j = 0 ; j <= 5 ; j++ ) printf ( "%d " , s[i][j] );
	p[1] = 1;
	k = 0;
	for ( i = 2 ; i <= 1000000 ; i++ ) {
		if ( p[i] == 0 ) {
			lp[i] = i;
			prime[++k] = i;
		}
		for ( j = 1 ; lp[i] >= prime[j] && j <= k && prime[j] * i <= 1000000 ; j++ ) {
			p[prime[j]*i] = 1;
			lp[prime[j]*i] = prime[j];
		}
	}
	//for ( i = 1 ; i <= 50 ; i++ ) printf ( "%d %d\n" , i , lp[i] );
	k = 0;
	for ( i = 2 ; i <= 1000000 ; i++ ) if ( p[i] == 0 ) prime[++k] = i;
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &r , &n );
		ans = 1;
		sum = 0; last = -1;
		while ( n != 1 ) {
			if ( lp[n] != last ) {
				if ( sum != 0 ) ans = (ans * (long long)s[r][sum]) % mod;
				sum = 1;
				last = lp[n];
			}
			else {
				sum++;
			}
			n = n / lp[n];
		}
		//printf ( "%d\n" , sum );
		ans = (ans * (long long)s[r][sum]) % mod;
		printf ( "%I64d\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}