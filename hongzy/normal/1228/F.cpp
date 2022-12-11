#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int d, n;
vector<int> G[N], ans;
int sz[N], w[N], g1, g2;
void dfs(int u, int fa = 0) {
	sz[u] = 1; w[u] = 0;
	for(int v : G[u]) if(v != fa)  {
		dfs(v, u); sz[u] += sz[v];
		w[u] = max(w[u], sz[v]);
	}
	w[u] = max(w[u], n - 1 - sz[u]);
	if(!g1 || w[u] < w[g1]) g1 = u, g2 = 0;
	else if(w[u] == w[g1]) g2 = u;
}
int de[N];
bool check(int u, int fa = 0) {
	int deg = 0; bool ans = 1; de[u] = de[fa] + 1;
	for(int v : G[u]) if(v && v != fa) {
		deg ++;
		if(deg > 2 || !check(v, u)) { ans = 0; break ; }
	}
	if(ans) {
		if(deg == 0) ans &= de[u] == d;
		else if(deg != 2) ans = 0;
	}
	return ans;
}
void link(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}
int ug(int g) { return g == g1 ? g2 : g1; }
int du[5], nf[N];
void dfs2(int u, int fa = 0) {
	nf[u] = fa; sz[u] = 1;
	if(G[u].size() == 4) du[4] = u;
	if(G[u].size() == 2) du[2] = u;
	for(int v : G[u]) if(v != fa && v != g1 && v != g2) {
		dfs2(v, u); sz[u] += sz[v];
	}
}
void work(int u, int g) {
	du[2] = du[4] = 0; dfs2(u, g);
	if(du[2]) {
		link(du[2], n);
		if(check(g)) ans.push_back(du[2]);
		G[du[2]].pop_back(); G[n].clear();
	} else if(du[4]) {
		int u = du[4], u1 = -1, u2 = -1, u3 = -1, mx = 0;
		for(int v : G[u]) {
			if(v == nf[u]) continue ;
			if(u1 == -1) u1 = v;
			else if(u2 == -1) u2 = v;
			else if(u3 == -1) u3 = v;
			mx = max(mx, sz[v]);
		}
		if(sz[u1] == mx) swap(u1, u3);
		if(sz[u2] == mx) swap(u2, u3);
		for(int &v : G[u1]) if(v == u) v = n;
		for(int &v : G[u2]) if(v == u) v = n;
		for(int &v : G[u]) {
			if(v == u1) v = 0;
			else if(v == u2) v = n;
		}
		G[n].push_back(u);
		G[n].push_back(u1); G[n].push_back(u2);
		if(check(g)) ans.push_back(du[4]);
		for(int &v : G[u1]) if(v == n) v = u;
		for(int &v : G[u2]) if(v == n) v = u;
		for(int &v : G[u]) {
			if(v == 0) v = u1;
			else if(v == n) v = u2;
		}
		G[n].clear();
	}
}
void solve(int g) {
	int s = G[g].size();
	if(s == 3) {
		int s1 = -1, s2 = -1;
		for(int v : G[g]) if(v != g1 && v != g2) {
			if(s1 == -1) s1 = v;
			else if(s2 == -1) s2 = v;
		}
		for(int &v : G[s1]) if(v == g) v = n;
		for(int &v : G[s2]) if(v == g) v = n;
		for(int &v : G[g]) {
			if(v == s1) v = 0;
			else if(v == s2) v = n;
		}
		G[n].push_back(g);
		G[n].push_back(s1); G[n].push_back(s2);
		if(check(g)) ans.push_back(g);
		for(int &v : G[s1]) if(v == n) v = g;
		for(int &v : G[s2]) if(v == n) v = g;
		for(int &v : G[g]) {
			if(v == 0) v = s1;
			else if(v == n) v = s2;
		}
		G[n].clear();
	}
	if(s == 2) {
		for(int v : G[g]) if(v != g1 && v != g2) {
			work(v, g); break ;
		}
	}
}
int main() {
	int u, v; scanf("%d", &d); n = (1 << d) - 1;
	if(d == 2) {
		puts("2");
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		printf("%d %d\n", u, v);
		return 0;
	}
	for(int i = 1; i <= n - 2; i ++) {
		scanf("%d%d", &u, &v); link(u, v);
	}
	for(int i = 1; i < n; i ++) if(G[i].size() >= 5) return puts("0"), 0;
	dfs(1); solve(g1); solve(g2);
	printf("%d\n", (int) ans.size());
	sort(ans.begin(), ans.end());
	for(int v : ans) printf("%d ", v);
	return 0;
}