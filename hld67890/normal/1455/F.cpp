#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n , k;
string ini;
string dp[510];
void work () {
	int i;
	string tmp , t2;
	cin >> n >> k;
	cin >> ini;
	for ( i = 0 ; i <= n ; i++ ) {
		dp[i] = ini;
	}
	dp[0] = ini;
	for ( i = 0 ; i < n ; i++ ) {
		tmp = dp[i];
		//cout << dp[i] << endl;
		if ( dp[i][i] == 'a' + k - 1 ) {
			tmp[i] = 'a';
		}
		else {
			if ( dp[i][i] != 'a' ) {
				tmp[i] = tmp[i] - 1;
			}
		}
		dp[i+1] = min ( dp[i+1] , tmp );
		if ( i != 0 ) {
			tmp = dp[i];
			swap ( tmp[i-1] , tmp[i] );
			dp[i+1] = min ( dp[i+1] , tmp );
		}
		if ( i != n - 1 ) {
			tmp = dp[i];
			swap ( tmp[i] , tmp[i+1] );
			dp[i+2] = min ( dp[i+2] , tmp );
			
			t2 = tmp;
			if ( t2[i] == 'a' + k - 1 ) {
				t2[i] = 'a';
			}
			else {
				if ( t2[i] != 'a' ) {
					t2[i] = t2[i] - 1;
				}
			}
			dp[i+2] = min ( dp[i+2] , t2 );
			
			if ( i != 0 ) {
				swap ( tmp[i-1] , tmp[i] );
				dp[i+2] = min ( dp[i+2] , tmp );
			}
		}
	}
	cout << dp[n] << endl;
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}