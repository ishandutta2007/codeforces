// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[500005], b[500005];
int c[1 << 20];
set<pair<int, int>> e[1 << 20];
basic_string<int> pt;

void brisi(int x, int y, int z) {
	e[x].erase({y, z});
	e[y].erase({x, -z});
}

list<pair<int, int>> eu(int x) {
	list<pair<int, int>> lst;

	while (e[x].size()) {
		auto [y, z] = *e[x].begin();
		lst.emplace_back(x, z);
		brisi(x, y, z);
		x = y;
	}

	for (auto it = lst.begin(); it != lst.end(); ++it) {
		auto q = eu(it->first);
		lst.splice(it, q);
	}

	return lst;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i] >> b[i];
	for (int w=20; w>=0; w--) {
		int m = (1 << w)-1, ok = 1;

		memset(c, 0, sizeof c);

		for (int i=0; i<n; i++) {
			c[a[i] & m] ^= 1;
			c[b[i] & m] ^= 1;
		}

		for (int i=0; i<(1<<w); i++) {
			if (c[i]) {
				ok = 0;
			}
			e[i].clear();
		}

		if (ok) {
			for (int i=0; i<n; i++) {
				e[a[i] & m].insert({b[i] & m, i+1});
				e[b[i] & m].insert({a[i] & m, -i-1});
			}

			auto lst = eu(a[0] & m);

			if ((int)lst.size() == n) {
				cout << w << '\n';
				for (auto [_, x] : lst) {
					if (x > 0) {
						cout << 2*x-1 << ' ' << 2*x << ' ';
					} else {
						x = -x;
						cout << 2*x << ' ' << 2*x-1 << ' ';
					}
				}
				cout << '\n';
				return 0;
			}
		}
	}
}