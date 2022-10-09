#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	ll sol = n;
	if (k > 1) {
		ll v = (1ll << (64 - __builtin_clzll(n))) - 1;
		sol = max(sol, v);
	}

	cout << sol;
}