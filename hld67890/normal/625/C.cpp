#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
	int n , k , i , j , first , last , sum = 0;
	int map[510][510];
	scanf ( "%d%d" , &n , &k );
	first = 1; last = n * n;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = n ; j >= k ; j-- ) map[i][j] = last--;
		for ( j = 1 ; j < k ; j++ ) map[i][j] = first++;
	}
	for ( i = 1 ; i <= n ; i++ ) sum += map[i][k];
	printf ( "%d\n" , sum );
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) printf ( "%d " , map[i][j] );
		printf ( "\n" );
	}
	return 0;
}