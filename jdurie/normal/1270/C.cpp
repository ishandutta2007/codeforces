#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll n, sum = 0, xorr = 0;
		cin >> n;
		for(ll i = 0; i < n; i++) {
			ll x; cin >> x;
			sum += x;
			xorr ^= x;
		}
		cout << 2 << endl;
		cout << xorr << " " << sum + xorr << endl;
	}
}