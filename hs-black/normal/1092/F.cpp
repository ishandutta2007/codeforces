#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int N = 200500;
template <typename T>
void read(T &x) {
	x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) x = -x;
}
vector<int> v[N];
ll val[N], n;
ll sum[N], x, y;
ll res[N], dp[N];

void dfs(int x, int fa) {
	sum[x] = val[x];
	for (int i = 0;i < v[x].size(); i++) {
		int y = v[x][i]; if (y == fa) continue;
		dfs(y, x); sum[x] += sum[y];
		res[x] += sum[y] + res[y];
	}
}

void dfs2(int x, int fa, ll rest) {
	for (int i = 0;i < v[x].size(); i++) {
		int y = v[x][i]; if (y == fa) continue;
		dp[y] = dp[x] + rest + sum[x] - 2 * sum[y];
		dfs2(y, x, rest + sum[x] - sum[y]);
	}
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(val[i]);
	for (int i = 1;i < n; i++) {
		read(x), read(y);
		v[x].push_back(y); v[y].push_back(x);
	}
	dfs(1, 0); dp[1] = res[1]; dfs2(1, 0, 0);
	ll ans = 0;
	for (int i = 1;i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}