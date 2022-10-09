// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef basic_string<int> vi;

vector<pair<int, int>> sol;

pair<vi, vi> razmena(vi a, vi b) {
	// a > b
	vi p, q;
	for (int i=0; i<(int)b.size(); i++) {
		sol.emplace_back(a[i], b[i]);
		q += a[i];
		q += b[i];
	}
	p = a.substr(b.size());
	return {p, q};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	set<pair<int, vi>> s;
	int n;
	cin >> n;

	int base = 1;

	vector<vi> resto;

	for (int w=1; w<=n; w+=w) {
		if (n & w) {
			vector<vi> a(w);
			for (int i=0; i<w; i++) {
				a[i] = vi{i + base};
			}
			base += w;

			// spajaj
			while (a.size() > 1) {
				vector<vi> t;
				for (int i=0; i<(int)a.size(); i+=2) {
					t.emplace_back(razmena(a[i], a[i+1]).second);
				}
				swap(a, t);
			}

			resto.emplace_back(a[0]);
		}
	}

	reverse(begin(resto), end(resto));

	while (resto.size() > 2) {
		for (auto& v : resto) {
			cerr << v.size() << ' ';
		}
		cerr << '\n';

		while (resto[resto.size() - 1].size() != resto[resto.size() - 2].size()) {
			auto [p, q] = razmena(resto[0], resto.back());
			resto[0] = p;
			resto.back() = q;
		}

		// jednaki, spoji
		resto[resto.size() - 2] = razmena(resto[resto.size() - 1], resto[resto.size() - 2]).second;
		resto.pop_back();
	}

	// to je to
	cout << sol.size() << "\n";
	for (auto [x, y] : sol) {
		cout << x << ' ' << y << '\n';
	}
	// cerr << sol.size() << "\n";
}