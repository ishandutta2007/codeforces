#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main () {
	int i , a[6] , sum = 0;
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	sort ( a + 1 , a + 6 );
	for ( i = 1 ; i <= 3 ; i++ ) if ( a[i] == a[i+1] && a[i+1] == a[i+2] ) sum = max ( sum , a[i] * 3 );
	for ( i = 1 ; i <= 4 ; i++ ) if ( a[i] == a[i+1] ) sum = max ( sum , a[i] * 2 );
	printf ( "%d\n" , a[1] + a[2] + a[3] + a[4] + a[5] - sum );
	return 0;
}