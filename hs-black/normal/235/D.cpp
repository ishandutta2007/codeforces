

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
	static short st[30], tp; 
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

const int N = 3005;
int ne[N<<1], to[N<<1], h[N], tot, n;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
int vis[N], To[N], rt;
double inv[N], ans;
vector<int> vec;

void dfs1(int x, int fa) {
	vis[x] = 1;
	for (int i = h[x], y; i; i = ne[i]) {
		if ((y = to[i]) == fa) continue;
		if (rt) break;
		To[x] = y;
		if (vis[y]) {
			memset(vis, 0, sizeof(vis)), rt = 0;
			vec.push_back(x), vis[x] = ++rt;
			for (int t = To[x]; t != x; t = To[t]) 
				vec.push_back(t), vis[t] = ++rt;
			break;
		}
		dfs1(y, x);
	}
}

void getans2(int x, int fa, int a, int b, int c) {
	ans += inv[a + b] + inv[a + c] - inv[a + b + c];
	for (int i = h[x]; i; i = ne[i])
		if (to[i] != fa && !vis[to[i]]) getans2(to[i], x, a + 1, b, c);
}

void getans1(int x, int fa, int dep) {
	ans += inv[dep];
	if (vis[x]) {
		for (int j = 1;j <= rt; ++j) if (vec[j - 1] != x) 
			getans2(vec[j - 1], 0, dep + 1, abs(j - vis[x]) - 1, rt - abs(j - vis[x]) - 1);
		for (int i = h[x], y; i; i = ne[i])
			if (!vis[y = to[i]] && y != fa) getans1(y, x, dep + 1);
		return ;
	}
	for (int i = h[x]; i; i = ne[i]) 
		if (to[i] != fa) getans1(to[i], x, dep + 1);
}

int main() {
	inv[0] = inv[1] = 1, read(n);
	for (int i = 1, x, y;i <= n; ++i) 
		read(x), read(y), ++x, ++y, add(x, y), add(y, x);
	for (int i = 2;i <= n; ++i) 
		inv[i] = (double)1. / i;
	dfs1(1, 0);
	for (int i = 1;i <= n; ++i) getans1(i, 0, 1);
    printf ("%.10lf\n", ans); 
	return 0;
}