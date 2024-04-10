#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1000050;
int read(void) {
	int x = 0; bool f = 0;
	char c = getchar(); 
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return f ? -x : x;
}

int h[N], ne[N<<1];
int to[N<<1], tot;
inline void add(int x,int y) {
	ne[++tot] = h[x];
	h[x] = tot, to[tot] = y;
}

int son[N], dep[N], D[N];
void dfs1(int x,int fa) {
	dep[x] = dep[fa] + 1;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs1(y, x); D[x] = max(D[x], D[y] + 1);
		if (D[son[x]] <= D[y]) son[x] = y;
	}
}

int tmp[N], *dp[N], *id = tmp;
int ans[N], n;
void dfs(int x,int f) {
	dp[x][0] = 1;
	if (son[x]) {
		dp[son[x]] = dp[x] + 1;
		dfs(son[x], x);
		ans[x] = ans[son[x]] + 1;
	}
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == f || y == son[x]) continue;
		dp[y] = id; id += D[y] + 1; 
		dfs(y, x);
		for (int j = 0;j <= D[y]; j++) {
			dp[x][j + 1] += dp[y][j];
			if (dp[x][j + 1] > dp[x][ans[x]] || 
			   (dp[x][j + 1] == dp[x][ans[x]] && ans[x] > j + 1))
				ans[x] = j + 1;
		}
	}
	if (dp[x][ans[x]] == 1) ans[x] = 0;
}

int main() {
	n = read();
	for (int i = 1;i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs1(1, 0); dp[1] = id; id += D[1] + 1; 
	dfs(1, 0);
	for (int i = 1;i <= n; i++) printf ("%d\n", ans[i]);
	return 0;
}