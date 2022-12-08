#include <iostream>
#include <stdio.h>

using namespace std;

int n , m , a[120000] , b[120000];
int main () {
	int i , l = 1 , r;
	cin >> n >> m;
	r = n-1;
	for ( i = 1 ; i <= m ; i++ ) {
		cin >> a[i] >> b[i];
		if ( a[i] > b[i] ) swap ( a[i] , b[i] );
		l = max ( l , a[i] );
		r = min ( r , b[i] - 1 );
	}
	if ( r - l + 1 >= 0 ) cout << r - l + 1 << endl;
	else cout << "0" << endl;
	return 0;
}