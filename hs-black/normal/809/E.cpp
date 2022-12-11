#pragma GCC optimize(3, "inline")
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P = 1e9+7;
const int N = 400500;

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P; mi >>= 1;
	}
	return res;
}

int dep[N], f[N], Top[N], son[N], siz[N], a[N], n;
int dfn[N], h[N], ne[N<<1], to[N<<1], num, tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

void dfs1(int x, int fa) { 
	dep[x] = dep[f[x] = fa] + (siz[x] = 1), dfn[x] = ++num;
	for (int i = h[x]; i ; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x); siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

void dfs2(int x, int topf) {
	Top[x] = topf;
	if (!son[x]) return; dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i]) 
		if ((y = to[i]) != f[x] && y != son[x]) dfs2(y, y);
}

int lca(int x, int y) {
	while (Top[x] != Top[y]) {
		if (dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = f[Top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}


int prime[N], phi[N], mu[N], e[N], cnt;
void prework(void) {
	phi[1] = mu[1] = 1;
	for (int i = 2;i <= n; i++) {
		if (!e[i]) prime[++cnt] = e[i] = i, phi[i] = i - 1, mu[i] = -1;
		for (int j = 1;j <= cnt; j++) {
			int t = prime[j] * i;
			if (t > n) break; e[t] = prime[j];
			if (prime[j] == e[i]) {
				phi[t] = phi[i] * prime[j];
				break;
			}
			phi[t] = phi[i] * (prime[j] - 1);
			mu[t] = -mu[i];
		}
	}
}

ll g[N], G[N], res;
int tmp[N], p[N], st[N], top;

vector<int> v[N];
inline void add_e(int x, int y) { v[x].push_back(y); }

void insert(int x) {
	if (top == 1) return st[++top] = x, void();
	int Lca = lca(x, st[top]);
	if (Lca == st[top]) return st[++top] = x, void();
	while (top > 1 && dfn[st[top-1]] >= dfn[Lca]) 
		add_e(st[top-1], st[top]), top--;
	if (Lca != st[top]) add_e(Lca, st[top]), st[top] = Lca;
	st[++top] = x;
}

bool cmp(int x, int y) { return dfn[x] < dfn[y]; }

ll sum[N], ans;
void dp(int x, int k) {
	if (a[x] % k == 0) {
		ans = (ans + (ll)phi[a[x]] * phi[a[x]] * dep[x]) % P;
		sum[x] = phi[a[x]];
	}
	else sum[x] = 0;
	for (auto y: v[x]) {
		dp(y, k); (ans += 2 * sum[x] * sum[y] % P * dep[x]) %= P;
		(sum[x] += sum[y]) %= P;
	}
	v[x].clear();
}

int main() {
	read(n); prework();
	for (int i = 1;i <= n; i++) read(a[i]), p[a[i]] = i;
	for (int i = 1, x, y; i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs1(1, 0), dfs2(1, 1);
	
	for (int d = 1; d * 2 <= n ; d++) {
		st[top = 1] = 1, res = ans = 0;
		ll sum = 0, sphi = 0; 
		for (int j = d;j <= n; j += d)
			tmp[++res] = p[j], sum = (sum + (ll)phi[j] * dep[p[j]]) % P, sphi += phi[j];
		sort(tmp + 1, tmp + res + 1, cmp);
		if (tmp[1] != 1) insert(tmp[1]);
		for (int i = 2; i <= res; i++) insert(tmp[i]);
		while (top > 1) add_e(st[top-1], st[top]), top--;
		dp(1, d); g[d] = (2 * (sphi % P) * sum - 2 * ans) % P;
		if (g[d] < 0) g[d] += P;
//		printf ("%lld\n", g[d]);
	}
	
	for (int i = 1;i <= n; i++) {
		for (int j = i;j <= n; j += i)
			G[i] += g[j] * mu[j / i], G[i] = (G[i] + P) % P;
//		cout << mu[i] << endl;
	}
			
	ans = 0;
	for (int i = 1;i <= n; i++) ans = (ans + i * fpw(phi[i], P - 2) % P * G[i]) % P;
	ans = (ans + P) % P; 
	printf ("%lld\n", ans * fpw((ll)n * (n - 1) % P, P - 2) % P);
	return 0;
}