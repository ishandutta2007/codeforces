#include <bits/stdc++.h>
using namespace std ;
 
const int N = 2e5 + 20 ;
int n , a[N] , b[N] , c[N] ;
string s , t ;
 
int main(){
	cin >> n ;
	cin >> s >> t ;
	for (int i = 0 ; i < n ; i ++) {
		a[i] = s[i] - 'a' ;
		b[i] = t[i] - 'a' ;
		c[i] = a[i] + b[i] ;
	}
	for (int i = n - 1 ; i > 0 ; i --) {
		if (c[i] >= 26) {
			c[i] -= 26 ;
			c[i - 1] ++ ;
		}
	}
	for (int i = 0 ; i < n ; i ++) {
		c[i + 1] += (c[i] % 2) * 26 ;
		c[i] /= 2 ;
		cout << char(c[i] + 'a') ;
	}
	return 0;
}