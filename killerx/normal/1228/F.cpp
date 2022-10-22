#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int mm;
int n;
set <int> g[1<<17], ng[1<<17];
vi deg[1<<17];

void cp() {
	rep(i, n) {
		ng[i] = g[i];
	}
}

ll disall[1<<17];
int siz[1<<17];

void dfs1(int u, int p) {
	siz[u] = 1;
	disall[u] = 0;
	foreach(it, ng[u]) {
		int v = *it;
		if (v == p) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		disall[u] += disall[v] + siz[v];
	}
} 

bool flg = 1;
ll disfull[1<<17];

void dfs2(int u, int p, ll w) {
	disfull[u] = disall[u] + w;
	foreach(it, ng[u]) {
		int v = *it;
		if (v == p) continue;
		dfs2(v, u, w + (n - flg - siz[v]) + disall[u] - disall[v] - siz[v]);
	}
}

int dis[1<<17];

void dfs3(int u, int p, int d) {
	dis[u] = d;
	foreach(it, ng[u]) {
		int v = *it;
		if (v == p) continue;
		dfs3(v, u, d + 1);
	}
}

int cnt[20];

bool chk() {
	dfs1(0, -1);
	dfs2(0, -1, 0);
	ll mx = inf;
	rep(i, n) mx = min(mx, disfull[i]);
	vi roots;
	rep(i, n) if (disfull[i] == mx) {
		roots.pb(i);
	}
	if (roots.size() > 5) return 0;
	rep(i, roots.size()) {
		int r = roots[i];
		dfs3(r, -1, 0);
		bool ok = 1;
		rep(j, n) {
			if (dis[j] >= mm) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			memset(cnt, 0, sizeof(cnt));
			rep(j, n) cnt[dis[j]] ++;
			for (int j = 1; j < mm; ++ j) {
				if (cnt[j] != 2 * cnt[j - 1]) {
					ok = 0; break;
				}
			}
			rep(j, n) if (j != roots[i]) {
				if (ng[j].size() != 3 && ng[j].size() != 1) ok = 0;
			}
			if (ok) return 1;
		}
	}
	return 0;
}

bool ismx[1<<17];

int main() {
	mm = read();
	n = (1<<mm) - 1;
	rep(i, n - 2) {
		int u = read() - 1;
		int v = read() - 1;
		g[u].insert(v);
		g[v].insert(u);
	}
	rep(i, n - 1) deg[g[i].size()].pb(i);
	rep(i, n + 1) if (!deg[i].empty() && i > 4) {
		puts("0"); return 0;
	}
	cp();
	dfs1(0, -1);
	dfs2(0, -1, 0);
	ll mx = inf;
	rep(i, n - 1) mx = min(mx, disfull[i]);
	rep(i, n - 1) ismx[i] = disfull[i] == mx;
	vi ans;
	rep(i, 3) if (i == 1 || deg[i].size() <= 5) rep(j, deg[i].size()) {
		if (i == 1 && !ismx[deg[i][j]]) continue;
		cp();
		ng[deg[i][j]].insert(n - 1);
		ng[n - 1].insert(deg[i][j]);
		if (chk()) ans.pb(deg[i][j]);
	}
	rep(j, deg[3].size()) if (ismx[deg[3][j]]) {
		set <int> :: iterator it, jt;
		for (it = g[deg[3][j]].begin(); it != g[deg[3][j]].end(); ++ it) {
			for (jt = g[deg[3][j]].begin(); jt != it; ++ jt) {
				cp();
				ng[deg[3][j]].erase(*it); ng[deg[3][j]].erase(*jt);
				ng[*it].erase(deg[3][j]); ng[*jt].erase(deg[3][j]);
				ng[deg[3][j]].insert(n - 1); ng[n - 1].insert(deg[3][j]);
				ng[n - 1].insert(*it); ng[n - 1].insert(*jt);
				ng[*it].insert(n - 1); ng[*jt].insert(n - 1);
				if (chk()) ans.pb(deg[3][j]);
			}
		}
	}
	flg = 0;
	if (deg[4].size() <= 5) rep(j, deg[4].size()) {
		set <int> :: iterator it, jt;
		for (it = g[deg[4][j]].begin(); it != g[deg[4][j]].end(); ++ it) {
			for (jt = g[deg[4][j]].begin(); jt != it; ++ jt) {
				cp();
				ng[deg[4][j]].erase(*it); ng[deg[4][j]].erase(*jt);
				ng[*it].erase(deg[4][j]); ng[*jt].erase(deg[4][j]);
				ng[deg[4][j]].insert(n - 1); ng[n - 1].insert(deg[4][j]);
				ng[n - 1].insert(*it); ng[n - 1].insert(*jt);
				ng[*it].insert(n - 1); ng[*jt].insert(n - 1);
				if (chk()) ans.pb(deg[4][j]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", int(ans.size()));
	rep(i, ans.size()) printf("%d%c", ans[i] + 1, " \n"[i + 1 == int(ans.size())]);
	return 0;
}