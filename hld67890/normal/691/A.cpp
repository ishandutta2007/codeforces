#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int main () {
	int i , s = 0 , a;
	cin >> n;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> a;
		s += a;
	}
	if ( (s == n - 1&&n!=1) || (n==1&&s==1) ) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}