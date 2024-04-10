#include <iostream>
#include <stdio.h>

using namespace std;

int i , n , a , b[100] , s;
int main () {
	cin >> n;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> a;
		b[a] = 1;
	}
	s = 0;
	for ( i = 1 ; i <= 90 ; i++ ) {
		if ( b[i] == 0 ) s++;
		else {
			s = 0;
		}
		if ( s >= 15 ) break;
	}
	if ( i >= 91 ) i--;
	cout << i << endl;
	return 0;
}