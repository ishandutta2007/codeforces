#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 10005;
int s[N], t[N], mn[N];
int f[N], dep[N], tot, n, m;
int h[N], ne[N<<1], to[N<<1];

inline void add(int x, int y) {
	ne[++tot] = h[x], to[tot] = y, h[x] = tot;
}

int ed[N];
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1, f[x] = fa;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		ed[y] = (i + 1) >> 1; dfs(y, x);
	}
}

int ans[N];
int main() {
	read(n);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y), add(y, x); ans[i] = 1;
	} dfs(1, 0);
	
	read(m);
	for (int i = 1;i <= m; i++) {
		read(s[i]), read(t[i]), read(mn[i]);
		int x = s[i], y = t[i];
		while (x != y) {
			if (dep[x] < dep[y]) swap(x, y);
			ans[ed[x]] = max(ans[ed[x]], mn[i]);
			x = f[x];
		}
	}
	
	for (int i = 1;i <= m; i++) {
		int x = s[i], y = t[i], flag = 0;
		while (x != y) {
			if (dep[x] < dep[y]) swap(x, y);
			if (ans[ed[x]] <= mn[i]) {
				flag = 1; break;
			}
			x = f[x];
		}
		if (!flag) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = 1;i < n; i++) write(ans[i]), putchar(' ');
	return 0;
}