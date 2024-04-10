#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, verts;
vector<pair<int, int>> e[1100005];
vector<pair<int, int>> f[1100005];
int d[1100005], df[1100005], mp[1100005];
int p[1100005], val[1100005];

void add_edge(int x, int y, int i) {
	string s = to_string(i);
	vector<int> put = {x};
	for (int j=0; j<(int)s.size()-1; j++)
		put.push_back(++verts);
	put.push_back(y);
	for (int j=0; j<(int)put.size()-1; j++) {
		int u = put[j], v = put[j+1];
		e[u].emplace_back(v, s[j] - '0');
		f[v].emplace_back(u, s[j] - '0');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	verts = n;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		add_edge(x, y, i);
		add_edge(y, x, i);
	}

	memset(d, 63, sizeof d);
	d[1] = 0;
	basic_string<int> q = {1};
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (auto [y, w] : e[x]) {
			if (d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}

	vector<vector<int>> atd(1100005);
	for (int i=1; i<=verts; i++) {
		atd[d[i]].push_back(i);
	}

	mp[1] = df[1] = 0;
	for (int l=1; l<=verts; l++) {
		if (!atd[l].size())
			continue;
		for (int x : atd[l]) {
			mp[x] = 1e9;
			for (auto [y, w] : f[x]) {
				if (d[y] == d[x] - 1) {
					mp[x] = min(mp[x], df[y] * 10 + w);
				}
			}
		}
		sort(atd[l].begin(), atd[l].end(), [&](int x, int y) {
			return mp[x] < mp[y];
		});
		df[atd[l][0]] = 0;
		for (int i=1; i<(int)atd[l].size(); i++) {
			int u = atd[l][i-1];
			int v = atd[l][i];
			df[v] = df[u] + (mp[u] != mp[v]);
		}
	}

	for (int x : q) {
		if (x == 1)
			continue;
		int qq = 1e9;
		for (auto [y, w] : f[x]) {
			if (d[y] == d[x]-1 && df[y]*10+w < qq)
				qq = df[y]*10+w, p[x] = y, val[x] = (val[y] * 10ll + w) % 1000000007;
		}
	}
	for (int i=2; i<=n; i++)
		cout << val[i] << '\n';
}