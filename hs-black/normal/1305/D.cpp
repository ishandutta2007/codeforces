#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

const int N = 2005;
int h[N], ne[N<<1], to[N<<1], deg[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y, deg[x]++;
}

int vis[N], cnt;

void dfs(int x, int f) {
	if (x == f || vis[x]) return; vis[x] = 1, cnt--;
	for (int i = h[x]; i; i = ne[i]) dfs(to[i], f);
}

int n, m;
int main() {
	read(n); cnt = n;
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		add(x, y), add(y, x);
	}
	
	for (int i = 1;i <= n; i++) {
		int j = 1, k;
		while (j <= n) {
			if (!vis[j] && deg[j] == 1) break;
			j++;
		}
		k = j + 1;
		while (k <= n) {
			if (!vis[k] && deg[k] == 1) break;
			k++;
		}
		printf ("? %d %d\n", j, k); fflush(stdout);
		int w; read(w); dfs(j, w), dfs(k, w);
		if (w == j || w == k) deg[w]--;
		else deg[w] -= 2;
		if (cnt == 1) break;
	}
	
	int ans = 0;
	for (int i = 1;i <= n; i++) if (!vis[i]) ans = i;
	printf ("! %d\n", ans);
	fflush(stdout);
	return 0;
}
/*

6
1 4
4 2
5 3
6 3
2 3

3

4

4



*/