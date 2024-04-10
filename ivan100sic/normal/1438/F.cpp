// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

map<int, int> f;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int h;
	cin >> h;
	int n = (1 << h) - 1;

	uniform_int_distribution<int> ui(1, n);

	for (int i=0; i<420;) {
		int x = ui(eng), y = ui(eng), z = ui(eng);
		if (x == y || y == z || z == x) continue;

		i++;
		cout << "? " << x << ' ' << y << ' ' << z << '\n' << flush;
		int a;
		cin >> a;

		f[a]++;
	}

	vector<pair<int, int>> e;

	for (auto [x, y] : f) {
		e.emplace_back(y, x);
	}

	sort(begin(e), end(e), greater<pair<int, int>>());

	int u = e[0].second;
	int v = e[1].second;
	int sol = 1;
	for (int x=1; x<=n; x++) {
		if (x == u || x == v) continue;
		cout << "? " << x << ' ' << u << ' ' << v << '\n' << flush;
		int a;
		cin >> a;
		if (x == a) sol = x;
	}

	cout << "! " << sol << '\n' << flush;
}