#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int n, m;
vector<int> e[100005];
int u[100005], v[100005];
int idx[100005], low[100005], t, cc;
 
int o(int i, int x) {
	return u[i] ^ v[i] ^ x;
}
 
vector<int> stek;
vector<vector<int>> g;
 
void bcc(int x, int pi) {
	idx[x] = low[x] = ++t;
 
	int chld = 0;
 
	for (int i : e[x]) {
		if (i == pi)
			continue;
 
		int y = o(i, x);
 
		if (idx[y] == 0) {
			// tree edge
			stek.push_back(i);
			bcc(y, i);
			low[x] = min(low[x], low[y]);
			chld++;
 
			if ((pi == -1 && chld > 1) || (low[y] >= idx[x])) {
				// cc
				cc++;
				vector<int> gg;
				while (stek.size()) {
					auto ee = stek.back();
					stek.pop_back();
					gg.push_back(ee);
					if (ee == i) {
						break;
					}
				}
				g.push_back(gg);
			}
		} else if (idx[y] < idx[x]) {
			// back edge
			low[x] = min(low[x], idx[y]);
			stek.push_back(i);
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n >> m;
 
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(i);
		e[v[i]].push_back(i);
	}
 
	for (int i=1; i<=n; i++) {
		if (idx[i] == 0) {
			bcc(i, -1);
			if (stek.size()) {
				cc++;
				g.push_back(stek);
				stek = {};
			}
		}
	}
 
	vector<int> sol;
 
	for (auto gg : g) {
		set<int> cv;
		for (int i : gg) {
			cv.insert(u[i]);
			cv.insert(v[i]);
		}
		if (cv.size() == gg.size()) {
			for (int i : gg)
				sol.push_back(i);
		}
	}
	sort(sol.begin(), sol.end());
	cout << sol.size() << '\n';
	for (int i : sol)
		cout << i << ' ';
	cout << '\n';
}