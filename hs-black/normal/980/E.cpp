#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1050000;

int h[N], to[N<<1], ne[N<<1];
int dep[N], tot;

inline void add(int x,int y) {
	ne[++tot] = h[x], h[x] = tot;
	to[tot] = y;
}


int f[N][22], vis[N];
void dfs(int x) {
	dep[x] = dep[f[x][0]] + 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == f[x][0]) continue;
		f[y][0] = x;
		for (int i = 1;i <= 20; i++) 
			f[y][i] = f[f[y][i-1]][i-1];
		dfs(y);
	}
}
int k, n;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

int get_h(int x) {
	for (int i = 20;i >= 0; i--) 
		if (!vis[f[x][i]]) x = f[x][i];
	return x;
}

int main() {
	n = read(), k = n - read(); vis[0] = 1;
	for (int i = 1;i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs(n);
	for (int i = n;i >= 1; i--) {
		if (vis[i]) continue;
		int t = get_h(i), x = i;
		if (dep[i] - dep[t] + 1 > k) continue;
		while (!vis[x]) {
			vis[x] = 1; k--;
			x = f[x][0];
		}
	}
	for (int i = 1;i <= n; i++) 
		if (!vis[i]) printf ("%d ", i);
	return 0;
}