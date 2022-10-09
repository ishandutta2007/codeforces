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
		for (int& x : a) {
			cin >> x;
		}

		int m = *min_element(begin(a), end(a));

		vector<int> g, gs;

		for (int i=0; i<n; i++) {
			if (a[i] % m == 0) {
				g.push_back(i);
			}
		}

		gs = g;

		sort(begin(gs), end(gs), [&](int i, int j) { return a[i] < a[j]; });

		vector<int> b = a;
		for (int i=0; i<(int)g.size(); i++) {
			b[g[i]] = a[gs[i]];
		}

		cout << (is_sorted(begin(b), end(b)) ? "YES\n" : "NO\n");
	}
}