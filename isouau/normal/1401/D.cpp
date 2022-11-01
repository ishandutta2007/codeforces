#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5, md = 1e9 + 7;

vector <int> adj[N];
int siz[N], p[N]; ll sum[N];
int T, n, m;

void dfs1(int u, int fa) {
	siz[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		dfs1(v, u);
		siz[u] += siz[v];
	}
	sum[u] = 1ll * siz[u] * (n - siz[u]);
}

int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			read(u); read(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(1, 0);
		sum[1] = sum[n];
		sort(sum + 1, sum + n);
		read(m);
		for (int i = 1; i <= m; i++) read(p[i]);
		sort(p + 1, p + m + 1);
		while (m > n - 1) p[m - 1] = 1ll * p[m - 1] * p[m] % md, --m;
		int ans = 0;
		for (int i = 1; i <= m; i++) ans = (ans + 1ll * p[m - i + 1] * (sum[n - i] % md) % md) % md;
		for (int i = 1; i <= n - 1 - m; i++) ans = (ans + sum[i]) % md;
		print(ans, '\n');
	}
	return 0;
}