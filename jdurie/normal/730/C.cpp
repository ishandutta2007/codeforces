#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) int x; cin >> x;
#define F(i, l, r) for(int i = l; i < r; i++)

#define NN 5050
vector<int> edges[NN];
vector<int> stores[NN];
vector<pair<pair<int, int>, int>> from[NN];
bool vis[NN];
int dis[NN];
bool call[NN];
int c[NN], k[NN], p[NN];

void bfs(int s) {
	memset(vis, 0, sizeof vis);
	queue<int> fringe;
	vis[s] = 1;
	fringe.push(s);
	dis[s] = 0;
	while (!fringe.empty()) {
		int u = fringe.front();
		for (auto o:stores[u]) {
			from[s].push_back({{p[o], dis[u]}, o});
		}
		fringe.pop();
		for (auto v:edges[u]) {
			if (vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u]+1;
			fringe.push(v);
		}
	}
	sort(from[s].begin(), from[s].end());
}

bool works(int x, int g, int r, int a) {
	int need = r;
	int cash = a;
	for (auto s:from[g]) {
		int i = s.second;
		if (s.first.second > x) continue;

		ll take = min(need, k[i]);
		ll mon = take*p[i];
		if (mon>cash) return false;
		cash -= mon;
		need -= take;
	}
	if (need || (cash<0)) return false;
	return true;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int w;
	cin>>w;
	for (int i=0; i<w; ++i) {
		scanf("%d %d %d", &c[i], &k[i], &p[i]);
		stores[c[i]].push_back(i);
	}
	int q;
	scanf("%d", &q);
	for (int W=0; W<q; ++W) {
		int g, R, a;
		scanf("%d %d %d", &g, &R, &a);
		if (!call[g]) {
			call[g] = 1;
			bfs(g);
		}
		int l = -1, r = 5010;
		if (works(r, g, R, a)==0) {puts("-1"); continue;}
		while (r-l>1) {
			int M = (r+l)/2;
			if (works(M,g , R, a)) r = M;
			else l = M;
		}
		printf("%d\n", r);
	}
}