#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<18;
int ans = 0;
struct dsu {
	vector<int> r, p;
	vector<vector<int>> t;
	dsu(int n) : r(n, 1), p(n), t(n) {
		iota(p.begin(), p.end(), 0);
		for(int i = 0; i <n ;i++) t[i] = {i};
	}
	int par(int v) {
		return p[v] == v ? v : p[v] = par(p[v]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		for(auto x : t[j]) if(x) ans += par(x-1) == i;
		for(auto x : t[j]) if(x+1<r.size()) ans += par(x+1) == i;
		r[i] += r[j];
		p[j] = i;
		for(auto x : t[j])
			t[i].push_back(x);
	}
};
vector<int> b[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		b[--t].push_back(i);
	}
	dsu d(n);
	for(int i = 0; i < m; i++)
		for(int j = 1; j < b[i].size(); j++)
			d.unite(b[i][j], b[i][j-1]);
	cout << n-1-ans << '\n';
	for(int x, y, i = 1; i < m; i++) {
		cin >> x >> y;--x, --y;
		d.unite(b[x][0], b[y][0]);
		cout << n-1-ans << '\n';
	}
}