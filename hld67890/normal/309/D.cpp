#include <iostream>
#include <stdio.h>

using namespace std;

int n , m;
long long ans;
void work () {
	int i , j , k;
	long long sum;
	scanf ( "%d%d" , &n  , &m );
	for ( i = m + 1 ; i <= n/2 & i <= n - m ; i++ ) {
		sum = 0;
		for ( j = m + 1 , k = m + 1 ; j <= n - m ; j++ ) {
			if ( i * 2 < j ) break;
			while ( i * i + ( j - i ) * j  + (n + 1 - i) * (n + 1 - i) + (-k+i) * (n+1-k) >= (n+1-j)*(n+1-j)+(k-n-1+j)*k ) k++;
			if ( k > n - m ) break;
			sum += (long long) ( n - m - k + 1 );
			//cout << i << ' ' <<j << " " << k<< " " << n - m - k << endl;
		}
		ans += sum;
	}
	ans = ans * 2;
	if ( n%2 == 1 ) {
		i = n / 2 + 1;
		if ( i <= n - m )
		for ( j = m + 1 , k = m + 1 ; j <= n - m ; j++ ) {
			while ( i * i + ( j - i ) * j  + (n + 1 - i) * (n + 1 - i) + (-k+i) * (n+1-k) >= (n+1-j)*(n+1-j)+(k-n-1+j)*k ) k++;
			if ( k > n - m ) break;
			ans += (long long) ( n - m - k + 1 );
			//cout << i << ' ' <<j << " " << k<< " " << n - m - k << endl;
		}
	}
	printf ( "%I64d\n" , ans * 3 );
}
int main () {
	work ();
	return 0;
}