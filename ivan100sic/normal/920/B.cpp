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
		vector<vector<int>> l(6005), r(6005);
		vector<int> l0(n), h(n);
		for (int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			l0[i] = x;
			l[x].push_back(i);
			r[y].push_back(i);
		}

		set<pair<int, int>> q;

		for (int c=0; c<6005; c++) {
			// ubaci
			for (int i : l[c]) {
				q.insert({c, i});
			}

			// vidi
			if (q.size()) {
				int i = q.begin()->second;
				h[i] = c;
				q.erase(q.begin());
			}

			// izbaci
			for (int i : r[c]) {
				q.erase({l0[i], i});
			}
		}

		for (int i=0; i<n; i++)
			cout << h[i] << " \n"[i == n-1];
	}
}