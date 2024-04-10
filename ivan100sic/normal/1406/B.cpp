// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		sort(begin(a), end(a));
		ll sol = -1e18;
		for (int i=0; i<=5; i++) {
			ll z = 1;
			for (int j=0; j<i; j++) z *= a[j];
			for (int j=n-5+i; j<n; j++) z *= a[j];
			sol = max(sol, z);
		}

		if (count(begin(a), end(a), 0)) {
			sol = max(sol, 0ll);
		}

		cout << sol << '\n';
	}
}