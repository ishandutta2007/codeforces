#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 202;
struct Edge {
	int u, v, flow, cap;
	Edge(int U, int V, int C) : u(U), v(V), cap(C), flow(0) {};
};
struct Dinic {
	int n;
	vector<Edge> e;
	vector<vector<int>> g;
	vector<int> h, vis, pos;
	Dinic(int n) : n(n) {
		g.resize(n);
	}
	void add(int u, int v, int c = 1) {
		g[u].push_back(e.size());
		e.emplace_back(u, v, c);
		g[v].push_back(e.size());
		e.emplace_back(v, u, 0);
	}
	bool bfs() {
		queue<int> q;
		h.assign(n, 0);
		vis.assign(n, 0);
		pos.assign(n, 0);
		q.push(1);
		vis[1] = 1;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto &i : g[v]) {
				if(!vis[e[i].v] && e[i^1].cap != e[i^1].flow) {
					h[e[i].v] = h[v]+1;
					vis[e[i].v] = 1;
					q.push(e[i].v);
				}
			}
		}
		return h[0];
	}
	int dfs(int v = 0, int low = 1<<30) {
		if(!low || v==1) return low;
		for(int &_i = pos[v]; _i < g[v].size(); _i++) {
			int i = g[v][_i];
			if(h[e[i].v]+1 != h[v] || e[i].cap == e[i].flow) continue;
			int f = dfs(e[i].v, min(low, e[i].cap - e[i].flow));
			if(f) {
				e[i].flow += f;
				e[i^1].flow -= f;
				return f;
			}
		}
		return 0;
	}
	int ans = 0, t;
	int solve() {
		while(bfs()) {
			while(t = dfs()) {
				ans += t;
			}
		}
		return ans;
	}
};
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
	vector<array<int, 3>> edges(m);
	for(auto &[a, b, c] : edges) {
		cin >> b >> c >> a;b++, c++;
	}
	sort(all(edges));
	int ans = 0;
	Dinic f(2*n+2);
	for(int i = 1; i <= n; i++) f.add(0, 1+i);
	for(int i = 1; i <= n; i++) f.add(n+1+i, 1);
	for(int i = 1<<20; i>>=1;) {
		if(ans+i > m) continue;
		Dinic tmp = f;
		for(int j = ans; j < ans+i; j++) tmp.add(edges[j][1], n+edges[j][2]);
		if(tmp.solve() < n) ans += i, f = tmp;
	}
	if(ans == m) cout << -1;
	else cout << edges[ans][0] << '\n';
}