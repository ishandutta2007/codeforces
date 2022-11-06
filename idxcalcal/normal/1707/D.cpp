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
	int mod;
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
typedef pair <int, int> pii;
#define fi first
#define se second
int n;
const int N = 2005;
vector <int> e[N];
int f[N][N], ss[N][N], ans[N], C[N][N], S[N], F[3], G[3], pre[N], suf[N];
void dfs(int p, int ft) {
	bool ff = 0;
	for (int i = 0, v; i < (int) e[p].size(); ++i) {
		v = e[p][i];
		if (v == ft) continue;
		ff = 1;
		dfs(v, p);
	}
	if (!ff) {
		for (int i = 1; i < n; ++i) f[p][i] = 1, ss[p][i] = i;
		return;
	}
	if (p != 1) {
		S[0] = 1;
		for (int i = 1; i <= (int) e[p].size(); ++i) S[i] = 0;
		for (int t = 1; t < n; ++t) { // f[p][t]
			f[p][t] = 0;
			F[0] = 1, F[1] = F[2] = 0;
			pre[0] = 1;
			int ct = 0;
			for (int i = 0, v; i < (int) e[p].size(); ++i) {
				v = e[p][i];
				if (v == ft) continue;
				++ct;
				pre[ct] = mul(pre[ct - 1], ss[v][t - 1]);
			}
			suf[0] = 1;
			ct = 0;
			for (int i = (int) e[p].size() - 1, v; ~i; --i) {
				v = e[p][i];
				if (v == ft) continue;
				++ct;
				suf[ct] = mul(suf[ct - 1], ss[v][t - 1]);
			}
			suf[++ct] = 0;
			reverse(suf, suf + ct + 1);
			for (int i = 0, v, sz = 0; i < (int) e[p].size(); ++i) {
				v = e[p][i];
				if (v == ft) continue;
				++sz;
				Add(S[sz], mul(pre[sz - 1], suf[sz + 1])); 
				Add(f[p][t], mul(S[sz], f[v][t]));
				G[0] = mul(F[0], ss[v][t - 1]);
				G[1] = mul(F[1], ss[v][t - 1]);
				G[2] = mul(F[2], ss[v][t - 1]);
				Add(G[1], mul(F[0], f[v][t]));
				Add(G[2], mul(add(F[1], F[2]), f[v][t]));
				F[0] = G[0], F[1] = G[1], F[2] = G[2];
			}
			Add(f[p][t], F[0]);
			Add(f[p][t], F[1]);
			Add(f[p][t], F[2]);
			if (ct == 2) {
				f[p][t] = 0;
				Add(f[p][t], F[0]);
				Add(f[p][t], mul(F[1], t));
			}
			ss[p][t] = add(f[p][t], ss[p][t - 1]);
		}
		return;
	}
	for (int t = 1; t < n; ++t) { // ans[t]
		ans[t] = 1;
		for (int i = 0, v; i < (int) e[p].size(); ++i) {
			v = e[p][i];
			if (v == ft) continue;
			Mul(ans[t], ss[v][t]);
		}
		for (int s = 1; s < t; ++s) Dec(ans[t], mul(ans[s], C[t][s]));
	}
}
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	for (int tt = 1; tt; --tt) {
		n = read(), mod = read();
		for (int i = C[0][0] = 1; i <= n; ++i) for (int j = C[i][0] = 1; j <= i; ++j)
		C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
		for (int i = 1, u, v; i < n; ++i) {
			u = read(), v = read();
			e[u].pb(v), e[v].pb(u);
		}
		dfs(1, 0);
		for (int i = 1; i < n; ++i) cout << ans[i] << ' ';
	}
	return 0;
}