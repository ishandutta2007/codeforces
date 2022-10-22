#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, m;
std::vector <int> adj[mxn];
bool hav_rig[mxn];
int sum_rig[mxn];
std::vector <int> nadj[mxn], nradj[mxn];

bool vis_1[mxn][2], vis_2[mxn][2];

void dfs_1(int u, int c) {
	vis_1[u][c] = 1;
	for (int v : nradj[u]) {
		if (!vis_1[v][c ^ 1]) {
			dfs_1(v, c ^ 1);
		}
	}
}

void dfs_2(int u, int c) {
	vis_2[u][c] = 1;
	for (int v : nadj[u]) {
		if (!vis_2[v][c ^ 1]) {
			dfs_2(v, c ^ 1);
		}
	}
}

void Main() {
	scanf("%d %d", &n, &m);
	n += 2;
	rep(i, n) adj[i].clear();
	rep(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i < n - 1; ++ i) {
		adj[0].push_back(i);
		adj[i].push_back(n - 1);
	}
	rep(i, n) {
		hav_rig[i] = false;
		for (int j : adj[i]) if (j == i + 1) hav_rig[i] = true;
	}
	rep(i, n) sum_rig[i + 1] = sum_rig[i] + hav_rig[i];
	rep(i, n) nadj[i].clear(), nradj[i].clear();
	rep(i, n) for (int j : adj[i]) if (j > i + 1) {
		if (sum_rig[j - 1] - sum_rig[i + 1] == (j - 1) - (i + 1)) {
			// eprintf("edge: %d %d\n", i, j - 1);
			nadj[i].push_back(j - 1);
			nradj[j - 1].push_back(i);
		}
	}
	rep(i, n - 1) rep(j, 2) vis_1[i][j] = vis_2[i][j] = 0;
	int i = 0;
	while (hav_rig[i]) ++ i;
	// eprintf("%d %d\n", i, n);
	if (i == n - 1) printf("%lld\n", 1LL * (n - 2) * (n - 3) / 2);
	else {
		dfs_1(i, 0);
		dfs_2(i, 0);
		int ans_10 = 0, ans_11 = 0, ans_1 = 0, ans_20 = 0, ans_21 = 0, ans_2 = 0;
		bool ml = 0, mr = 0;
		for (int j = 0; j < n; ++ j) {
			ans_10 += vis_1[j][0];
			ans_11 += vis_1[j][1];
			ans_1 += vis_1[j][0] * vis_1[j][1];
			ml |= j == i;
			if (!hav_rig[j]) break;
		}
		for (int j = n - 2; ~j; -- j) {
			ans_20 += vis_2[j][0];
			ans_21 += vis_2[j][1];
			ans_2 += vis_2[j][0] * vis_2[j][1];
			mr |= j == i;
			if (!hav_rig[j]) break;
		}
		// eprintf("%d %d %d %d %d %d\n", ans_10, ans_20, ans_11, ans_21, ans_1, ans_2);
		long long ans = 1LL * ans_10 * ans_20 + 1LL * ans_11 * ans_21 - 1LL * ans_1 * ans_2;
		if (ml && mr) -- ans;
		printf("%lld\n", ans);
	}
}

int main() {
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}