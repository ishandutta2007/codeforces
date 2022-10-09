// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct gr {
	int y, w, c;
};

int n;
ll s, swp;
vector<gr> e[100005];
basic_string<ll> h[3];

int dfs(int x, int p, int ew, int ec) {
	int st = e[x].size() == 1 && x != 1;
	for (auto [y, w, c] : e[x]) {
		if (y == p) continue;
		st += dfs(y, x, w, c);
	}

	if (x != p) {
		swp += st * 1ll * ew;
		for (int q=ew; q; q>>=1) {
			ll qd = q - (q>>1);
			h[ec] += qd * st;
		}
	}

	return st;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;

		// clear
		for (int i=1; i<=n; i++) {
			e[i] = {};
		}
		h[1] = h[2] = {};
		swp = 0;

		for (int i=1; i<n; i++) {
			int u, v, w, c;
			cin >> u >> v >> w;
			c = 1;
			e[u].push_back({v, w, c});
			e[v].push_back({u, w, c});
		}

		dfs(1, 1, 0, 0);

		ll sd = swp - s;
		// moras da skines bar ovoliko
		for (int i : {1, 2}) {
			sort(begin(h[i]), end(h[i]), greater<ll>());
			h[i].insert(h[i].begin(), 0);
			for (int j=1; j<(int)h[i].size(); j++) {
				h[i][j] += h[i][j-1];
			}
		}

		int sol = 1123123123;

		// cerr << "sd = " << sd << '\n';
		// for (ll x : h[1]) cerr << x << ' ';
		// cerr << '\n';
		// for (ll x : h[2]) cerr << x << ' ';
		// cerr << '\n';

		for (int s1=0; s1<(int)h[1].size(); s1++) {
			int s2 = lower_bound(begin(h[2]), end(h[2]), sd - h[1][s1]) - h[2].begin();
			if (s2 == (int)h[2].size())
				continue;
			sol = min(sol, s1 + 2*s2);
		}

		cout << sol << '\n';
	}
}