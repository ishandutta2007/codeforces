#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int n , a , b;
void work () {
	int i , t;
	scanf ( "%d" , &n );
	a = b = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &t );
		a = a ^ t;
	}
	for ( i = 1 ; i <= n - 1 ; i++ ) {
		scanf ( "%d" , &t );
		a = a ^ t;
		b = b ^ t; 
	}
	for ( i = 1 ; i <= n - 2 ; i++ ) {
		scanf ( "%d" , &t );
		b = b ^ t;
	}
	cout << a << endl << b << endl;
}
int main () {
	work ();
	return 0;
}