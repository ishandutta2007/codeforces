#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y, z;

	bool operator< (const pt& b) const {
		return z < b.z;
	}
};

int n, m, p;
vector<pt> e[90005];
int a[305][305];
int d[305][305];

void bfssolve(const vector<pt>& a, vector<pt>& b) {
	memset(d, 63, sizeof(d));
	multiset<pt> pq;
	for (pt p : a) {
		d[p.x][p.y] = p.z;
		pq.insert(p);
	}

	while (pq.size()) {
		auto [x, y, z] = *pq.begin();
		pq.erase(pq.begin());

		auto go = [&](int u, int v, int w) {
			if (u < 1 || u > n || v < 1 || v > m)
				return;
			if (d[u][v] <= w)
				return;
			pq.erase({u, v, d[u][v]});
			d[u][v] = w;
			pq.insert({u, v, d[u][v]});
		};

		go(x+1, y, z+1);
		go(x-1, y, z+1);
		go(x, y+1, z+1);
		go(x, y-1, z+1);
	}

	for (auto& [x, y, z] : b) {
		z = d[x][y];
	}
}

void brutsolve(const vector<pt>& a, vector<pt>& b) {
	for (auto& [u, v, w] : b) {
		for (auto [x, y, z] : a) {
			w = min(w, z + abs(u-x) + abs(v-y));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> p;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			e[a[i][j]].push_back({i, j, 1123123123});
		}
	}

	size_t gr = sqrt(n*m) * 6;

	e[0].push_back({1, 1, 0});

	for (int i=1; i<=p; i++) {
		if (e[i-1].size() >= gr && e[i].size() >= gr) {
			bfssolve(e[i-1], e[i]);
		} else {
			brutsolve(e[i-1], e[i]);
		}
	}

	cout << e[p][0].z << '\n';
}