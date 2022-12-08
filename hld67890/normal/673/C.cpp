#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int t[12000] , ans[10200];
int f[6000];
int main () {
	int i , j , n , mx , mi;
	cin >> n;
	for ( i = 1 ; i <= n ; i++ ) cin >> t[i];
	for ( i = 1 ; i <= n ; i++ ) {
		
		for ( j = 0 ; j <= n ; j++ ) {
			f[j] = 0;
		}
		mx = 0; mi = 99999;
		for ( j = i ; j <= n ; j++ ) {
			f[t[j]]++;
			if ( f[t[j]] > mx || (f[t[j]] == mx&&mi>t[j])) {
				mx = f[t[j]];
				mi = t[j];
			}
			ans[mi]++;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) cout << ans[i] << " ";
	cout << endl;
	return 0;
}