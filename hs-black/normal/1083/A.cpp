#include <bits/stdc++.h>
#define ok printf ("ok on line#%d\n", __LINE__)
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c);  c = getchar())
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

const int N = 505050;
int ne[N<<1], to[N<<1], w[N<<1], h[N], tot;
int v[N], n; ll ans;
inline void add(int x, int y, int z) { ne[++tot] = h[x], to[h[x] = tot] = y, w[tot] = z; }
ll dfs(int x, int fa) {
	ll mx = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		ll val = dfs(y, x) - w[i];
		ans = max(ans, mx + v[x] + val);
		if (val > mx) mx = val;
	}
	ans = max(ans, mx += v[x]);
	return mx;
}

int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(v[i]);
	for (int i = 1, x, y, z;i < n; ++i)
		read(x), read(y), read(z), add(x, y, z), add(y, x, z);
	write(max(ans, dfs(1, 0)));
	return 0;
}