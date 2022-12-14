#include <bits/stdc++.h>

template <typename T>
inline bool chkmax(T &a, const T &b) { return (a < b) ? a = b, 1 : 0; }

template <typename T>
inline bool chkmin(T &a, const T &b) { return (a > b) ? a = b, 1 : 0; }

inline long long fpm(long long x, int Exp, const int &mod) { long long res = 1; for (; Exp; Exp >>= 1, x = x * x % mod) if (Exp & 1) res = res * x % mod; return res; }

inline int read() {
	static char ch;
	bool sgn = false;
	while ((ch = getchar()) < '0' || ch > '9')
		if (ch == '-') sgn = true;
	int res = ch - 48;
	while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - 48;
	return (sgn ? -res : res);
}

#define SZ(x) (int)((x).size())
#define mp std::make_pair
#define fst first
#define snd second

const int N = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, col[N], sze[N];
std::vector<int> edge[N];
std::vector<int> ans;
int sum;

inline void dfs1(const int &u, const int &fa) {
	if (col[u] == 0) sze[u] = 1;
	sum += col[u];
	for (int i = 0; i < SZ(edge[u]); ++i) {
		if (edge[u][i] == fa) continue;
		dfs1(edge[u][i], u);
		sze[u] += sze[edge[u][i]];
	}
}

inline void dfs2(const int &u, const int &fa) {
	for (int i = 0; i < SZ(edge[u]); ++i) {
		if (edge[u][i] == fa) continue;
		if (!sze[edge[u][i]]) continue;
		int v = edge[u][i];
		ans.push_back(v);
		sum -= col[v];
		col[v] ^= 1;
		sum += col[v];
		dfs2(v, u);
	}
	if (sum == n) return ; 
	if (u == 1) {
		ans.push_back(edge[u][0]);
		ans.push_back(1);
		ans.push_back(edge[u][0]);
		return ;
	}
	if (col[u] == 0) {
		ans.push_back(fa);
		ans.push_back(u);
		ans.push_back(fa);
		++sum;
	} else {
		ans.push_back(fa);
		sum -= col[fa];
		col[fa] ^= 1;
		sum += col[fa];
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) col[i] = (read() == 1) ? 1 : 0;
	for (int i = 1; i < n; ++i) {
		int a = read(), b = read();
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs1(1, 0);
	ans.push_back(1);
	dfs2(1, 0);
	for (int i = 0; i < SZ(ans); ++i) printf("%d ", ans[i]);
	return 0;
}