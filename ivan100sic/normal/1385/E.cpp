// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class E, class R>
void dfs(int x,  E& e, R& r, int& cnt) {
	r[x] = -2;

	for (int y : e[x]) {
		if (r[y] == -1) {
			dfs(y, e, r, cnt);
		}
	}

	r[x] = cnt--;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> undir;
		vector<basic_string<int>> e(n);
		for (int i=0; i<m; i++) {
			int t, x, y;
			cin >> t >> x >> y;
			x--, y--;
			if (t) {
				e[x] += y;
			} else {
				undir.emplace_back(x, y);
			}
		}

		vector<int> r(n, -1);
		int cnt = n-1, ok = 1;

		for (int i=0; i<n; i++) {
			if (r[i] == -1) {
				dfs(i, e, r, cnt);
			}
		}

		for (int i=0; i<n; i++) {
			for (int j : e[i]) {
				if (r[i] > r[j]) {
					ok = 0;
				}
			}
		}

		if (!ok) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (auto [x, y] : undir) {
				if (r[x] > r[y]) {
					swap(x, y);
				}
				cout << x+1 << ' ' << y+1 << '\n';
			}
			for (int i=0; i<n; i++) {
				for (int j : e[i]) {
					cout << i+1 << ' ' << j+1 << '\n';
				}
			}
		}
	}
}