#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll read() {
	ll n, x, ans = 0;
	cin >> n >> x;
	for(ll i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		ans *= x;
		ans += t;
	}
	return ans;
}

int main() {
	ll n = read();
	ll m = read();
	if (n < m) cout << "<\n";
	else if (n == m) cout << "=\n";
	else cout << ">\n";
}