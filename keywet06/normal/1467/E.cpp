#include <bits/stdc++.h>

using namespace std;

const int K = 200005;
const int N = 500005;

int l[N], r[N], nn = 0;
int top, stk[N];
int a[N];
vector<int> v[K];

bool f[N], g[N], ff[N];
int n;
vector<int> E[K];
void dfs(int x, int fa) {
	l[x] = ++ nn;
	v[a[x]].push_back(l[x]);
	for (int i = 0; i < (int )E[x].size(); i ++) {
		int to = E[x][i];
		if (to == fa) continue;
		dfs(to, x);
	}
	r[x] = nn;
}

bool dfs2(int x, int fa) {
	bool tmp = true;
	int idx = -1, cnt = 0;
	for (int i = 0; i < (int )E[x].size(); i ++) {
		int to = E[x][i];
		if (to == fa) continue;
		tmp &= dfs2(to, x);
		bool tmp2 = true;
		int id = (int )(lower_bound(v[a[x]].begin(), v[a[x]].end(), l[to]) - v[a[x]].begin());
	
		if (id < (int )v[a[x]].size()) {
			if (v[a[x]][id] <= r[to]) tmp2 = false;
		}

		if (f[to] == false || tmp2 == false) idx = to, ++ cnt;
	}
	if (cnt >= 1) {
		for (int i = 0; i < (int )E[x].size(); i ++) {
			int to = E[x][i];
			if (to == fa) continue;
			if (cnt == 1) {
				if (to == idx) continue;
				ff[to] = false;
			}
			else ff[to] = false;
		}
	}
	int id = (int )(lower_bound(v[a[x]].begin(), v[a[x]].end(), l[x] + 1) - v[a[x]].begin());
	if (id < (int )v[a[x]].size()) {
		if (v[a[x]][id] <= r[x]) tmp = false;
	}
	return f[x] = tmp;
}

void dfs3(int x, int fa) {
	g[x] = (g[fa] & ff[x]);
	int N = (int )v[a[x]].size();
	if (N > 0) {
		int tx = v[a[x]][0];
		int ty = v[a[x]][N - 1];
		if (tx < l[x] || ty > r[x]) g[x] = false;
	}

	for (int i = 0; i < (int )E[x].size(); i ++) {
		int to = E[x][i];
		if (to == fa) continue;
		dfs3(to, x);
	}
}

int main( ) {
	int x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		stk[++ top] = a[i];
	}
	sort(stk + 1, stk + 1 + top);
	int m = (int )(unique(stk + 1, stk + 1 + top) - stk) - 1;
	for (int i = 1; i <= n; i ++)
		a[i] = (int )(lower_bound(stk + 1, stk + 1 + m, a[i]) - stk);
	
	for (int i = 1; i < n; i ++) {
		scanf("%d %d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for (int i = 1; i <= n; i ++) ff[i] = true;
	dfs(1, 0);
	for (int i = 1; i <= m; i ++)
		sort(v[i].begin(), v[i].end());
	dfs2(1, 0);
	g[0] = true;
	dfs3(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += (f[i] & g[i]);
	}
	printf("%d\n", ans);
	return 0;
}