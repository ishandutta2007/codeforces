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
		vector<ll> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		ll lo = 0, sol = 0, v = 0;
		for (int i=0; i+1<n; i+=2) {
			v += a[i+1] - a[i];
			sol = max(sol, v-lo);
			lo = min(lo, v);
		}

		lo = v = 0;
		for (int i=1; i+1<n; i+=2) {
			v += a[i] - a[i+1];
			sol = max(sol, v-lo);
			lo = min(lo, v);
		}

		for (int i=0; i<n; i+=2) sol += a[i];
		cout << sol << '\n';
	}
}