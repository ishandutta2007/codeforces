#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++) {
		ll x = abs(i - n / 2);
		for(ll j = 0; j < x; j++) cout << "*";
		for(ll j = 0; j < n - 2 * x; j++) cout << "D";
		for(ll j = 0; j < x; j++) cout << "*";	
		cout << endl;
	}
	return 0;
}