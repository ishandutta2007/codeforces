#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar())
		if (c == '-') f = -1;
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	x *= f;
}

const int N = 200500;
int h[N], ne[N<<1], to[N<<1], w[N<<1],  tot = 1;
inline void adde(int x, int y, int z) {
	ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z;
}

inline void add(int x, int y, int z) {
	adde(x, y, z), adde(y, x, 0);
}

int dep[N], cur[N], cnt, s, t, m, n, g;

queue<int> q;
bool bfs(void) {
	memset(dep, 0, cnt *  4 + 200);
	q.push(s); dep[s] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = h[x]; i; i = ne[i]) {
			int y = to[i];
			if (dep[y] || !w[i]) continue;
			dep[y] = dep[x] + 1, q.push(y);
		}
	}
	if (!dep[t]) return 0;
	for (int i = 1;i <= cnt; i++) cur[i] = h[i];
	return 1;
}

int dfs(int x, int lim) {
	if (x == t || !lim) return lim;
	int res = 0, f;
	for (int &i = cur[x]; i; i = ne[i]) {
		int y = to[i]; if (!w[i] || dep[y] != dep[x] + 1) continue;
		f = dfs(y, min(lim, w[i]));
		res += f, lim -= f;
		w[i] -= f, w[i^1] += f;
		if (!lim) return res;
	}
	return res;
}

int a[N], v[N];
const int inf = 1e8;
int main() {
	read(n), read(m), read(g); cnt = n, s = ++cnt, t = ++cnt;
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1, x;i <= n; i++) {
		read(x);
		if (a[i]) add(s, i, x);
		else add(i, t, x);
	}
	ll ans = 0;
	for (int i = 1, v, w, k;i <= m; i++) {
		read(v), read(w), read(k);
		ans += w; int num = ++cnt;
		for (int j = 1, x;j <= k; j++) {
			read(x);
			v ? add(num, x, inf) : add(x, num, inf);
		}
		read(k); w += k * g;
		v ? add(s, num, w) : add(num, t, w);
	}
	while (bfs()) ans -= dfs(s, inf);
	cout << ans << endl;
	return 0;
}