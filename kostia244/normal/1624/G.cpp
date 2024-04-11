#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;
int _deg[1<<20];
struct BFS {
	int vis = 0;
	queue <int> q;
	vector <int> d, p;

	void add(int node, int parent, int dist) {
		q.push(node);
		d[node] = dist;
		p[node] = parent;
	}

	BFS(const vector <vector <int>> &g, const vector <int> &sources) {
		int n = g.size();
		d.assign(n, -1);
		p.assign(n, -1);

		for(const int &node: sources) add(node, -1, 0);
		while(!q.empty()) {
			const int node = q.front();
			q.pop();
			vis++;
			for(const int &child: g[node]) {
				if(d[child] == -1) add(child, node, d[node] + 1);
			}
		}
	}
};

void run_test(int testcase) {
	int n, m;
	cin >> n >> m;
	vector <int> u(m), v(m), c(m), keep(m, 1);
	for(int i = 1; i <= n; i++) _deg[i]=0;
	for(int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> c[i];
		_deg[u[i]]++, _deg[v[i]]++;
	}

	int ans = 0;
	for(int b = 30; b >= 0; b--) {
		int flag = 0;
		vector <vector <int>> adj(n + 1);
		for(int i = 1; i <= n; i++) adj[i].reserve(_deg[i]);
		for(int i = 0; i < m; i++) {
			if(!keep[i]) continue;
			if(!(c[i] & (1 << b))) {
				adj[u[i]].push_back(v[i]);
				adj[v[i]].push_back(u[i]);
			} else {
				flag = 1;
			}
		}

		auto ds = BFS(adj, {1});
		if(ds.vis == n) {
			for(int i = 0; i < m; i++)
				if(keep[i] && (c[i] & (1 << b))) keep[i] = 0, _deg[u[i]]--, _deg[v[i]]--;
		} else {
			if(flag) ans += (1 << b);
		}
		//cout << b << " ";for(int x: keep) cout << x;cout << endl;
	}

	cout << ans << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	#ifndef DUSH1729
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}