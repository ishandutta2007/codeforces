#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int N = 400005;

int n, m;
int u[N], v[N], vis[N];
int s, t, ds, dt;

int fa[N];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}


#define mp(a,b) make_pair(a,b)
vector<pii> ans;
void gao(int u, int v) {
	int pu = find(u);
	int pv = find(v);
	if (pu != pv) {
		ans.push_back(mp(u, v));
		if (u == s || v == s) ds--;
		if (v == t || u == t) dt--;
		fa[pu] = pv;
	}
}


int to[N][2];
int vi[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < m; i++) scanf("%d%d", &u[i], &v[i]);
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	for (int i = 0; i < m; i++) {
		if (u[i] != s && u[i] != t && v[i] != s && v[i] != t) {
			gao(u[i], v[i]);
			vis[i] = 1;
		}
	}
	int f = 0;
	memset(to, -1, sizeof(to));
	for (int i = 0; i < m; i++) {
		if (vis[i]) continue;
		if ((u[i] == s && v[i] == t) || (u[i] == t && v[i] == s)) f = 1;
		else {
			if (u[i] == s) {
				to[find(v[i])][0] = i;
			}
			if (v[i] == s) {
				to[find(u[i])][0] = i;
			}
			if (u[i] == t) {
				to[find(v[i])][1] = i;
			}
			if (v[i] == t) {
				to[find(u[i])][1] = i;
			}
		}
	}
	int ff = 0;
	for (int i = 1; i <= n; i++) {
		if (to[i][0] != -1 && to[i][1] != -1) {
			ff = 1;
			vis[i] = 1;
			gao(u[to[i][0]], v[to[i][0]]);
			gao(u[to[i][1]], v[to[i][1]]);
			break;
		}
	}
	if (!ff && !f) {
		printf("No\n");
		return 0;
	}
	if (!ff) {
		gao(s, t);
	}
	for (int i = 1; i <= n; i++) {
		if (to[i][0] != -1 && to[i][1] != -1) {
			if (ds > dt) {
				gao(u[to[i][0]], v[to[i][0]]);
			} else {
				gao(u[to[i][1]], v[to[i][1]]);
			}
		} else if (to[i][0] != -1) {
			gao(u[to[i][0]], v[to[i][0]]);
		} else if (to[i][1] != -1) {
			gao(u[to[i][1]], v[to[i][1]]);
		}
	}
	if (ds < 0 || dt < 0) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}