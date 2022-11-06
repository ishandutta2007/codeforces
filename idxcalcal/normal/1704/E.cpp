#include <bits/stdc++.h>
using namespace std;
#define gc getchar
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
typedef long long ll;
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
		for (res = 1; p; p >>= 1, Mul(a, a)) if (p & 1) Mul(res, a);
		return res;
	}
}	using namespace modular;
typedef pair <int, ll> pil;
typedef double db;
#define fi first
#define se second
#define pb push_back
#define rez resize
#define ppp pop_back
const int N = 2e5 + 5;
int n, m, a[N], b[N];
vector <int> e[N];
int q[N], hd, tl, du[N];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = read(); tt; --tt) {
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) du[i] = 0, a[i] = read(), e[i].rez(0);
		for (int i = 1, x, y; i <= m; ++i) {
			x = read(), y = read();
			e[x].pb(y);
			++du[y];
		}
		bool ff = 1;
		for (int i = 1; i <= n; ++i) if (a[i]) ff = 0;
		if (ff) {
			cout << 0 << '\n';
			continue;
		}
		ff = 1;
		for (int tt = 1; tt <= m; ++tt) {
			for (int i = 1; i <= n; ++i) {
				if (a[i]) b[i] = a[i] - 1;
				else b[i] = 0;
			}
			for (int i = 1; i <= n; ++i) if (a[i])
			for (int j = 0; j < (int) e[i].size(); ++j) ++b[e[i][j]];
			for (int i = 1; i <= n; ++i) a[i] = b[i];
			bool fff = 0;
			for (int i = 1; i <= n; ++i) if (a[i]) fff = 1;
			if (!fff) {
				ff = 0;
				cout << tt << '\n';
				break;
			}
		}
		if (!ff) continue;
		for (int i = 1; i <= n; ++i) a[i] %= mod;
		hd = 1, tl = 0;
		for (int i = 1; i <= n; ++i) if (!du[i]) q[++tl] = i;
		while (hd <= tl) {
			int x = q[hd++];
			for (int i = 0, v; i < (int) e[x].size(); ++i) {
				v = e[x][i];
				--du[v];
				Add(a[v], a[x]);
				if (!du[v]) q[++tl] = v;
			}
		}
		cout << add(m, a[q[tl]]) << '\n';
	}
	return 0;
}