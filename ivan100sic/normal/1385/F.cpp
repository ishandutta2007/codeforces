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
		vector<set<int>> e(n), l(n);
		for (int i=1; i<n; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			e[x].insert(y);
			e[y].insert(x);
		}

		int sol = 0;
		set<pair<int, int>> pq;
		for (int i=0; i<n; i++) {
			for (int j : e[i]) {
				if (e[j].size() == 1) {
					l[i].insert(j);
				}
			}
			pq.insert({l[i].size(), i});
		}

		while (pq.size()) {
			auto [c, x] = *--pq.end();
			if (c < k) {
				break;
			}

			pq.erase({l[x].size(), x});

			sol++;
			int rep = k;
			while (rep--) {
				int y = *l[x].begin();
				pq.erase({l[y].size(), y});
				l[y] = {};
				e[y] = {};
				e[x].erase(y);
				l[x].erase(y);
			}

			pq.insert({l[x].size(), x});
			if (e[x].size() == 1) {
				int y = *e[x].begin();
				pq.erase({l[y].size(), y});
				l[y].insert(x);
				pq.insert({l[y].size(), y});
			}
		}

		cout << sol << '\n';
	}
}