#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long ll;

int n, L, W;
vector <pair <int, int> > g[N];

int sum[N], tme, tms[N];

void clear() {
	tme ++;
}

void upd(int x, int v) {
	for (++ x; x < N; x += x & -x) {
		if (tms[x] != tme) sum[x] = 0, tms[x] = tme;
		sum[x] += v;
	}
}

int qry(int x) {
	int ans = 0;
	for (++ x; x; x -= x & -x) {
		if (tms[x] != tme) sum[x] = 0, tms[x] = tme;
		ans += sum[x];
	}
	return ans;
}

ll ans;
bool used[N];
int siz[N], mn, mnn, nn;

void dfs0(int u, int p) {
	siz[u] = 1;
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i].first, w = g[u][i].second;
		if (v == p) continue;
		if (used[v]) continue;
		dfs0(v, u);
		siz[u] += siz[v];
	}
}

void dfs1(int u, int p) {
	int mx = 0;
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i].first, w = g[u][i].second;
		if (v == p) continue;
		if (used[v]) continue;
		dfs1(v, u);
		mx = max(mx, siz[v]);
	}
	mx = max(mx, nn - siz[u]);
	if (mx < mn) {
		mn = mx;
		mnn = u;
	}
}

int find_centroid(int r) {
	mn = n; mnn = -1;
	dfs0(r, -1);
	nn = siz[r];
	dfs1(r, -1);
	return mnn;
}

int dis[N], dis0[N];
vector <pair <int, int> > V;

void dfs2(int u, int p, int d, int d0) {
	dis[u] = d; dis0[u] = d0;
	V.push_back(make_pair(dis[u], dis0[u]));
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i].first, w = g[u][i].second;
		if (v == p) continue;
		if (used[v]) continue;
		dfs2(v, u, d + w, d0 + 1);
	}
}

ll calc(vector <pair <int, int> > &v) {
	sort(v.begin(), v.end());
	clear();
	ll res = 0;
	for (int i = v.size() - 1, j = 0; ~i; -- i) {
		while (j < v.size() && v[j].first + v[i].first <= W)
			upd(v[j ++].second, 1);
		if (v[i].second <= L) {
			bool can_self = v[i].second * 2 <= L && j > i;
			res += qry(L - v[i].second) - can_self;
		}
	}
	return res / 2;
}

void solve(int r) {
	int G = find_centroid(r);
//	cerr << "root " << r << " centroid " << G << endl;
	vector <pair <int, int> > subtree;
	subtree.push_back(make_pair(0, 0));
	for (int i = 0; i < g[G].size(); ++ i) {
		int u = g[G][i].first, w = g[G][i].second;
		if (used[u]) continue;
		V.clear();
		dfs2(u, G, w, 1);
		ans -= calc(V);
		for (int j = 0; j < V.size(); ++ j)
			subtree.push_back(V[j]);
	}
	ans += calc(subtree);
	used[G] = 1;
	for (int i = 0; i < g[G].size(); ++ i) {
		int u = g[G][i].first;
		if (used[u]) continue;
		solve(u);
	}
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> L >> W;
	for (int i = 1; i < n; ++ i) {
		int p, w;
		cin >> p >> w;
		-- p;
		g[p].push_back(make_pair(i, w));
		g[i].push_back(make_pair(p, w));
	}
	solve(0);
	cout << ans << endl;
	return 0;
}

/*
4 4 6
1 3
1 4
1 3

4

6 2 17
1 3
2 5
2 13
1 6
5 9

9

*/