#include <algorithm>
#include <cstring>
#include <cstdio>
#include <random>
#include <ctime>
using namespace std;
typedef long long ll;
const int N = 524288 | 10, mod = 998244353, g = 3;
int rev[N], len, w[N], inv_w[N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
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
		inv_w[len - i] = w[i] = (ll) w[i - 1] * v % mod;
}
void NTT(int *a, const int *w) {
	for(int i = 1; i < len; i ++)
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		for(int j = 0, t = len / (i << 1); j < len; j += i << 1) {
			const int *wn = w;
			for(int k = j; k < j + i; k ++, wn += t) {
				int t1 = a[k], t2 = (ll) *wn * a[k + i] % mod;
				a[k] = (t1 + t2) % mod; a[k + i] = (t1 - t2) % mod;
			}
		}
	}
	if(w == inv_w)
		for(int i = 0, v = - (mod - 1) / len; i < len; i ++)
			a[i] = (ll) a[i] * v % mod;
}
int n, m, Map[30], a[N], b[N], c[N], sum[N], ans[N];
char s[N], t[N];
void multi(int *x, int *y) {
	fill(x + n, x + len, 0); fill(y + m, y + len, 0);
	NTT(x, w); NTT(y, w);
	for(int i = 0; i < len; i ++) x[i] = (ll) x[i] * y[i] % mod;
	NTT(x, inv_w);
}
int main() {
	mt19937 rnd(time(0));
	static int p[30];
	for(int x, i = 1; i <= 26; i ++) scanf("%d", &x), p[x] = i;
	for(int i = 1; i <= 26; i ++) Map[i] = (Map[i - 1] + rnd() % mod) % mod;
	scanf("%s%s", t, s); n = strlen(s); m = strlen(t);
	for(int i = 0; i < n; i ++) a[i] = Map[s[i] - 'a' + 1], b[i] = Map[p[s[i] - 'a' + 1]];
	for(int i = 0; i < m; i ++) c[i] = Map[t[i] - 'a' + 1];
	int x = 0;
	for(int i = 0; i < m; i ++) (x += qpow(c[i], 4)) %= mod;
	for(int i = 0; i < n - m + 1; i ++) ans[i] = x;

	for(int i = 0; i < n; i ++) {
		sum[i] = (ll) a[i] * b[i] % mod * a[i] % mod * b[i] % mod;
		if(i) (sum[i] += sum[i - 1]) %= mod;
	}
	for(int i = 0; i < n - m + 1; i ++) {
		(ans[i] += sum[i + m - 1]) %= mod;
		if(i) (ans[i] += mod - sum[i - 1]) %= mod;
	}
	static int ta[N], tb[N]; InitNTT(n + m);

	for(int i = 0; i < n; i ++) ta[i] = ((ll) a[i] * a[i] + (ll) b[i] * b[i]) % mod;
	for(int i = 0; i < m; i ++) tb[m - 1 - i] = (ll) c[i] * c[i] % mod;
	multi(ta, tb);
	for(int i = m - 1; i < n + m - 1; i ++) {
		(ans[i - m + 1] += ta[i]) %= mod;
	}

	for(int i = 0; i < n; i ++) ta[i] = (a[i] + b[i]) % mod;
	for(int i = 0; i < m; i ++) tb[m - 1 - i] = (ll) c[i] * c[i] % mod * c[i] % mod;
	multi(ta, tb);
	for(int i = m - 1; i < n + m - 1; i ++) {
		(ans[i - m + 1] += -2ll * ta[i] % mod) %= mod;
	}

	for(int i = 0; i < n; i ++) ta[i] = ((ll) a[i] * a[i] % mod * b[i] % mod + (ll) a[i] * b[i] % mod * b[i] % mod) % mod;
	for(int i = 0; i < m; i ++) tb[m - 1 - i] = c[i];
	multi(ta, tb);
	for(int i = m - 1; i < n + m - 1; i ++) {
		(ans[i - m + 1] += -2ll * ta[i] % mod) %= mod;
	}

	for(int i = 0; i < n; i ++) ta[i] = (ll) a[i] * b[i] % mod;
	for(int i = 0; i < m; i ++) tb[m - 1 - i] = (ll) c[i] * c[i] % mod;
	multi(ta, tb);
	for(int i = m - 1; i < n + m - 1; i ++) {
		(ans[i - m + 1] += 4ll * ta[i] % mod) %= mod;
	}

	for(int i = 0; i < n - m + 1; i ++) {
		// printf("%lld !\n", ans[i]);
		putchar(ans[i] == 0 ? '1' : '0');
	}
	return 0;
}