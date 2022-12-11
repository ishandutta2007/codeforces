

#include <bits/stdc++.h>
#define fi first
#define se second
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

template <typename T>
inline void Mx(T &x, T y) { if (x < y) x = y; }
template <typename T>
inline void Mn(T &x, T y) { if (x > y) x = y; }
#define ls p << 1
#define rs ls | 1
const int N = 100005;
vector<int> vec[N<<2], mn[N<<2], dp[N<<2];
int vis[N], ne[N<<1], to[N<<1], fr[N], h[N], tot, n, m, q;
inline void adde(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
void build(int p, int l, int r) {
	int mid = (l + r) >> 1;
	if (l != r) build(ls, l, mid), build(rs, mid + 1, r);
	dp[p].resize(r - l + 1);
	for (int i = l;i <= r; ++i) vis[i] = 0;
	for (int i = r;i >= l; --i) {
		Mx(dp[p][i - l], i), vis[i] = 1;
		if (fr[i] >= l) {
			int t = fr[i];
			while (!vis[t]) vis[t] = 1, dp[p][t - l] = dp[p][i - l], ++t;
		}
	}
	mn[p].resize(r - l + 1);
	for (int i = l;i <= r; ++i) {
		mn[p][i - l] = n + 1;
		if (i != l) mn[p][i - l] = mn[p][i - l - 1];
		for (int t = h[i]; t; t = ne[t]) 
			if (to[t] > r) Mn(mn[p][i - l], to[t]), vec[p].push_back(to[t]);
	}
	sort(vec[p].begin(), vec[p].end());
}

int Far;
void query(int p, int l, int r, int L, int R) {
	if (Far < l) return;
	if (L <= l && r <= R) {
		if (Far < r) {
			Far = dp[p][Far - l];
			if (mn[p][Far - l] <= R) Far = r;
		}
		if (Far >= r && vec[p].size()) {
			int t = upper_bound(vec[p].begin(), vec[p].end(), R) - vec[p].begin();
			if (t) --t;
			if (vec[p][t] <= R) Mx(Far, vec[p][t]);
		} 
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) query(ls, l, mid, L, R);
	if (R > mid) query(rs, mid + 1, r, L, R);
}

int main() {
	read(n), read(m);
	for (int i = 1, a, b;i <= m; ++i) 
		read(a), read(b), fr[b] = a, adde(a, b);
	build(1, 1, n), read(q);
	for (int i = 1, l, r;i <= q; ++i)
		read(l), read(r), Far = l, query(1, 1, n, l, r), write(Far);
	return 0;
}