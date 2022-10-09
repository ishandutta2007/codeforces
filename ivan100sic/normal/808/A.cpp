#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, sol = 1e18;
	cin >> n;

	for (ll l=0; l<=11; l++) {
		for (ll k=1; k<=9; k++) {
			ll x = k;
			for (int i=0; i<l; i++) {
				x *= 10;
			}
			if (x > n) {
				sol = min(sol, x-n);
			}
		}
	}

	cout << sol;
}