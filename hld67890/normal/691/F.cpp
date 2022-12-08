#include <iostream>
#include <stdio.h>

using namespace std;

//long long
const long long block = 2000;
long long n , m;
long long a[4200000] , p[4200000];
long long s[4200000];
long long ans[4200000];
void work () {
	long long i , j;
	scanf ( "%I64d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
	scanf ( "%I64d" , &m );
	for ( i = 1 ; i <= m ; i++ ) scanf ( "%I64d" , &p[i] );
	for ( i = 1 ; i <= n ; i++ ) s[a[i]]++;
	for ( i = 1 ; i <= 3000000 ; i++ )
		if ( s[i] ) {
			for ( j = 1 ; j <= 3000000 ; j++ ) {
				if ( i * j >= 3000000 ) break;
				if ( i == j ) ans[i*j] += s[i] * (s[i]-1);
				else ans[i*j] += s[i] * s[j];
			}
		}
	for ( i = 1 ; i <= 3000000 ; i++ ) ans[i] += ans[i-1];
	for ( i = 1 ; i <= m ; i++ ) printf ( "%I64d\n" , n * (n-1) - ans[p[i]-1] );
}
int main () {
	work ();
	return 0;
}