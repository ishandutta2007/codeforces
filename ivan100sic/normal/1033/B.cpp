#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (a-b >= 2) {
			cout << "NO\n";
			continue;
		}

		ll x = a+b;
		int p = 1;
		for (ll i=2; i*i<=x; i++) {
			if (x % i == 0) {
				p = 0;
			}
		}

		cout << (p ? "YES\n" : "NO\n");
	}
}