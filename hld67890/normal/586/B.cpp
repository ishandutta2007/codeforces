#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n , a[5][100] , b[100] , sum[5][100] , ans[100];
void work () {
	int i;
	scanf ( "%d" , &n );
	for ( i = 1 ; i < n ; i++ ) scanf ( "%d" , &a[1][i] );
	for ( i = 1 ; i < n ; i++ ) scanf ( "%d" , &a[2][i] );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &b[i] );
	for ( i = 1 ; i <= n ; i++ ) sum[1][i] = sum[1][i-1] + a[1][i-1];
	for ( i = n ; i >= 1 ; i-- ) sum[2][i] = sum[2][i+1] + a[2][i];
	for ( i = 1 ; i <= n ; i++ ) ans[i] = sum[1][i] + b[i] + sum[2][i];
	//for ( i = 1 ; i <= n ; i++ ) cout <<sum[1][i] << " " << b[i] << " " << sum[2][i] << endl;
	sort ( ans + 1 , ans + 1 + n );
	printf ( "%d\n" , ans[1] + ans[2] );
}
int main () {
	work ();
	return 0;
}