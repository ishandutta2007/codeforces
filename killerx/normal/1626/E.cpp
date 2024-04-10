#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;

struct result {
	int sz, cnt;
	// 0, sz, sz-1

	result(): sz(), cnt() {}
	result(int _sz, int _cnt): sz(_sz), cnt(_cnt) {}
};

struct state {
	int sz, cnt;

	state(): sz(), cnt() {}
	state(int _sz, int _cnt): sz(_sz), cnt(_cnt) {}
};

int n;
bool col[mxn];
std::vector <int> adj[mxn];

state operator + (const state &a, const result &b) {
	return {a.sz + b.sz, a.cnt + b.cnt};
}

state operator + (const state &a, const state &b) {
	return {a.sz + b.sz, a.cnt + b.cnt};
}

result operator ^ (const state &a, int u) {
	if (col[u]) return {a.sz + 1, a.sz + 1};
	else return {a.sz, a.cnt > 1 ? a.sz : a.cnt == 1 ? a.sz - 1 : 0};
}

result f[mxn];

inline void dfs1(int u, int p) {
	state now = state();
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		now = now + f[v];
	}
	f[u] = now ^ u;
}

result g[mxn];

inline void dfs2(int u, int p, result w) {
	std::vector <int> son;
	for (int v : adj[u]) {
		if (v == p) continue;
		son.push_back(v);
	}
	std::vector <state> pre(son.size() + 1), suf(son.size() + 1);
	pre[0] = suf[son.size()] = state();
	rep(i, son.size()) pre[i + 1] = pre[i] + f[son[i]];
	for (int i = son.size() - 1; ~i; -- i) suf[i] = suf[i + 1] + f[son[i]];
	g[u] = (pre[son.size()] + w) ^ u;
	rep(i, son.size()) dfs2(son[i], u, (pre[i] + suf[i + 1] + w) ^ u);
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &col[i]);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(0, -1);
	dfs2(0, -1, result());
	rep(i, n) printf("%d ", g[i].cnt > 0);
	return 0;
}