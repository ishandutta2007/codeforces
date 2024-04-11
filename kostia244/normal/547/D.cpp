#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<20, B = 1<<18, mod = 1e9 + 7;
int n, used[maxn], used2[maxn], vis[maxn], curl = 0;
vector<array<int, 3>> g[maxn];
void dfs(int v) {
	vis[v] = 1;
	while(!g[v].empty()) {
		auto [t, rid, tid] = g[v].back();
		g[v].pop_back();
		if(!used[tid]) {
			used2[rid] = used[tid] = curl++;
			//cout << v << " " << t << " " << rid << endl;
			dfs(t);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int pid = 0;
	for(int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		g[x].push_back({B+y, 1+i, pid});
		g[B+y].push_back({x, 1+i, pid++});
	}
	for(int i = 1; i < B; i++) {
		if(g[i].size()&1) {
			g[i].push_back({B, 0, pid});
			g[B].push_back({i, 0, pid++});
		}
		if(g[B+i].size()&1) {
			g[0].push_back({B+i, 0, pid});
			g[B+i].push_back({0, 0, pid++});
		}
	}
	if(g[0].size()&1) {
		g[0].push_back({B, 0, pid});
		g[B].push_back({0, 0, pid++});
	}
	for(int i = 0; i < maxn; i++) if(!vis[i]) dfs(i);
	for(int i = 1; i <= n; i++) cout << (used2[i]%2?'r':'b'); cout << '\n';
}