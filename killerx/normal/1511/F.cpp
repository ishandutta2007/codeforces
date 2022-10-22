#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 165;
const int mod = 998244353;

struct Mat {
	int a[mxn][mxn];

	Mat() { memset(a, 0, sizeof(a)); }

	Mat operator * (const Mat &oth) const {
		Mat ans;
		rep(i, mxn) rep(j, mxn) rep(k, mxn) {
			(ans.a[i][k] += 1LL * a[i][j] * oth.a[j][k] % mod) %= mod;
		}
		return ans;
	}
};

Mat qpow(Mat x, int n) {
	Mat ans;
	rep(i, mxn) ans.a[i][i] = 1;
	for (; n; n >>= 1, x = x * x)
		if (n & 1) ans = ans * x;
	return ans;
}

int n, m;
char s[8][15];
int go[55][26];
int ed[55];
int tot;
bool vis[55 * 55];
int id[55 * 55];
int itm[55 * 55];
int cnt;

void insert(char *s) {
	int u = 0;
	for (int i = 0; s[i]; ++ i) {
		int c = s[i] - 'a';
		int &to = go[u][c];
		if (!to) to = tot ++;
		u = to;
	}
	ed[u] ++;
}

void dfs(int u, int v) {
	if (u > v) std::swap(u, v);
	if (vis[u * tot + v]) return ;
	vis[u * tot + v] = 1;
	itm[cnt] = u * tot + v;
	id[u * tot + v] = cnt ++;
	rep(c, 26) if (go[u][c] && go[v][c]) {
		dfs(go[u][c], go[v][c]);
		if (ed[go[u][c]]) dfs(0, go[v][c]);
		if (ed[go[v][c]]) dfs(go[u][c], 0);
		if (ed[go[u][c]] && ed[go[v][c]]) dfs(0, 0);
	}
}

Mat trans;

void add_trans(int u, int v, int nu, int nv, int c) {
	if (nu > nv) std::swap(nu, nv);
	int i = id[u * tot + v], j = id[nu * tot + nv];
	(trans.a[i][j] += c) %= mod;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%s", s[i]);
	tot = 1;
	rep(i, n) insert(s[i]);
	dfs(0, 0);
	// eprintf("CNT = %d\n", cnt);
	rep(i, cnt) {
		int u = itm[i] / tot, v = itm[i] % tot;
		rep(c, 26) if (go[u][c] && go[v][c]) {
			add_trans(u, v, go[u][c], go[v][c], 1);
			if (ed[go[u][c]]) add_trans(u, v, 0, go[v][c], ed[go[u][c]]);
			if (ed[go[v][c]]) add_trans(u, v, go[u][c], 0, ed[go[v][c]]);
			if (ed[go[u][c]] && ed[go[v][c]]) add_trans(u, v, 0, 0, ed[go[u][c]] * ed[go[v][c]]);
		}
	}
	Mat init;
	init.a[0][0] = 1;
	Mat ans = init * qpow(trans, m);
	printf("%d\n", ans.a[0][0]);
	return 0;
}