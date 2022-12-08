#include <iostream>
#include <stdio.h>

using namespace std;

int n;
long long a[120000] , sum , maxx;
int main () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
		sum += a[i];
		maxx = max ( maxx , a[i] );
	}
	printf ( "%I64d\n" , maxx - (sum - maxx) + 1 );
	return 0;
}