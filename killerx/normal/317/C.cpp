#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 305;
int n, v, e;
int a[mxn], b[mxn];
bool adj[mxn][mxn];
bool vis[mxn];
vector <pair <pair <int, int>, int> > oper;

vector <int> dfs(int S, int u) {
	if (vis[u]) return {};
	vis[u] = 1;
	if (S == u) return {u};
	rep(v, n) if (adj[v][u]) {
		auto vec = dfs(S, v);
		if (vec.empty()) continue;
		vec.pb(u);
		return vec;
	}
	return {};
}

void flow(int u, int v, int w) {
	if (!w) return ;
	memset(vis, 0, sizeof(vis));
	auto vec = dfs(u, v);
	if (vec.empty()) return ;
//	cerr << u << " " << v << " " << w << endl;
//	cerr << "["; for (auto x : vec) cerr << x << " "; cerr << "]";
//	cerr << endl;
	int last = vec.size() - 1;
	for (int i = vec.size() - 1; ~i; -- i) {
		if (a[vec[i]] >= w) {
			for (int j = i; j + 1 <= last; ++ j) {
				oper.pb({{vec[j], vec[j + 1]}, w});
				a[vec[j]] -= w;
				a[vec[j + 1]] += w;
			}
			last = i;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &v, &e);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	rep(i, e) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u; -- v;
		adj[u][v] = adj[v][u] = 1;
	}
	rep(i, n) if (a[i] > b[i]) {
		rep(j, n) if (a[j] < b[j]) {
			int fl = min(a[i] - b[i], b[j] - a[j]);
			flow(i, j, min(fl, v / 2));
			flow(i, j, max(0, fl - v / 2));
		}
	}
	rep(i, n) if (a[i] != b[i]) {
		printf("NO\n");
		return 0;
	}
	printf("%d\n", (int) oper.size());
	for (auto p : oper) {
		int u = p.first.first;
		int v = p.first.second;
		int w = p.second;
		printf("%d %d %d\n", u + 1, v + 1, w);
	}
	return 0;
}