#include <queue>
#include <vector>
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

const int N = 2e5+5;
int vis[N], t, T, n, m;
int l[N], r[N], col[N];

vector<int> v[N];

int wrong(void) { return puts("IMPOSSIBLE"), 0; }

void dfs(int x) {
	if (vis[x]) return; vis[x] = 1;
	for (auto y: v[x]) {
		if (!col[y]) col[y] = 3 - col[x];
		if (col[y] + col[x] != 3) exit(wrong());
		dfs(y);
	}
}

int main() {
	read(t), read(T), read(n), read(m);
	int n1 = 1e9, n2 = 0;
	for (int i = 1;i <= n; i++) 
		read(l[i]), read(r[i]), n1 = min(n1, r[i]), n2 = max(n2, l[i]);
	if (n1 + n2 < t) n2 = t - n1;
	if (n1 + n2 > T) n1 = T - n2;
	if (n1 < 0 || n2 < 0) return wrong();
	for (int i = 1;i <= n; i++) {
		int a = l[i] <= n1, b = n2 <= r[i];
		if (!a && !b) return wrong();
		if (!a && b) col[i] = 2;
		if (a && !b) col[i] = 1;
	}
	for (int i = 1;i <= m; i++) {
		int x, y; read(x), read(y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for (int i = 1;i <= n; i++)
		if (!vis[i] && col[i]) dfs(i);
	for (int i = 1;i <= n; i++)
		if (!col[i]) col[i] = 1, dfs(i);
	puts("POSSIBLE");
	printf ("%d %d\n", n1, n2);
	for (int i = 1;i <= n; i++) putchar(col[i] + '0');
	return 0;
}