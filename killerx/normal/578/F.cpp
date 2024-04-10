#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int maxn = 105;
int n, m, mod;
char s[maxn][maxn];

int qp(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int inv(int x) { return qp(x, mod - 2); }

int det(int A[maxn << 1][maxn << 1], int n) {
	int cnt = 0;
	rep(i, n) {
		int bes = i;
		for (int j = i + 1; j < n; ++ j)
			if (A[j][i] > A[bes][i]) bes = j;
		if (bes != i) {
			++ cnt;
			rep(j, n) swap(A[i][j], A[bes][j]);
		}
		if (A[i][i] == 0) return 0;
		int ri = inv(A[i][i]);
		for (int j = i + 1; j < n; ++ j) {
			int r = 1LL * A[j][i] * ri % mod;
			rep(k, n) {
				(A[j][k] += mod - 1LL * r * A[i][k] % mod) %= mod;
			}
		}
	}
	int ans = 1;
	if (!((cnt ^ (n - 1)) & 1)) ans = mod - 1;
	rep(i, n) ans = 1LL * ans * A[i][i] % mod;
	return ans;
}

struct UF {
	static const int maxn = 23333;
	int fa[maxn], rnk[maxn];
	void clear() { rep(i, maxn) fa[i] = i, rnk[i] = 1; }
	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (rnk[x] < rnk[y]) swap(x, y);
		fa[y] = x;
		if (rnk[x] == rnk[y]) ++ rnk[x];
	}
} uf;

int ans;
int id[maxn][maxn];
int tot;
int A[maxn << 1][maxn << 1];
vector <int> rts;

int getid(int x) {
	return lower_bound(rts.begin(), rts.end(), x) - rts.begin();
}

inline void add_edge(int u, int v) {
	if (!~u || !~v) return ;
	u = getid(uf.find(u));
	v = getid(uf.find(v));
	if (u == v) return ;
	(A[u][v] += 1) %= mod;
	(A[v][u] += 1) %= mod;
	(A[u][u] += mod - 1) %= mod;
	(A[v][v] += mod - 1) %= mod;
}

void solve(int c) {
	tot = 0;
	rep(i, n + 1) rep(j, m + 1) id[i][j] = -1;
	rep(i, n + 1) rep(j, m + 1) if ((i + j) % 2 == c) id[i][j] = tot ++;
	uf.clear();
	rep(i, n) rep(j, m) {
		int x = 0, y = 0;
		if (s[i][j] == '\\') x = id[i][j], y = id[i + 1][j + 1];
		else if (s[i][j] == '/') x = id[i][j + 1], y = id[i + 1][j];
		if (!~x || !~y) continue;
		uf.merge(x, y);
	}
	rts.clear();
	rep(i, tot) if (uf.find(i) == i) rts.pb(i);
	if (rts.size() > 200) return ;
	rep(i, rts.size()) rep(j, rts.size()) A[i][j] = 0;
	rep(i, n) rep(j, m) if (s[i][j] == '*') {
		int a = id[i][j], b = id[i][j + 1];
		int c = id[i + 1][j], d = id[i + 1][j + 1];
		add_edge(a, d); add_edge(b, c);
	}
	(ans += det(A, rts.size() - 1)) %= mod;
}

int main() {
	scanf("%d %d %d", &n, &m, &mod);
	rep(i, n) scanf("%s", s[i]);
	solve(0); solve(1);
	printf("%d\n", ans);
	return 0;
}