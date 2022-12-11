#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

const int N = 100050;
const int M = 1000500;
template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

int h[N], ne[M], to[M];
ll w[M], tot = 1;
inline void add(int x, int y, ll z) {
	ne[++tot] = h[x], h[x] = tot;
	w[tot] = z, to[tot] = y;
}

inline void add_e(int x, int y, ll z) {
	add(x, y, z); add(y, x, 0);
}

int s, t;
int dep[N], cur[N];
ll dfs(int x, ll lim) {
	if (!lim || x == t) return lim;
	ll res = 0, f;
	for (int i = cur[x]; i; i = ne[i]) {
		int y = to[i]; cur[x] = i;
		if (!w[i] || dep[y] != dep[x] + 1) continue;
		f = dfs(y, min(w[i], lim));
		w[i] -= f, w[i^1] += f;
		res += f, lim -= f;
		if (!lim) return res;
	}
	return res;
}

int cnt;
queue<int> q;
bool bfs(void) {
	for (int i = 1;i <= cnt; i++) dep[i] = 0;
	dep[s] = 1; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = h[x]; i ; i = ne[i]) {
			int y = to[i]; if (!w[i] || dep[y]) continue;
			dep[y] = dep[x] + 1; q.push(y);
		}
	}
	if (!dep[t]) return 0;
	for (int i = 1;i <= cnt; i++) cur[i] = h[i];
	return 1;
}

int n, m;

vector<int> v[100];
int a[100], b[100], c[100];

const ll INF = 10000000000;
const ll LIM = 1000000;

ll f(int i, ll x) {
	return x * (x * a[i] + b[i]) + c[i];
}

int l[N], r[N];
int main() {
	read(n), read(m); s = ++cnt, t = ++cnt;
	for (int i = 1;i <= n; i++) read(a[i]), read(b[i]), read(c[i]);
	for (int i = 1;i <= n; i++) {
		read(l[i]), read(r[i]);
		add_e(s, cnt+1, INF);
		for (int j = l[i];j <= r[i]; j++) {
			v[i].push_back(++cnt);
			add_e(cnt, cnt+1, LIM - f(i, j));
		}
		v[i].push_back(++cnt);
		add_e(cnt, t, INF); r[i]++;
	}
	for (int i = 1;i <= m; i++) {
		int u, vv, d;
		read(u), read(vv), read(d);
		for (int j = l[u];j <= r[u]; j++) {
			int k = j - d;
			if (k < l[vv] || k > r[vv]) continue;
			add_e(v[u][j-l[u]], v[vv][k-l[vv]], INF);
		}
	}
	ll ans = LIM * n;
	while (bfs()) ans -= dfs(s, INF);
	cout << ans << endl;
	return 0;
}