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
		vector<int> a(n), b(n);
		for (int& x : a)
			cin >> x;
		for (int& x : b)
			cin >> x;

		bool ok = 1;
		int p = 0, m = 0;
		for (int i=0; i<n; i++) {
			int d = b[i] - a[i];
			if (d > 0)
				ok &= p;
			if (d < 0)
				ok &= m;
			p |= a[i] == 1;
			m |= a[i] == -1;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}