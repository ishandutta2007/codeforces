#include <bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define ppp pop_back
#define rez resize
#define gc getchar
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef pair <int, ll> pil;
typedef vector <int> poly;
typedef vector <pii> vii;
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1; !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
namespace modular {
	const int mod = 998244353;
	inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
	inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
	inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
}
const int N = 505;
int n, m, K, dx[4] = {0, 0, 1, -1} ,dy[4] = {1, -1, 0, 0}, du[N * N];
int que[N * N], hd, tl;
char s[N];
int a[N][N];
bool vs[N * N];
inline int id1(int x, int y) { return (x - 1) * m + y; }
inline pii id2(int x) { return x % m ? pii(x / m + 1, x % m) : pii(x / m, m); }
vector <int> e[N * N], g[N * N];
void dfs(int p) {
	vs[p] = 1;
	for (ri i = 0, v; i < g[p].size(); ++i) {
		v = g[p][i];
		if (vs[v]) continue;
		++du[p];
		++du[v];
		e[p].pb(v);
		e[v].pb(p);
		dfs(v);
	}
}
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	n = read(), m = read(), K = read();
	for (ri i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (ri j = 1; j <= m; ++j) a[i][j] = s[j] == '.';
	}
	for (ri i = 1; i <= n; ++i) {
		for (ri j = 1; j <= m; ++j) if (a[i][j]) {
			for (ri d = 0; d < 4; ++d) {
				int x = i + dx[d], y = j + dy[d];
				if (x > n || y > m || !x || !y) continue;
				if (a[x][y]) {
					g[id1(i, j)].pb(id1(x, y));
				}
			}
		}
	}
	for (ri i = 1; i <= n; ++i) for (ri j = 1; j <= m; ++j) if (a[i][j]) {
		dfs(id1(i, j));
		break;
	}
	if (K) {
		hd = 1, tl = 0;
		for (ri i = 1; i <= n * m; ++i) if (du[i] == 1) que[++tl] = i;
		int ct = 0;
		while (hd <= tl) {
			int x = que[hd++];
			++ct;
			pii t = id2(x);
			a[t.fi][t.se] = 2;
			if (ct == K) break;
			for (ri j = 0, v; j < e[x].size(); ++j) {
				v = e[x][j];
				--du[v];
				if (du[v] == 1) que[++tl] = v;
			}
		}
	}
	for (ri i = 1; i <= n; ++i) {
		for (ri j = 1; j <= m; ++j) {
			if (!a[i][j]) putchar('#');
			else if (a[i][j] == 1) putchar('.');
			else putchar('X');
		}
		puts("");
	}
	return 0;
}