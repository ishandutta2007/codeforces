#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read(void) {
	int x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}

const int N = 405000;
int h[N], ne[N<<1], to[N<<1];
int fr[N<<1], n, m, tot;

inline void add(int x,int y) {
	ne[++tot] = h[x], to[tot] = y;
	fr[tot] = x, h[x] = tot;
}

int st[N], low[N], dfn[N];
int res[N], top, num, cnt;

void tarjan(int x,int f) {
	bool flag = 0;
	low[x] = dfn[x] = ++cnt;
	st[++top] = x;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; 
		if (!dfn[y]) {
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
		else if (y != f || flag) 
			low[x] = min(low[x], dfn[y]);
		else flag = 1;
	}
	if (low[x] == dfn[x]) {
		num++; int tmp;
		while (tmp = st[top--]) {
			res[tmp] = num;
			if (tmp == x) break;
		}
	}
}

int block, dp[N], ru[N];
int vis[N], ans, len;
void dfs(int x,int f) {
	dp[x] = vis[x] = 1; int mx = 0, mmx = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == f) continue;
		dfs(y, x); 
		dp[x] = max(dp[x], dp[y] + 1);
		if (dp[y] > mx) mmx = mx, mx = dp[y];
		else if (dp[y] > mmx) mmx = dp[y];
	}
	len = max(len, mmx + mx + 1);
}

int main() {
	n = read(), m = read();
	for (int i = 1;i <= m; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	for (int i = 1;i <= n; i++) 
		if (!dfn[i]) tarjan(i, 0), block++;
	int tmp = tot; tot = 0;
	for (int i = 1;i <= num; i++) h[i] = 0;
	for (int i = 1;i <= tmp; i++) {
		if (res[fr[i]] == res[to[i]]) continue;
		int x = res[fr[i]], y = res[to[i]];
		add(x, y); ru[y]++;
	}
	for (int i = 1;i <= num; i++) if (ru[i] <= 1) ans++;
	for (int i = 1;i <= num; i++) {
		if (!vis[i]) {
			len = 0; 
			dfs(i, 0); len = max(len, dp[i]);
			if (len != 1) ans += len - 2;
		}
	}
	cout << n - ans + (block - 1) << endl;
	return 0;
}