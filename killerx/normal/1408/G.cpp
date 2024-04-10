#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 1505;
const int mod = 998244353;

int n;
int a[mxn][mxn];
int dp[mxn][mxn];
std::vector <std::pair <int, std::pair <int, int> > > vec;

struct UF {
	int fa[mxn], sz[mxn], esz[mxn];

	UF() { rep(i, mxn) fa[i] = i, sz[i] = 1, esz[i] = 0, dp[i][1] = 1; }

	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			esz[x] ++;
			return ;
		}
		static int f[mxn];
		for (int k = 1; k <= sz[x] + sz[y]; ++ k) f[k] = 0;
		for (int k0 = 1; k0 <= sz[x]; ++ k0) {
			for (int k1 = 1; k1 <= sz[y]; ++ k1) {
				(f[k0 + k1] += ll(dp[x][k0]) * dp[y][k1] % mod) %= mod;
			}
		}
		sz[x] += sz[y];
		esz[x] += esz[y] + 1;
		for (int k = 1; k <= sz[x]; ++ k) dp[x][k] = f[k];
		fa[y] = x;
	}
} uf;

int main() {
	scanf("%d", &n);
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	rep(i, n) rep(j, i) vec.push_back({a[i][j], {i, j}});
	std::sort(vec.begin(), vec.end());
	for (auto x : vec) {
		int u = x.second.first;
		int v = x.second.second;
		uf.merge(u, v);
		if (uf.esz[uf.find(u)] == uf.sz[uf.find(u)] * (uf.sz[uf.find(u)] - 1) / 2)
			(dp[uf.find(u)][1] += 1) %= mod;
	}
	for (int i = 1; i <= n; ++ i)
		printf("%d ", dp[uf.find(1)][i]);
	printf("\n");
	return 0;
}