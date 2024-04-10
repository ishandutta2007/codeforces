#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//long long
long long n;
char z[120000];
long long a;
long long ans;
int main () {
	int i;
	long long t , x , tmp;
	cin >> z;
	n = strlen ( z );
	t = 0;
	for ( i = 0 ; i < n ; i++ ) {
		if ( '0' <= z[i] && z[i] <= '9' ) x = z[i] - '0';
		if ( 'A' <= z[i] && z[i] <= 'Z' ) x = z[i] - 'A' + 10;
		if ( 'a' <= z[i] && z[i] <= 'z' ) x = z[i] - 'A' + 36;
		if ( z[i] == '-' ) x = 62;
		if ( z[i] == '_' ) x = 63;
		tmp = 0;
		while ( x ) {
			if ( x % 2 == 1 ) tmp++;
			x = x / 2;
		}
		t += 6 - tmp;
	}
	ans = 1;
	while ( t-- ) {
		ans = ans * 3;
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}