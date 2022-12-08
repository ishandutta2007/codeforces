#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

//long long
long long n , k;
void work () {
	long long i , t;
	scanf ( "%I64d%I64d" , &n , &k );
	t = sqrt ( n );
	while ( t * t > n ) t--;
	while ( (t+1) * (t+1) <= n ) t++;
	for ( i = 1 ; i <= t ; i++ ) {
		if ( n % i == 0 ) {
			if ( i * i != n ) k--;
			if ( k == 0 ) {
				printf ( "%I64d\n" , i );
				return ;
			}
		}
	}
	for ( i = t ; i >= 1 ; i-- ) {
		if ( n % i == 0 ) {
			k--;
			if ( k == 0 ) {
				printf ( "%I64d\n" , n / i );
				return ;
			}
		}
	}
	printf ( "-1\n" );
}
int main () {
	work ();
	return 0;
}