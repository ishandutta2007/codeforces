#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct dsu {
	vector<int> par, siz;
	void init(int n) {
		vector<int>().swap(par);
		vector<int>().swap(siz);
		par.resize(n);
		for(int i = 0; i < n; i++) par[i] = i;
		siz.resize(n, 1);
	}
	int find(int x) {
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	bool unite(int x, int y) {
		if(x == y) return true;
		x = find(x); y = find(y);
		if(x == y) return false;
		if(siz[x] > siz[y]) swap(x, y);
		siz[y] += siz[x];
		par[x] = y;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	dsu uf;
	while(t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		uf.init(n);
		while(m--) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			ans += (x == y ? 0 : (uf.unite(x, y) ? 1 : 2));
		}
		cout << ans << '\n';
	}
}