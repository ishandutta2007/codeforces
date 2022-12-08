#include <iostream>
#include <stdio.h>

using namespace std;

int k[22] = { 6,2,5,5,4,5,6,3,7,6};
int main () {
	int i , j , a , b , s = 0;
	scanf ( "%d%d" , &a , &b );
	for ( i = a ; i <= b ; i++ ) {
		j = i;
		while ( j ) s += k[j%10], j = j / 10;
	}
	printf ( "%d\n" , s );
	return 0;
}