#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;

int n, m;
int S[mxn];
std::set <std::pair <int, int> > adj1[mxn], adj2[mxn], adj[mxn];
std::set <int> hav1, hav2;
int U[mxn * 2], V[mxn * 2];
int ls[mxn * 2], rs[mxn * 2];
bool ans[mxn];

inline void setdir(int i, int u, int v) {
	if (i < m) {
		ans[i] = u == U[i];
		return ;
	}
	if (U[ls[i]] == u || V[ls[i]] == u) {
		int w = U[ls[i]] ^ V[ls[i]] ^ u;
		setdir(ls[i], u, w);
		setdir(rs[i], w, v);
	} else if (U[rs[i]] == u || V[rs[i]] == u) {
		int w = U[rs[i]] ^ V[rs[i]] ^ u;
		setdir(rs[i], u, w);
		setdir(ls[i], w, v);
	} else exit(0);
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		S[u] += w, S[v] += w;
		U[i] = u, V[i] = v;
		if (w == 1) adj1[u].emplace(v, i), adj1[v].emplace(u, i);
		else adj2[u].emplace(v, i), adj2[v].emplace(u, i);
	}
	rep(i, n) if (adj1[i].size() > 1) hav1.insert(i);
	rep(i, n) if (adj2[i].size() > 1) hav2.insert(i);
	int mm = m;
	while (!hav1.empty() || !hav2.empty()) {
		if (!hav1.empty()) {
			int u = *hav1.begin();
			hav1.erase(u);
			std::pair <int, int> p1, p2;
			int v1, i1, v2, i2;
			p1 = *adj1[u].begin(), v1 = p1.first, i1 = p1.second; adj1[u].erase({v1, i1}), adj1[v1].erase({u, i1});
			p2 = *adj1[u].begin(), v2 = p2.first, i2 = p2.second; adj1[u].erase({v2, i2}), adj1[v2].erase({u, i2});
			hav1.erase(v1);
			hav1.erase(v2);
			if (v1 == v2) {
				setdir(i1, u, v1);
				setdir(i2, v2, u);
			} else {
				int i = mm ++;
				U[i] = v1, V[i] = v2;
				adj1[v1].insert({v2, i}), adj1[v2].insert({v1, i});
				ls[i] = i1, rs[i] = i2;
			}
			if (adj1[u].size() > 1) hav1.insert(u);
			if (adj1[v1].size() > 1) hav1.insert(v1);
			if (adj1[v2].size() > 1) hav1.insert(v2);
		} else {
			int u = *hav2.begin();
			hav2.erase(u);
			std::pair <int, int> p1, p2;
			int v1, i1, v2, i2;
			p1 = *adj2[u].begin(), v1 = p1.first, i1 = p1.second; adj2[u].erase({v1, i1}), adj2[v1].erase({u, i1});
			p2 = *adj2[u].begin(), v2 = p2.first, i2 = p2.second; adj2[u].erase({v2, i2}), adj2[v2].erase({u, i2});
			hav2.erase(v1);
			hav2.erase(v2);
			if (v1 == v2) {
				setdir(i1, u, v1);
				setdir(i2, v2, u);
			} else {
				int i = mm ++;
				U[i] = v1, V[i] = v2;
				adj2[v1].insert({v2, i}), adj2[v2].insert({v1, i});
				ls[i] = i1, rs[i] = i2;
			}
			if (adj2[u].size() > 1) hav2.insert(u);
			if (adj2[v1].size() > 1) hav2.insert(v1);
			if (adj2[v2].size() > 1) hav2.insert(v2);
		}
	}
	rep(i, n) for (auto pr : adj1[i]) adj[i].insert(pr);
	rep(i, n) for (auto pr : adj2[i]) adj[i].insert(pr);
	static bool vis[mxn];
	rep(R, n) if (adj[R].size()) {
		std::vector <int> vec;
		std::function <void(int)> dfs = [&] (int u) {
			vec.push_back(u);
			vis[u] = true;
			for (auto pr : adj[u]) {
				int v = pr.first;
				if (!vis[v]) dfs(v);
			}
		};
		dfs(R);
		std::sort(vec.begin(), vec.end(), [&] (int i, int j) {
			return adj[i].size() < adj[j].size();
		});
		std::function <void(int)> DFS = [&] (int u) {
			while (!adj[u].empty()) {
				int v = adj[u].begin()->first;
				int i = adj[u].begin()->second;
				adj[u].erase({v, i});
				adj[v].erase({u, i});
				setdir(i, u, v);
				DFS(v);
			}
		};
		DFS(vec[0]);
	}
	int cnt = 0;
	rep(i, n) cnt += S[i] % 2 == 1;
	printf("%d\n", cnt);
	rep(i, m) putchar(ans[i] + '1');
	puts("");
	return 0;
}