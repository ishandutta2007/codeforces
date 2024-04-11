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
	int solve() {
		int ans = 0, t;
		while(bfs()) {
			while(t = dfs()) {
				ans += t;
			}
		}
		return ans;
	}
};
int n, m;
char mat[maxn][maxn];
int V[maxn][maxn], H[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
			cin >> mat[i][j];
	int N = 2, total = 0;
	memset(H, -1, sizeof H);
	memset(V, -1, sizeof V);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(mat[i][j] == '.') continue;
			total++;
			if(mat[i][j] == mat[i+1][j])
				V[i][j] = N++;
			if(mat[i][j] == mat[i][j+1])
				H[i][j] = N++;
		}
	Dinic d(N);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(H[i][j] != -1) d.add(0, H[i][j]);
			if(V[i][j] != -1) d.add(V[i][j], 1);
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(H[i][j] == -1) continue;
			if(V[i][j] != -1) d.add(H[i][j], V[i][j]);
			if(V[i][j+1] != -1) d.add(H[i][j], V[i][j+1]);
			if(i&&V[i-1][j] != -1) d.add(H[i][j], V[i-1][j]);
			if(i&&V[i-1][j+1] != -1) d.add(H[i][j], V[i-1][j+1]);
		}
	cout << total - (N-2) + d.solve() << '\n';
}