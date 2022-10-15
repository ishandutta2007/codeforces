#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ll n, mx = 0;
	cin >> n;
	for(ll i = 0; i < n; i++) { 
		ll x;
		cin >> x;
		mx = max(mx, x);
	}
	cout << mx << endl;
	return 0;
}