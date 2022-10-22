#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> trAdj; // x, i
vector<pair<int, int>> pa_ord;
vector<pair<int, int>> pa;
vector<bool> isTree;
vector<int> tour, vis, mp, pm, dep, ans, answer;
vector<vector<int>> anc, maxc; // ancestor, min
vector<vector<int>> ad;
// mp: n to tour, pm: tour to n

struct dsu {
	vector<int> par, siz;
	void init(int n) {
		par.resize(n);
		for(int i = 0; i < n; i++) par[i] = i;
		siz.resize(n, 1);
	}
	int find(int x) {
		if(x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		if(siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
	bool unite(pair<int, int> p) {
		return unite(p.first, p.second);
	}
};

struct sparseTable { // on tour vector
	vector<vector<int>> spar;
	void init() {
		spar.push_back(tour);
		int g = 1, i = 0, n = spar[0].size();
		while(g < tour.size()) {
			spar.push_back(vector<int>());
			i++;
			spar[i].resize(n);
			for(int j = 0; j < n; j++) {
				if(j+g < n) spar[i][j] = min(spar[i-1][j], spar[i-1][j+g]);
			}
			g *= 2;
		}
	}
	int mini(int x, int y) {
		if(y < x) swap(x, y);
		int g = 1, i = 0;
		while(g < y-x) {
			g *= 2;
			i++;
		}
		g /= 2;
		i--;
		// cout << x << ' ' << x+g << ' ' << spar[i][x] << '\n';
		// cout << y-g << ' ' << y << ' ' << spar[i][y-g] << '\n';
		return min(spar[i][x], spar[i][y-g]);
	}
};

int ct = 0, de = -1;

void dfs(int n, int par=-1) {
	de++;
	if(par == -1) anc[0][n] = n;
	else anc[0][n] = par;
	dep[n] = de;
	mp[n] = ct;
	pm[ct++] = n;
	vis[n] = tour.size();
	int g = ct-1;
	tour.push_back(g);
	for(auto i : trAdj[n]) {
		if(i.first == par) {
			continue;
		}
		maxc[0][i.first] = pa[i.second].first;
		dfs(i.first, n);
		tour.push_back(g);
	}
	de--;
}

int maxPath(int x, int y) {
	if(x == y) return 0;
	if(dep[x] > dep[y]) swap(x, y);
	int k = 0, g = 1;
	while(g <= dep[y] - dep[x]) {
		k++; g *= 2;
	}
	k--; g /= 2;
	// cout << x << ' ' << y << '\n';
	return max(maxc[k][y], maxPath(x, anc[k][y]));
}

multiset<int> dfs2(int n, int par=-1) {
	multiset<int> s;
	for(auto p : trAdj[n]) {
		if(p.first == par) continue;
		multiset<int> ms = dfs2(p.first, n);
		if(ms.size()) ans[p.second] = *(ms.begin()) - 1;
		else ans[p.second] = -1;
		if(s.size() < ms.size()) swap(s, ms);
		for(int i : ms) s.insert(i);
	}
	for(auto i : ad[n]) {
		if(i < 0) {
			auto it = s.find(-i);
			s.erase(it);
		}
		else s.insert(i);
	}
	return s;
}

/*
3 steps:
* get an MST
* consider each nonMST edge, find answer
  which is max(stuff from x to y) - 1
* consider each MST edge, find answer which 
  is min(stuff that connects x and y) - 1
*/

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	isTree.resize(m);
	trAdj.resize(n);
	vis.resize(n);
	mp.resize(n);
	pm.resize(n);
	dep.resize(n);
	ad.resize(n);
	ans.resize(m);
	answer.resize(m);
	int g = n;
	for(int i = 1; g; i++) {
		g /= 2;
		anc.push_back(vector<int>(n));
		maxc.push_back(vector<int>(n));
	}
	for(int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		adj[x].push_back({y, i});
		pa_ord.push_back({x, y});
		pa.push_back({c, i});
	}
	sort(pa.begin(), pa.end());
	dsu uf;
	uf.init(n);
	g = 0;
	for(int i = 0; i < m; i++) {
		auto p = pa_ord[pa[i].second];
		if(uf.unite(p)) {
			int x = p.first, y = p.second;
			trAdj[x].push_back({y, i});
			trAdj[y].push_back({x, i});
			isTree[i] = true;
			g++;
		}
		if(g == n-1) break;
	}
	dfs(0);
	// for(int i = 0; i < n; i++) {
	// 	cout << mp[i] << ' ';
	// }
	// cout << '\n';
	// for(int i = 0; i < tour.size(); i++) {
	// 	cout << tour[i] << ' ';
	// }
	// cout << '\n';
	sparseTable st;
	st.init();
	// for(int i = 0; i < n; i++) {
	// 	cout << anc[0][i] << ' ';
	// }
	// for(int i = 0; i < n; i++) {
	// 	cout << maxc[0][i] << ' ';
	// }
	// cout << '\n';
	for(int i = 1; i < anc.size(); i++) {
		for(int j = 0; j < n; j++) {
			anc[i][j] = anc[i-1][anc[i-1][j]];
			// cout << anc[i][j] << ' ';
		}
		// cout << '\n';
		for(int j = 0; j < n; j++) {
			maxc[i][j] = max(maxc[i-1][j], maxc[i-1][anc[i-1][j]]);
			// cout << maxc[i][j] << ' ';
		}
		// cout << '\n';
	}
	for(int i = 0; i < m; i++) {
		if(!isTree[i]) {
			int x = pa_ord[pa[i].second].first;
			int y = pa_ord[pa[i].second].second;
			int c = pa[i].first;
			int lc = pm[st.mini(vis[x], vis[y])];
			// cout << x << ' ' << y << ' ' << lc << '\n';
			if(lc == y) swap(x, y);
			ans[i] = max(maxPath(lc, x), maxPath(lc, y)) - 1;
			if(lc == x) {
				ad[lc].push_back(-c);
				ad[y].push_back(c);
			}
			else {
				ad[lc].push_back(-c);
				ad[lc].push_back(-c);
				ad[x].push_back(c);
				ad[y].push_back(c);
			}
		}
		else {
			int x = pa_ord[pa[i].second].first;
			int y = pa_ord[pa[i].second].second;
			// cout << "Tree " << x << ' ' << y << '\n';
		}
	}
	// cout << '\n';
	dfs2(0);
	for(int i = 0; i < m; i++) {
		answer[pa[i].second] = i;
	}
	for(int i = 0; i < m; i++) {
		// if(isTree[answer[i]]) cout << '!';
		cout << ans[answer[i]] << ' ';
	}
	cout << '\n';
}