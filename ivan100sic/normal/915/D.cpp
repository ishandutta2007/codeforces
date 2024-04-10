#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
bool a[505][505];
bool v[505];
int stek_idx[505];
basic_string<int> stek, ciklus;

void dfs(int x) {
	if (ciklus.size())
		return;
	stek_idx[x] = stek.size();
	stek += x;
	v[x] = true;
	for (int y=0; y<n; y++) {
		if (!a[x][y])
			continue;
		if (v[y]) {
			if (stek_idx[y] != -1 && ciklus.empty()) {
				ciklus = stek.substr(stek_idx[y]); 
			}
		} else
			dfs(y);
	}
	stek_idx[x] = -1;
	stek.pop_back();
}

basic_string<int> nadji_ciklus() {
	fill(v, v+n, false);
	fill(stek_idx, stek_idx+n, -1);
	stek = ciklus = {};
	for (int i=0; i<n; i++) {
		if (!v[i])
			dfs(i);
		if (ciklus.size())
			break;
	}
	return ciklus;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		a[u-1][v-1] = 1;
	}

	// ispitaj aciklicnost/nadji ciklus
	auto cyc = nadji_ciklus();
	if (cyc.size() == 0) {
		cout << "YES\n";
		return 0;
	} else {
		for (int i=0; i<(int)cyc.size(); i++) {
			int x = cyc[i];
			int y = cyc[(i + 1) % cyc.size()];
			a[x][y] = 0;
			if (nadji_ciklus().empty()) {
				cout << "YES\n";
				return 0;
			}
			a[x][y] = 1;
		}
	}
	cout << "NO\n";
}