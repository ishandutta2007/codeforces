#include <bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
namespace modular {
    const int mod = 998244353;
    inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
    inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
    inline int mul(int a, int b) { return (ll) a * b % mod; }
    inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
    inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
    inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
    inline int ksm(int a, int p) {
        static int res;
        for (res = 1; p; p >>= 1, Mul(a, a)) {
            if (p & 1) Mul(res, a);
        }
        return res;
    }
    inline int Inv(int a) { return ksm(a, mod - 2); }
}    using namespace modular;
#define pb push_back
#define rez resize
const int N = 1e5 + 5;
vector <int> e[N];
int n, m, ft[N], fa[N][20], dep[N];
inline int findx(int x) { return x ^ ft[x] ? ft[x] = findx(ft[x]) : x; }
typedef pair <int, int> pii;
#define fi first
#define se second
vector <pii> E;
void dfs(int p) {
	for (int i = 1; i < 20; ++i) fa[p][i] = fa[fa[p][i - 1]][i - 1];
	for (int i = 0, v; i < (int) e[p].size(); ++i) {
		v = e[p][i];
		if (v == fa[p][0]) continue;
		dep[v] = dep[p] + 1;
		fa[v][0] = p;
		dfs(v);
	}
}
inline pii lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int len = dep[x] - dep[y];
	if (len) for (int i = 0; i < 20; ++i) if ((len - 1) >> i & 1) x = fa[x][i];
	if (fa[x][0] == y) return pii(y, x);
	if (len) x = fa[x][0];
	for (int i = 19; ~i; --i) if (fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return pii(fa[x][0], x); 
}
int vl[N];
void Dfs(int p) {
	for (int i = 0, v; i < (int) e[p].size(); ++i) {
		v = e[p][i];
		if (v == fa[p][0]) continue;
		vl[v] += vl[p];
		Dfs(v);
	}
}
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = 1; tt; --tt) {
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) ft[i] = i;
		for (int i = 1, x, y, u, v; i <= m; ++i) {
			u = read(), v = read();
			x = findx(u), y = findx(v);
			if (x != y) {
				ft[y] = x;
				e[u].pb(v);
				e[v].pb(u);
			}
			else E.pb(pii(u, v));
		}
		dfs(1);
		for (int i = 0, x, y; i < (int) E.size(); ++i) {
			x = E[i].fi, y = E[i].se;
			if (dep[x] < dep[y]) swap(x, y);
			pii t = lca(x, y);
			if (t.fi == y) {
				++vl[x];
				++vl[1];
				--vl[t.se];
			} else {
				++vl[x];
				++vl[y];
			}
		}
		Dfs(1);
		for (int i = 1; i <= n; ++i) cout << (vl[i] == (int) E.size());
	}
	return 0;
}