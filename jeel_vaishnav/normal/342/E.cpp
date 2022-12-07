#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 2e18

const int N = 1e5 + 5;

// 1-based index
vector<int> adj[N];
int forb[N], sz[N], par[N];
unordered_map<int, int> dist[N];
int ans[N];
void dfs(int u, int p) {
  sz[u] = 1;
  for(int v : adj[u]) {
    if(v != p and !forb[v]) {
      dfs(v, u);
      sz[u] += sz[v];
}}}

int find_cen(int u, int p, int qt) {
  for(int v : adj[u]) {
    if(v == p or forb[v]) continue;
    if(sz[v] > qt / 2) return find_cen(v, u, qt);
  }
  return u;
}

void getdist(int u, int p, int cen) {
  for(int v : adj[u]) {
    if(v != p and !forb[v]) {
      dist[cen][v] = dist[v][cen] = dist[cen][u] + 1;
      getdist(v, u, cen);
}}}

void decomp(int u, int p) {
  dfs(u, -1);
  int cen = find_cen(u, -1, sz[u]);
  forb[cen] = 1;
  par[cen] = p;
  dist[cen][cen] = 0;
  getdist(cen, -1, cen);
  for(int v : adj[cen]) if(!forb[v]) decomp(v, cen);
}
// decomp(1, -1);


void color(int u) {
	int temp = u;
	while(temp != -1) {
		ans[temp] = min(ans[temp], dist[temp][u]);
		temp = par[temp];
	}
}

int query(int u) {
	int cans = inf;
	int temp = u;
	while(temp != -1) {
		// cout << temp << " " << dist[temp][u] << " " << ans[temp] << endl;
		cans = min(cans, dist[temp][u] + ans[temp]);
		temp = par[temp];
	}
	return cans;
}

signed main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	decomp(0, -1);

	for(int i = 1; i <= n; ++i)
		ans[i] = n;

	color(0);
	for(int i = 0; i < m; ++i) {
		int t, u;
		cin >> t >> u;
		u--;

		if(t == 1) {
			color(u);
		} else {
			cout << query(u) << "\n";
		}
	}
}