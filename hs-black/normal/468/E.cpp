#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int P = 1e9 + 7;
const int N = 1105000;
const int K = 55;
ll fac[N];
int id[55], siz[55], ct[55], x[55], y[55], w[55], st[55], tp, n, k;
vector<pair<int, int> > vec[55];
int c[K], lim;
void dfs(void) {
	while (1) {
		int t = 0, mnct = 0;
		for (int i = 1;i <= k; ++i) if (!id[y[i]]) {
			int cnt = 0;
			for (int j = 1;j <= k; ++j) 
				if (!id[y[j]] && x[j] == x[i]) ++cnt;
			if (!t || mnct > cnt) mnct = cnt, t = i;
		}
		if (!t) return;
		for (int i = 1;i <= k; ++i)
			if (!id[y[i]] && x[i] == x[t]) id[y[i]] = ++tp;
	}
}

ll calc(void) {
	memset(id, 0, (k + 1) << 2), tp = 0;
	dfs(); int s = 1; ll res = 0;
	for (int i = 1;i <= k; ++i) ++siz[x[i]], ct[x[i]] = 0;
	for (int i = 1;i <= k; ++i) {
		for (int j = 1;j <= k; ++j) {
			if (id[y[j]] == i) {
				if (!ct[x[j]]++) s <<= 1;
				if (!--siz[x[j]]) s >>= 1;
			}
		}
		res += s * i;
	}
	return res;
}

ll f[55][(1 << 20) + 5]; int rev[(1 << 20) + 5];
void dfst(int x, int tx, int t, int ts) {
	if (1 << x >= lim) return rev[t] = ts, void();
	if (!siz[st[x]]) dfst(x + 1, tx, t, ts), dfst(x + 1, tx, t | (1 << x), ts);
	else dfst(x + 1, tx + 1, t, ts), dfst(x + 1, tx + 1, t | (1 << x), ts | (1 << tx));
}

void solve(void) {
	dfs(), f[0][0] = lim = 1;
	for (int i = 1;i <= k; ++i) vec[id[y[i]]].emplace_back(x[i], w[i]);
	for (int i = 1;i <= k; ++i) ++siz[x[i]], ct[x[i]] = 0;
	memset(id, -1, sizeof(id)), tp = 0;
	for (int i = 1;i <= k; ++i) {
		for (auto t: vec[i]) {
			int x = t.first;
			//printf ("%d -> %d\n", i, x);
			if (ct[x] + siz[x] > 1 && !ct[x]) id[x] = tp++, st[tp - 1] = x;
			++ct[x], --siz[x];
		}
		lim = 1 << tp;
		for (int j = i - 1;j >= 0; --j) 
			for (int s = 0;s < lim; ++s) {
				for (auto t: vec[i]) {
					int x = t.first, w = t.second, ts = ~id[x] ? s | 1 << id[x] : s;
					if (~id[x] && ts == s) continue;
					f[j + 1][ts] = (f[j + 1][ts] + f[j][s] * (w - 1)) % P;
				}
			}
		for (auto t: vec[i]) {
			int x = t.first;
			if (!siz[x] && siz[x] + ct[x] > 1) {
				for (int j = 1;j <= k; ++j)
					if (id[j] > id[x]) --id[j];
				id[x] = -1, --tp;
			}
		}
		dfst(0, 0, 0, 0);
		//for (int i = 0;1 << i < lim; ++i) printf ("%d", siz[st[i]] ? 1 : 0);
		//puts("");
		//for (int i = 0;i < lim; ++i) printf ("rev[%d] = %d\n", i, rev[i]);
		for (int j = 1;j <= k; ++j) 
			if (~id[j]) st[id[j]] = j;
		for (int j = i;j >= 0; --j)
			for (int s = 0;s < lim; ++s)
				if (rev[s] != s) f[j][rev[s]] = (f[j][rev[s]] + f[j][s]) % P, f[j][s] = 0;
	}
	//printf ("tp = %d\n", tp);
	ll ans = 0;
	for (int i = 0;i <= min(n, k); ++i)
		ans = (ans + f[i][0] * fac[n - i]) % P;
	write(ans);
}

void lisanhua(int *x) {
	int t = 0;
	for (int i = 1;i <= k; ++i) c[++t] = x[i];
	sort(c + 1, c + t + 1), t = unique(c + 1, c + t + 1) - c - 1;
	for (int i = 1;i <= k; ++i) x[i] = lower_bound(c + 1, c + t + 1, x[i]) - c;
}

int main() {
	read(n), read(k), fac[0] = 1;
	for (int i = 1;i <= n; ++i) fac[i] = fac[i-1] * i % P;
	for (int i = 1;i <= k; ++i) read(x[i]), read(y[i]), read(w[i]);
	lisanhua(x), lisanhua(y);
	ll cnt1 = calc();
	for (int i = 1;i <= k; ++i) swap(x[i], y[i]);
	ll cnt2 = calc();
	//write(min(cnt1, cnt2));
	if (cnt2 < cnt1) solve();
	else {
		for (int i = 1;i <= k; ++i) swap(x[i], y[i]);
		solve();
	}
	return 0;
}