#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rac {
	ll p, q;

	bool operator< (rac b) const {
		return p * b.q < q * b.p;
	}

	bool operator== (rac b) const {
		return p * b.q == q * b.p;
	}
};

int n, k, m;
basic_string<int> e[100005];
int v[100005], g[100005], v0[100005];

rac f1() {
	set<pair<rac, int>> s;

	for (int i=1; i<=n; i++)
		v[i] = v0[i];
	for (int i=1; i<=n; i++) {
		if (v[i]) {
			g[i] = 0;
			for (int y : e[i])
				if (v[y])
					g[i]++;
			s.insert({{g[i], (int)e[i].size()}, i});
		}
	}
	rac opt = s.begin()->first;
	while (s.size()) {
		auto it = s.begin();
		opt = max(opt, it->first);
		// ce brisemo cvor x
		int x = it->second;
		v[x] = 0;
		s.erase(it);
		for (int y : e[x]) {
			if (v[y] == 0)
				continue;
			s.erase({{g[y], (int)e[y].size()}, y});
			g[y]--;
			s.insert({{g[y], (int)e[y].size()}, y});
		}
	}

	return opt;
}

void f2(rac opt) {
	set<pair<rac, int>> s;
	
	for (int i=1; i<=n; i++)
		v[i] = v0[i];
	for (int i=1; i<=n; i++) {
		if (v[i]) {
			g[i] = 0;
			for (int y : e[i])
				if (v[y])
					g[i]++;
			s.insert({{g[i], (int)e[i].size()}, i});
		}
	}

	while (s.size()) {

		if (opt == s.begin()->first) {
			basic_string<int> z;
			for (int i=1; i<=n; i++)
				if (v[i])
					z += i;
			cout << z.size() << '\n';
			for (int x : z)
				cout << x << ' ';
			cout << '\n';
			exit(0);
		}

		auto it = s.begin();
		// ce brisemo cvor x
		int x = it->second;
		v[x] = 0;
		s.erase(it);
		for (int y : e[x]) {
			if (v[y] == 0)
				continue;
			s.erase({{g[y], (int)e[y].size()}, y});
			g[y]--;
			s.insert({{g[y], (int)e[y].size()}, y});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		v0[i] = 1;
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		v0[x] = 0;
	}
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	f2(f1());
}