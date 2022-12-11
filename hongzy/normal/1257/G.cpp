#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 4e5 + 10, M = 3e6 + 10;
const int mod = 998244353, g = 3;
int rev[N], len, w[N], inv_w[N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
		if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
void InitNTT(int n) {
	int k = 0;
	for(len = 1; len <= n; len <<= 1) k ++;
	for(int i = 1; i < len; i ++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	w[0] = inv_w[0] = 1;
	int v = qpow(g, (mod - 1) / len);
	for(int i = 1; i < len; i ++)
		inv_w[len - i] = w[i] = 1ll * w[i - 1] * v % mod;
}
void NTT(int *a, const int *w) {
	for(int i = 1; i < len; i ++)
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		for(int j = 0, t = len / (i << 1); j < len; j += i << 1) {
			const int *wn = w;
			for(int k = j; k < j + i; k ++, wn += t) {
				int t1 = a[k], t2 = 1ll * *wn * a[k + i] % mod;
				a[k] = (t1 + t2) % mod; a[k + i] = (t1 - t2 + mod) % mod;
			}
		}
	}
	if(w == inv_w) {
		int v = - (mod - 1) / len;
		v = (v + mod) % mod;
		for(int i = 0; i < len; i ++)
			a[i] = 1ll * a[i] * v % mod;
	}
}
vector<int> operator * (vector<int> a, vector<int> b) {
	static int f[N], g[N];
	int c = (int) a.size() + (int) b.size() - 2; InitNTT(c);
	for(int i = 0; i < len; i ++) f[i] = i < a.size() ? a[i] : 0;
	for(int i = 0; i < len; i ++) g[i] = i < b.size() ? b[i] : 0;
	NTT(f, w); NTT(g, w);
	for(int i = 0; i < len; i ++) f[i] = 1ll * f[i] * g[i] % mod;
	NTT(f, inv_w); a.resize(c + 1);
	for(int i = 0; i <= c; i ++) a[i] = ((f[i] + mod) % mod);
	return a;
}
vector<int> c;
vector<int> solve(int l, int r) {
	if(l == r) return vector<int>(c[l] + 1, 1);
	int m = (l + r) >> 1;
	return solve(l, m) * solve(m + 1, r);
}
int main() {
	static int n, m, cnt[M];
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x); cnt[x] ++; m = max(m, x);
	}
	for(int i = 1; i <= m; i ++) if(cnt[i]) {
		c.push_back(cnt[i]);
	}
	printf("%d\n", solve(0, (int) c.size() - 1)[n / 2]);
	return 0;
}