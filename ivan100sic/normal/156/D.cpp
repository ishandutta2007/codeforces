#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;

struct dsu {
	vector<int> p; int cc;

	dsu(int n) : p(n), cc(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (p[x] == x)
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		cc--;
		p[x] = y;
		return true;
	}
};

void rek(dsu d, int n, set<pair<int, int>> s, set<set<pair<int, int>>>& p) {
	if (d.cc == 1) {
		p.insert(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto d2 = d;
			if (d2.spoji(i, j)) {
				auto s2 = s;
				s2.insert({ i, j });
				rek(d2, n, s2, p);
			}
		}
	}
}

ll resi(vector<int> a) {
	int n = accumulate(a.begin(), a.end(), 0);
	dsu d0(n);
	int k = 0;
	for (int x : a) {
		int z = k++;
		for (int j = 0; j < x - 1; j++) {
			int y = k++;
			d0.spoji(z, y);
		}
	}
	set<set<pair<int, int>>> s;
	rek(d0, n, {}, s);
	return s.size();
}

void igramo_se() {
	for (int i = 1; i <= 4; i++) {
		for (int j = i; j <= 4; j++) {
			for (int k = j; k <= 4; k++) {
				vector<int> v = { i, j, k };
				ll r = resi(v);
				cout << i << ' ' << j << ' ' << k << ' ' << r << '\n';
				cout << "perhaps " << r / (i + j + k) << '\n';
			}
		}
	}
}

int n, m, mod;
basic_string<int> e[100005];
bool vis[100005];

void dfs(int x, int& z) {
	z++;
	vis[x] = 1;
	for (int y : e[x]) {
		if (!vis[y]) {
			dfs(y, z);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> mod;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	int p = 1, komp = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int z = 0;
			dfs(i, z);
			p = p * 1ll * z % mod;
			komp++;
		}
	}

	for (int i = 0; i < komp - 2; i++) {
		p = p * 1ll * n % mod;
	}

	if (komp == 1)
		p = 1 % mod;

	cout << p << '\n';
}