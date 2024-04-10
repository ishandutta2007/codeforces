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
		int n, k;
		cin >> n >> k;
		vector<int> a(n), d(n);
		for (int& x : a) cin >> x;

		d[0] = a[0];
		for (int i=1; i<n; i++) d[i] = a[i] - a[i-1];

		// int s0 = a[0] != 0;
		int s1 = count_if(begin(d)+1, end(d), [](int x) { return !!x; });

		// svaki niz bi moze da ima najvise k-1 stepova
		if (k == 1) {
			cout << (s1 == 0 ? 1 : -1) << '\n';
		} else {
			int sol = (s1 + k - 2) / (k - 1);
			if (!sol) sol = 1;
			cout << sol << '\n';
		}
	}
}