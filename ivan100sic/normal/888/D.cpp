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
	ll sol = 1;

	if (k >= 2) {
		sol += n*(n-1) / 2;
	}
	if (k >= 3) {
		sol += n*(n-1)*(n-2) / 3;
	}
	if (k == 4) {
		sol += n*(n-1)*(n-2)*(n-3) / 24 * 9;
	}

	cout << sol;
}